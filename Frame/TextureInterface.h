#pragma once

#include <any>
#include <cinttypes>
#include <utility>
#include <glm/glm.hpp>
#include "Frame/BindInterface.h"
#include "Frame/Proto/Proto.h"

namespace frame {

	// Interface to a texture.
	struct TextureInterface : public BindInterface 
	{
		// Texture filter rename.
		using TextureFilterEnum = frame::proto::Texture::TextureFilterEnum;
		using PixelElementSizeEnum = frame::proto::PixelElementSize::Enum;
		using PixelStructureEnum = frame::proto::PixelStructure::Enum;
		// Common interface.
		virtual PixelStructureEnum GetPixelStructure() const = 0;
		virtual PixelElementSizeEnum GetPixelElementSize() const = 0;
		virtual std::pair<std::uint32_t, std::uint32_t> GetSize() const = 0;
		virtual void EnableMipmap() const = 0;
		virtual void SetMinFilter(const TextureFilterEnum texture_filter) = 0;
		virtual TextureFilterEnum GetMinFilter() const = 0;
		virtual void SetMagFilter(const TextureFilterEnum texture_filter) = 0;
		virtual TextureFilterEnum GetMagFilter() const = 0;
		virtual void SetWrapS(const TextureFilterEnum texture_filter) = 0;
		virtual TextureFilterEnum GetWrapS() const = 0;
		virtual void SetWrapT(const TextureFilterEnum texture_filter) = 0;
		virtual TextureFilterEnum GetWrapT() const = 0;
		virtual void SetWrapR(const TextureFilterEnum texture_filter)
		{
			throw std::runtime_error("Not implemented!");
		}
		virtual TextureFilterEnum GetWrapR() const
		{
			throw std::runtime_error("Not implemented!");
		}
		virtual void Clear(const glm::vec4 color) = 0;
		virtual bool IsCubeMap() const = 0;
		virtual std::vector<std::any> GetTexture() const = 0;
		virtual std::vector<std::any> GetTexture(int i) const = 0;
	};

} // End namespace frame.
