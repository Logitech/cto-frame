#include "fill.h"

#include <fstream>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "frame/file/file_system.h"
#include "frame/json/parse_level.h"
#include "frame/opengl/material.h"
#include "frame/opengl/renderer.h"
#include "frame/opengl/static_mesh.h"
#include "frame/opengl/texture_cube_map.h"
#include "frame/proto/pixel.pb.h"

namespace frame::opengl {

namespace {

// Get the 6 view for the cube map.
const std::array<glm::mat4, 6> views_cubemap = {
    glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, -1.0f, 0.0f)),
    glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, -1.0f, 0.0f)),
    glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
                glm::vec3(0.0f, 0.0f, 1.0f)),
    glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),
                glm::vec3(0.0f, 0.0f, -1.0f)),
    glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),
                glm::vec3(0.0f, -1.0f, 0.0f)),
    glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f),
                glm::vec3(0.0f, -1.0f, 0.0f))
};
// Projection cube map.
const glm::mat4 projection_cubemap = glm::perspective(glm::radians(90.0f), 1.0f, 0.01f, 10.0f);

// Taken from cpp reference.
std::size_t ReplaceAll(std::string& inout, const std::string_view what,
                       const std::string_view with) {
    std::size_t count = 0;
    for (std::string::size_type pos = 0;
         inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length(), ++count) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
    return count;
}

std::string FillLevel(const std::string& initial, const std::map<std::string, std::string>& map) {
    std::string out = initial;
    for (auto [from, to] : map) {
        ReplaceAll(to, "\\", "/");
        ReplaceAll(out, from, to);
    }
    return out;
}

}  // namespace

std::unique_ptr<TextureInterface> FillIrradianceFromCubeMap(
    Level& level, std::unique_ptr<TextureInterface>&& cube_map, EntityId irradiance_id) {
    // Extract the already registered irradiance map to use it in the irradiance render level.
    auto irradiance = level.ExtractTexture(irradiance_id);

    auto original_irradiance_name = irradiance->GetName();
    auto original_cube_map_name   = cube_map->GetName();

    // Values to replace in the level json.
    auto cube_map_size                             = cube_map->GetSize();
    auto irradiance_size                           = irradiance->GetSize();
    std::map<std::string, std::string> filling_map = {
        { "<irradiance.x>", std::to_string(irradiance_size.x) },
        { "<irradiance.y>", std::to_string(irradiance_size.y) },
        { "<irradiance.pixel_element_size>",
          proto::PixelElementSize_Enum_Name(irradiance->GetPixelElementSize()) },
        { "<irradiance.pixel_structure>",
          proto::PixelStructure_Enum_Name(irradiance->GetPixelStructure()) }
    };

    // Now get it from external file.
    std::ifstream ifs(frame::file::FindFile("asset/json/irradiance.json").string());
    std::string inner_file_json((std::istreambuf_iterator<char>(ifs)), {});
    auto irradiance_level =
        frame::proto::ParseLevel(irradiance_size, FillLevel(inner_file_json, filling_map));
    if (!irradiance_level) {
        throw std::runtime_error(
            "Could not parse the irradiance_level from the json file in order to pre-compute the "
            "IBL.");
    }

    // Add the texture to the level.

    cube_map->SetName("CubeMap");
    auto new_cube_map_id = irradiance_level->AddTexture(std::move(cube_map));

    auto& material =
        irradiance_level->GetMaterialFromId(irradiance_level->GetIdFromName("IrradianceMaterial"));
    material.AddTextureId(new_cube_map_id, "Environment");

    Renderer renderer(*irradiance_level.get(), { 0, 0, irradiance_size.x, irradiance_size.y });
    auto& mesh_ref =
        irradiance_level->GetStaticMeshFromId(irradiance_level->GetDefaultStaticMeshCubeId());
    auto material_id = irradiance_level->GetIdFromName("IrradianceMaterial");
    if (!material_id) throw std::runtime_error("No material id found for [IrradianceMaterial].");
    MaterialInterface& material_ref = irradiance_level->GetMaterialFromId(material_id);

    renderer.FakeMesh(mesh_ref, material_ref, projection_cubemap, views_cubemap[0]);
    for (std::uint32_t i = 0; i < 6; ++i) {
        renderer.SetCubeMapTarget(GetTextureFrameFromPosition(i));
        renderer.RenderMesh(mesh_ref, material_ref, projection_cubemap, views_cubemap[i]);
    }

    // Put back the irradiance map in the original level.
    auto filled_irradiance =
        irradiance_level->ExtractTexture(irradiance_level->GetIdFromName("IrradianceMap"));
    filled_irradiance->SetName(original_irradiance_name);
    level.AddTexture(std::move(filled_irradiance));
    auto used_cube_map = irradiance_level->ExtractTexture(new_cube_map_id);
    used_cube_map->SetName(original_cube_map_name);
    return std::move(used_cube_map);
}

// THIS IS BROKEN
// In case this is needed you should fix it!

// namespace {
// // Get the 6 view for the cube map.
// const std::array<glm::mat4, 6> views_cubemap = {
//     glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
//             glm::vec3(0.0f, -1.0f, 0.0f)),
// glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f),
//             glm::vec3(0.0f, -1.0f, 0.0f)),
// glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
//             glm::vec3(0.0f, 0.0f, 1.0f)),
// glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),
//             glm::vec3(0.0f, 0.0f, -1.0f)),
// glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),
//             glm::vec3(0.0f, -1.0f, 0.0f)),
// glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f),
//             glm::vec3(0.0f, -1.0f, 0.0f))
// };
// }  // namespace

// void FillProgramMultiTexture(const std::shared_ptr<LevelInterface> level,
//                              const std::shared_ptr<ProgramInterface> program) {
//     FillProgramMultiTextureMipmap(level, program, 0,
//                                   [](const int, const std::shared_ptr<ProgramInterface>) {});
// }

// void FillProgramMultiTextureMipmap(
// 		const std::shared_ptr<LevelInterface> level,
// 		const std::shared_ptr<ProgramInterface> program,
// 		const int mipmap,
// 		const std::function<void(
// 			const int mipmap,
// 			const std::shared_ptr<ProgramInterface> program)> func /*=
// 		[](const int, const std::shared_ptr<sgl::ProgramInterface>) {}*/)
// 	{
//     assert(program->GetOutputTextureIds().size());
//     auto texture_out_ids = program->GetOutputTextureIds();
//     auto texture_ref     = level->GetTextureFromId(*texture_out_ids.cbegin());
//     auto size            = texture_ref->GetSize();
//     FrameBuffer frame{};
//     RenderBuffer render{};
//     ScopedBind scoped_frame(frame);
//     ScopedBind scoped_render(render);
//     render.CreateStorage(size);
//     frame.AttachRender(render);
//     frame.DrawBuffers(static_cast<std::uint32_t>(texture_out_ids.size()));
//     int max_mipmap = (mipmap <= 0) ? 1 : mipmap;
//     if (max_mipmap > 1) {
//         for (const auto& texture_id : texture_out_ids) {
//             auto texture         = level->GetTextureFromId(texture_id);
//             auto* opengl_texture = dynamic_cast<Texture*>(texture);
//             opengl_texture->Bind();
//             texture->EnableMipmap();
//         }
//     }
//     glm::mat4 projection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, 10.0f);
//     std::pair<uint32_t, uint32_t> temporary_size = size;
//     for (int mipmap_level = 0; mipmap_level < max_mipmap; ++mipmap_level) {
//         func(mipmap_level, program);
//         double fact           = std::pow(0.5, mipmap_level);
//         temporary_size.first  = static_cast<std::uint32_t>(size.first * fact);
//         temporary_size.second = static_cast<std::uint32_t>(size.second * fact);
//         glViewport(0, 0, temporary_size.first, temporary_size.second);
//         int i = 0;
//         for (const auto& texture_id : program->GetOutputTextureIds()) {
//             auto* opengl_texture = dynamic_cast<Texture*>(level->GetTextureFromId(texture_id));
//             frame.AttachTexture(opengl_texture->GetId(), FrameBuffer::GetFrameColorAttachment(i),
//                                 FrameTextureType::TEXTURE_2D, mipmap_level);
//             i++;
//         }
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//         Renderer renderer(level.get(), temporary_size);
//         renderer.SetProjection(projection);
//         auto maybe_id = level->GetDefaultStaticMeshQuadId();
//         if (!maybe_id) {
//             throw std::runtime_error("Invalid default static mesh quad id.");
//         }
//         renderer.RenderMesh(level->GetStaticMeshFromId(maybe_id.value()));
//     }
// }

// void FillProgramMultiTextureCubeMap(const std::shared_ptr<LevelInterface> level,
//                                     const std::shared_ptr<ProgramInterface> program) {
//     FillProgramMultiTextureCubeMapMipmap(level, program, 0,
//                                          [](const int, const std::shared_ptr<ProgramInterface>)
//                                          {});
// }

// void FillProgramMultiTextureCubeMapMipmap(
// 		const std::shared_ptr<LevelInterface> level,
// 		const std::shared_ptr<ProgramInterface> program,
// 		const int mipmap,
// 		const std::function<void(
// 			const int mipmap,
// 			const std::shared_ptr<ProgramInterface> program)> func /*=
// 		[](const int, const std::shared_ptr<sgl::ProgramInterface>) {}*/)
// 	{
//     assert(program->GetOutputTextureIds().size());
//     auto texture_out_ids = program->GetOutputTextureIds();
//     auto texture_ref     = level->GetTextureFromId(*texture_out_ids.cbegin());
//     auto size            = texture_ref->GetSize();
//     FrameBuffer frame{};
//     RenderBuffer render{};
//     ScopedBind scoped_frame(frame);
//     ScopedBind scoped_render(render);
//     frame.AttachRender(render);
//     frame.DrawBuffers(static_cast<std::uint32_t>(texture_out_ids.size()));
//     int max_mipmap = (mipmap <= 0) ? 1 : mipmap;
//     if (max_mipmap > 1) {
//         for (const auto& texture_id : texture_out_ids) {
//             auto texture         = level->GetTextureFromId(texture_id);
//             auto* opengl_texture = dynamic_cast<Texture*>(texture);
//             opengl_texture->Bind();
//             texture->EnableMipmap();
//         }
//     }
//     glm::mat4 projection = glm::perspective(glm::radians(90.0f), 1.0f, 0.1f, 10.0f);
//     std::pair<std::uint32_t, std::uint32_t> temporary_size = { 0, 0 };
//     for (int mipmap_level = 0; mipmap_level < max_mipmap; ++mipmap_level) {
//         func(mipmap_level, program);
//         double fact           = std::pow(0.5, mipmap_level);
//         temporary_size.first  = static_cast<std::uint32_t>(size.first * fact);
//         temporary_size.second = static_cast<std::uint32_t>(size.second * fact);
//         render.CreateStorage(temporary_size);
//         frame.AttachRender(render);
//         glViewport(0, 0, temporary_size.first, temporary_size.second);
//         int cubemap_element = 0;
//         for (const auto& view : views_cubemap) {
//             int i = 0;
//             for (const auto& texture_id : program->GetOutputTextureIds()) {
//                 auto* opengl_texture =
//                 dynamic_cast<Texture*>(level->GetTextureFromId(texture_id));
//                 frame.AttachTexture(opengl_texture->GetId(),
//                                     FrameBuffer::GetFrameColorAttachment(i),
//                                     FrameTextureType::TEXTURE_2D, mipmap_level);
//             }
//             cubemap_element++;
//             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//             Renderer renderer(level.get(), temporary_size);
//             renderer.SetProjection(projection);
//             renderer.SetView(view);
//             auto maybe_id = level->GetDefaultStaticMeshCubeId();
//             if (!maybe_id) {
//                 throw std::runtime_error("Invalid default static mesh cube id.");
//             }
//             renderer.RenderMesh(level->GetStaticMeshFromId(maybe_id.value()));
//         }
//     }
// }

}  // End namespace frame::opengl.
