#include "Error.h"

#include <stdexcept>
#include <GL/glew.h>
#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#endif

namespace sgl {

	std::shared_ptr<Error> Error::instance_ = nullptr;
	void* Error::window_ptr_ = nullptr;

	std::string Error::GetLastError() const
	{
		switch (glGetError())
		{
		case GL_INVALID_ENUM:
			return "Invalid enum";
		case GL_INVALID_VALUE:
			return "Invalid value";
		case GL_INVALID_OPERATION:
			return "Invalid operation";
		case GL_INVALID_FRAMEBUFFER_OPERATION:
		{
			switch (glCheckFramebufferStatus(GL_FRAMEBUFFER))
			{
			case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
				return "Frame buffer incomplete attachment";
			case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT:
				return "Frame buffer incomplete dimensions";
			case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
				return "Frame buffer incomplete missing attachment";
			case GL_FRAMEBUFFER_UNSUPPORTED:
				return "Frame buffer unsupported";
			case GL_FRAMEBUFFER_COMPLETE:
				return "";
			}
		}
		case GL_OUT_OF_MEMORY:
			return "Out of memory";
		case GL_NO_ERROR:
			return "";
		}
		return "";
	}

	void Error::Display(
		const std::string& file /*= ""*/,
		const int line /*= -1*/) const
	{
		std::string error = GetLastError();
		if (error.empty()) return;
		if (line != -1) error = std::to_string(line) + ":" + error;
		if (!file.empty()) error = file + ":" + error;
		if (window_ptr_)
		{
#if defined(_WIN32) || defined(_WIN64)
			MessageBox(
				(HWND)window_ptr_, 
				error.c_str(), 
				"sgl::Error", 
				MB_ICONEXCLAMATION);
#endif
		}
		throw std::runtime_error(error);
	}

	void Error::DisplayShader(
		unsigned int shader, 
		const std::string& file /*= ""*/, 
		const int line /*= -1*/) const
	{
		const int max_length = 256;
		char info_log[max_length] = "";
		int length = 0;
		glGetShaderInfoLog(shader, max_length, &length, info_log);
		std::string error = GetLastError();
		if (error.empty()) return;
		if (line != -1) error = std::to_string(line) + ":" + error;
		if (!file.empty()) error = file + ":" + error;
		if (length)	error = error + "\n" + info_log;
		if (window_ptr_)
		{
#if defined(_WIN32) || defined(_WIN64)
			MessageBox(
				(HWND)window_ptr_,
				error.c_str(),
				"sgl::Error",
				MB_ICONEXCLAMATION);
#endif
		}
		throw std::runtime_error(error);
	}

	std::shared_ptr<sgl::Error> Error::GetInstance()
	{
		if (!instance_)
		{
			instance_ = std::make_shared<Error>();
		}
		return instance_;
	}

} // End namespace sgl.