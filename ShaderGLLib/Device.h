#pragma once

#include <memory>
#include <map>
#include <array>
#include <functional>
#include <optional>
#include <SDL2/SDL.h>
#include "../ShaderGLLib/Program.h"
#include "../ShaderGLLib/Texture.h"
#include "../ShaderGLLib/Buffer.h"
#include "../ShaderGLLib/Effect.h"
#include "../ShaderGLLib/Mesh.h"
#include "../ShaderGLLib/Scene.h"
#include "../ShaderGLLib/Camera.h"
#include "../ShaderGLLib/Light.h"
#include "../ShaderGLLib/Material.h"
#include "../ShaderGLLib/Uniform.h"

namespace sgl {

	class Device : public UniformInterface
	{
	public:
		// This will initialize the GL context and make the GLEW init.
		Device(
			void* gl_context, 
			const std::pair<std::uint32_t, std::uint32_t> size);

	public:
		// Pile up effect to be called before Startup.
		void AddEffect(std::shared_ptr<Effect> effect);
		// Startup the scene. Throw errors in case there is any, takes fov in 
		// degrees.
		void Startup(const float fov = 65.0f);
		// Draw what is on the scene.
		// Take the total time from the beginning of the program to now as a
		// const double parameter.
		void Draw(
			const std::shared_ptr<ProgramInterface> program,
			const double dt);
		// Draw to the deferred texture set.
		void DrawDeferred(
			const std::shared_ptr<ProgramInterface> program,
			const std::vector<std::shared_ptr<Texture>>& out_textures,
			const double dt);
		// Draw the view texture set.
		void DrawView(
			const std::shared_ptr<ProgramInterface> program,
			const std::vector<std::shared_ptr<Texture>>& out_textures,
			const double dt);
		// Draw to multiple textures.
		void DrawMultiTextures(
			const std::shared_ptr<ProgramInterface> program,
			const std::vector<std::shared_ptr<Texture>>& out_textures,
			const double dt);
		// Add environment to the scene.
		void AddEnvironment(const std::string& environment_map);
		// Display a texture to the display.
		void Display(const std::shared_ptr<Texture> texture);
		// Load scene from an OBJ file.
		void LoadSceneFromObjFile(const std::string& obj_file);
		// Debug access to the internals of device.
		const std::shared_ptr<Texture>& GetDeferredTexture(const int i) const;
		const std::shared_ptr<Texture>& GetViewTexture(const int i) const;
		const std::shared_ptr<Texture>& GetLightingTexture(const int i) const;

	public:
		const Camera GetCamera() const final { return camera_; }
		void SetCamera(const Camera& camera) { camera_ = camera; }
		SceneTree GetSceneTree() const { return scene_tree_; }
		void SetSceneTree(const SceneTree& scene_tree) 
		{ 
			scene_tree_ = scene_tree;
		}
		const LightManager& GetLightManager() const { return light_manager_; }
		void SetLightManager(const LightManager& light_manager)
		{
			light_manager_ = light_manager;
		}
		const glm::mat4 GetProjection() const final { return perspective_; }
		const glm::mat4 GetView() const final { return view_; }
		const glm::mat4 GetModel() const final { return model_; }
		void* GetDeviceContext() const { return gl_context_; }
		const std::string GetType() const { return "OpenGL"; }

	protected:
		void SetupCamera();

	private:
		std::shared_ptr<Frame> frame_ = nullptr;
		std::shared_ptr<Render> render_ = nullptr;
		std::shared_ptr<ProgramInterface> pbr_program_ = nullptr;
		std::shared_ptr<ProgramInterface> view_program_ = nullptr;
		std::shared_ptr<Material> environment_material_ = nullptr;
		std::vector<std::shared_ptr<Texture>> deferred_textures_ = {};
		std::vector<std::shared_ptr<Texture>> lighting_textures_ = {};
		std::vector<std::shared_ptr<Texture>> view_textures_ = {};
		std::vector<std::shared_ptr<Effect>> effects_ = {};
		std::map<std::string, std::shared_ptr<Material>> materials_ = {};
		SceneTree scene_tree_ = {};
		LightManager light_manager_ = {};
		// Camera storage.
		Camera camera_ = Camera({ 0.1f, 5.f, -7.f }, { -0.1f, -1.f, 2.f });
		// PVM matrices.
		glm::mat4 perspective_ = glm::mat4(1.0f);
		glm::mat4 view_ = glm::mat4(1.0f);
		glm::mat4 model_ = glm::mat4(1.0f);
		// Field of view (in degrees).
		float fov_ = 65.f;
		// Open GL context.
		void* gl_context_ = nullptr;
		// Constants.
		const std::pair<std::uint32_t, std::uint32_t> size_ = { 0, 0 };
		const PixelElementSize pixel_element_size_ = PixelElementSize_HALF();
		// Error setup.
		const Error& error_ = Error::GetInstance();
	};

} // End namespace sgl.
