#pragma once

#include <functional>
#include <map>
#include <memory>

#include "frame/level.h"

namespace frame::opengl {

/**
 * @brief Renders the irradiance map from a cube map.
 *
 * @param cube_map: The cube map to be used.
 * @param irradiance_id: The irradiance id of the map to fill.
 * @return The cube map.
 */
std::unique_ptr<TextureInterface> FillIrradianceFromCubeMap(
    Level& level, std::unique_ptr<TextureInterface>&& cube_map, EntityId irradiance_id);

// THIS IS BROKEN
// In case this is needed you should fix it!

// // Fill multiple textures from a program.
// //		- level					: structure that contain textures.
// //		- program				: program to be used.
// //		- unform_interface		: interface to update the uniforms.
// void FillProgramMultiTexture(const std::shared_ptr<LevelInterface> level,
//                              const std::shared_ptr<ProgramInterface> program);

// // Fill multiple textures from a program.
// //		- level					: structure that contain textures.
// //		- program				: program to be used.
// //		- unform_interface		: interface to update the uniforms.
// //		- mipmap				: level of mipmap (0 == 1).
// //		- func					: a lambda that will be call per mipmap.
// void FillProgramMultiTextureMipmap(
//     const std::shared_ptr<LevelInterface> level, const std::shared_ptr<ProgramInterface> program,
//     const int mipmap,
//     const std::function<void(const int mipmap, const std::shared_ptr<ProgramInterface> program)>
//         func = [](const int, const std::shared_ptr<ProgramInterface>) {});

// // Fill multiple cube map texture from a program.
// //		- level					: structure that contain textures.
// //		- program				: program to be used.
// //		- unform_interface		: interface to update the uniforms.
// void FillProgramMultiTextureCubeMap(const std::shared_ptr<LevelInterface> level,
//                                     const std::shared_ptr<ProgramInterface> program);

// // Fill multiple cube map texture from a program.
// //		- level					: structure that contain textures.
// //		- program				: program to be used.
// //		- unform_interface		: interface to update the uniforms.
// //		- mipmap				: level of mipmap (0 == 1).
// //		- func					: a lambda that will be call per mipmap.
// void FillProgramMultiTextureCubeMapMipmap(
//     const std::shared_ptr<LevelInterface> level, const std::shared_ptr<ProgramInterface> program,
//     const int mipmap,
//     const std::function<void(const int mipmap, const std::shared_ptr<ProgramInterface> program)>
//         func = [](const int, const std::shared_ptr<ProgramInterface>) {});

}  // End namespace frame::opengl.
