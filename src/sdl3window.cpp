/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 6 2024
 *
 * sdl3window.cpp
 */

// Local includes
#include <ether2d/sdl3window.hpp>
#include <ether2d/logger.hpp>

namespace ether2d::windows {

bool SDL3Window::SetResolution(uint16_t resx, uint16_t resy) {
	return SDL_SetWindowSize(m_window, resx, resy);
}

bool SDL3Window::EnableFullscreen() {
	return SDL_SetWindowFullscreen(m_window, true);
}

SDL3Window::SDL3Window(const char *title, uint16_t resx, uint16_t resy, bool fullscreen) {
	m_width = resx;
	m_height = resy;

	m_window = SDL_CreateWindow(title, resx, resy, DEFAULT_WINDOW_FLAGS);
	if(m_window == nullptr) {
		const char *const error = SDL_GetError();
		logging::Logger::Get().Error(error);
		throw std::runtime_error(error);
	}

	// Don't throw error if fullscreen fails, this isnt fatal
	if(!SDL_SetWindowFullscreen(m_window, fullscreen)) {
		const char *const error = SDL_GetError();
		logging::Logger::Get().Error(error);
	}
}

std::unique_ptr<SDL3Window> SDL3Window::Create(std::string &title, uint16_t resx, uint16_t resy, bool fullscreen) const {
	SDL3Window *window = new SDL3Window(title.c_str(), resx, resy, fullscreen);
	return std::unique_ptr<SDL3Window>(window);
}

std::unique_ptr<SDL3Window> SDL3Window::Create(std::string &title, bool fullscreen) const {
	SDL3Window *window = new SDL3Window(title.c_str(), m_width, m_height, fullscreen);
	return std::unique_ptr<SDL3Window>(window);
}

} // namespace ether2d::windows
