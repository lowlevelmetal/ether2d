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
#include "sdl3.hpp"
#include "windowtemplate.hpp"
#include "sdl3errorcodes.hpp"

// 3rd Party Includes
extern "C" {
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_events.h>
}

namespace ether2d::windows {

class SDL3Window;

using SDL3WindowRet = std::pair<std::unique_ptr<SDL3Window>, const SDL3ErrorCodes>;

// Use this class to create a window using SDL3
class SDL3Window : public core::SDL3, core::WindowTemplate {
public:
	~SDL3Window();

	// Factory Functions
	static SDL3WindowRet Create(std::string &title, uint16_t resx, uint16_t resy, bool fullscreen = false);

	bool EnableFullscreen() override;
	bool SetResolution(uint16_t resx, uint16_t resy) override;
	core::WindowEvent PollEvents() override;

	static const SDL_WindowFlags DEFAULT_WINDOW_FLAGS = SDL_WINDOW_OPENGL;

private:
	SDL3Window(const char *title, uint16_t resx, uint16_t resy, bool fullscreen);
	SDL3Window() = delete;

	int m_width, m_height;
	SDL_Window *m_window = nullptr;

	static const int DEFAULT_WIDTH = 640;
	static const int DEFAULT_HEIGHT = 480;

};

} // namespace ether2d::core
