/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 6 2024
 *
 * sdl3window.cpp
 */

// Standard Includes
#include <system_error>

// Local includes
#include "ether2d/sdl3window.hpp"
#include "ether2d/logger.hpp"
#include "ether2d/sdl3errorcodes.hpp"

namespace ether2d::windows {

bool SDL3Window::SetResolution(uint16_t resx, uint16_t resy) {
	return SDL_SetWindowSize(m_window, resx, resy);
}

bool SDL3Window::EnableFullscreen() {
	return SDL_SetWindowFullscreen(m_window, true);
}

core::WindowEvent SDL3Window::PollEvents() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_EVENT_QUIT:
				logging::Logger::Get().Debug("Quit event received");
				return {core::WindowPollStates::QUIT};
			case SDL_EVENT_MOUSE_MOTION:
				logging::Logger::Get().Debug("Mouse motion event received");
				return {core::WindowPollStates::MOUSE_MOTION, {event.motion.x, event.motion.y}};
			default:
				break;
		}
	}

	return {core::WindowPollStates::CONTINUE};
}

SDL3Window::SDL3Window(const char *title, uint16_t resx, uint16_t resy, bool fullscreen) {
	m_width = resx;
	m_height = resy;

	m_window = SDL_CreateWindow(title, resx, resy, DEFAULT_WINDOW_FLAGS);
	if(m_window == nullptr) {
		const char *const error = SDL_GetError();
		std::error_code ec((int)SDL3ErrorCodes::CREATEWINDOW, std::generic_category());
		throw std::system_error(ec, error);
	}

	if(!SDL_SetWindowFullscreen(m_window, fullscreen)) {
		const char *const error = SDL_GetError();
		std::error_code ec((int)SDL3ErrorCodes::SETFULLSCREEN, std::generic_category());
		throw std::system_error(ec, error);
	}
}

SDL3Window::~SDL3Window() {
	if(m_window != nullptr) {
		SDL_DestroyWindow(m_window);
	}

	logging::Logger::Get().Debug("Window destroyed successfully");
}

SDL3WindowRet SDL3Window::Create(std::string &title, uint16_t resx, uint16_t resy, bool fullscreen) {
	SDL3Window *window = nullptr;

	logging::Logger::Get().Debug("Creating window");

	try {
		window = new SDL3Window(title.c_str(), resx, resy, fullscreen);
	} catch (const std::system_error &e) {
		logging::Logger::Get().Error(e.what());
		return {std::unique_ptr<SDL3Window>(nullptr), (SDL3ErrorCodes)e.code().value()};
	}

	logging::Logger::Get().Debug("Window created successfully");

	return {std::unique_ptr<SDL3Window>(window), SDL3ErrorCodes::NONE};
}

} // namespace ether2d::windows
