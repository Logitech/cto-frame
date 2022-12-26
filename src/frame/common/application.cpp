#include "frame/common/application.h"

#include <glm/gtc/matrix_transform.hpp>

#include "frame/common/draw.h"

namespace frame::common {

Application::Application(std::unique_ptr<frame::WindowInterface>&& window)
    : window_(std::move(window)) {
    assert(window_);
}

void Application::Startup(std::filesystem::path path) {
    assert(window_);
    auto device = window_->GetUniqueDevice();
    assert(device);
    if (!plugin_name_.empty()) {
        device->RemovePluginByName(plugin_name_);
    }
    auto plugin  = std::make_unique<Draw>(window_->GetSize(), path, device);
    plugin_name_ = "ApplicationDraw";
    plugin->SetName(plugin_name_);
    device->AddPlugin(std::move(plugin));
}

void Application::Startup(std::unique_ptr<frame::LevelInterface>&& level) {
    assert(window_);
    auto device = window_->GetUniqueDevice();
    assert(device);
    if (!plugin_name_.empty()) {
        device->RemovePluginByName(plugin_name_);
    }
    auto plugin  = std::make_unique<Draw>(window_->GetSize(), std::move(level), device);
    plugin_name_ = "ApplicationDraw";
    plugin->SetName(plugin_name_);
    device->AddPlugin(std::move(plugin));
}

void Application::Resize(glm::uvec2 size, FullScreenEnum fullscreen_enum) {
    assert(window_);
    window_->Resize(size, fullscreen_enum);
}

void Application::Run() {
    assert(window_);
    window_->Run();
}

}  // End namespace frame::common.