#pragma once

#include <memory>
#include <string>
#include "Frame/LevelInterface.h"
#include "Frame/StaticMeshInterface.h"

namespace frame::file {

	std::shared_ptr<StaticMeshInterface> LoadStaticMeshFromFileOpenGL(
		const std::shared_ptr<LevelInterface> level,
		const std::string& file);

} // End namespace frame::file.