#include "frame/opengl/file/load_program.h"

#include <frame/file/file_system.h>
#include <frame/opengl/program.h>

#include <filesystem>
#include <fstream>

namespace frame::opengl::file {

// TODO(anirul): Should be moved to the device.
std::unique_ptr<frame::ProgramInterface> LoadProgramFromName(const std::string& name) {
    std::string vertex_filepath   = std::string("asset/shader/opengl/" + name + ".vert");
    std::string fragment_filepath = std::string("asset/shader/opengl/" + name + ".frag");
    std::string geometry_filepath = std::string("asset/shader/opengl/" + name + ".geom");
    return LoadProgram(vertex_filepath, fragment_filepath, geometry_filepath);
}

std::unique_ptr<ProgramInterface> LoadProgramFromName(const std::string& vertex_name,
                                                      const std::string& fragment_name,
                                                      const std::string& geometry_name) {
    std::string vertex_filepath   = std::string("asset/shader/opengl/" + vertex_name + ".vert");
    std::string fragment_filepath = std::string("asset/shader/opengl/" + fragment_name + ".frag");
    std::string geometry_filepath = "";
    if (geometry_name != "") {
        geometry_filepath = std::string("asset/shader/opengl/" + geometry_name + ".geom");
    }
    return LoadProgram(vertex_filepath, fragment_filepath, geometry_filepath);
}

// TODO(anirul): Should be moved to the device.

std::unique_ptr<frame::ProgramInterface> LoadProgram(const std::string& vertex_filepath,
                                                     const std::string& fragment_filepath,
                                                     const std::string& geometry_filepath) {
    std::ifstream vertex_ifs{ frame::file::FindFile(std::filesystem::path(vertex_filepath)) };
    std::ifstream fragment_ifs{ frame::file::FindFile(std::filesystem::path(fragment_filepath)) };
    if (geometry_filepath != "") try {
            std::ifstream geometry_ifs{ frame::file::FindFile(
                std::filesystem::path(geometry_filepath)) };

            return CreateProgram(vertex_ifs, fragment_ifs, geometry_ifs);
        } catch (std::runtime_error) {
        }
    return CreateProgram(vertex_ifs, fragment_ifs);
}

}  // namespace frame::opengl::file
