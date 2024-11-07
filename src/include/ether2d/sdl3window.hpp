/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 6 2024
 *
 * sdl3window.hpp
 */

#pragma once

// Standard includes
#include <memory>
#include <string>

// Local includes
#include <ether2d/sdl3.hpp>
#include <ether2d/windowtemplate.hpp>

// 3rd Party Includes
extern "C" {
#include <SDL3/SDL_video.h>
}

namespace ether2d::windows {

// Use this class to create a window using SDL3
class SDL3Window : public core::SDL3, core::WindowTemplate {
public:
	~SDL3Window();

	// Factory Functions
	std::unique_ptr<SDL3Window> Create(std::string &title, uint16_t resx, uint16_t resy, bool fullscreen = false) const;
	std::unique_ptr<SDL3Window> Create(std::string &title, bool fullscreen = false) const;

	bool EnableFullscreen() override;
	bool SetResolution(uint16_t resx, uint16_t resy) override;

	static const SDL_WindowFlags DEFAULT_WINDOW_FLAGS = SDL_WINDOW_OPENGL;

private:
	SDL3Window(const char *title, uint16_t resx, uint16_t resy, bool fullscreen);

	int m_width = 640, m_height = 480;
	SDL_Window *m_window = nullptr;

};

} // namespace ether2d::core
