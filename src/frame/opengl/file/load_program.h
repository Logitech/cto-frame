#pragma once

#include <memory>
#include <optional>

#include "frame/program_interface.h"

namespace frame::opengl::file {

/**
 * @brief Load from a name (something like "Blur").
 * @param name: Program name.
 * @return A unique pointer to a program interface or an error.
 */
std::unique_ptr<ProgramInterface> LoadProgramFromName(const std::string& name);

/**
 * @brief Load from names (to compose existing shaders).
 * @param vertex_name: vertex shader name.
 * @param fragment_name: fragment shader name.
 * @param geometry_name: geometry shader name. By default empty.
 * @return A unique pointer to a program interface or an error.
 */
std::unique_ptr<ProgramInterface> LoadProgramFromName(const std::string& vertex_name,
                                                      const std::string& fragment_name,
                                                      const std::string& geometry_name = "");
/**
 * @brief Load from 3 filepaths one for vertex, one for fragment and one for geometry.
 * @param vertex_filepath: Filepath towards vertex shader (full path should be provided).
 * @param fragment_filepath: Filepath towards fragment shader (full path should be provided).
 * @param geometry_filepath: Filepath towards geometry shader (full path should be provided).
 * @return A unique pointer to a program interface or an error.
 */
std::unique_ptr<ProgramInterface> LoadProgram(const std::string& vertex_filepath,
                                              const std::string& fragment_filepath,
                                              const std::string& geometry_filepath = "");

}  // namespace frame::opengl::file
