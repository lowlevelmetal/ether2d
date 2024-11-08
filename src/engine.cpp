/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 5 2024
 *
 * engine.cpp
 */

// Local includes
#include "ether2d/engine.hpp"
#include "ether2d/logger.hpp"

namespace ether2d {

// Ask the window if it has any events
core::WindowEvent Engine::PollEvent() {
	core::WindowEvent event = m_window->PollEvents();
	switch(event.state) {
		case core::WindowPollStates::MOUSE_MOTION:
			m_mouse_coords = event.mouse_coords;
			logging::Logger::Get().Debug("Mouse coordinates: x: {}, y: {}", m_mouse_coords.x, m_mouse_coords.y);
			break;
	}

	return event;
}

EngineRet Engine::Create(std::string title, uint16_t width, uint16_t height, bool fullscreen) {
	Engine *engine = nullptr;

	logging::Logger::Get().Debug("Creating engine");

	try {
		engine = new Engine(title, width, height, fullscreen);
	} catch(const std::runtime_error &e) {
		return {std::shared_ptr<Engine>(nullptr), false};
	}

	logging::Logger::Get().Debug("Engine created successfully");

	return {std::shared_ptr<Engine>(engine), true};
}

Engine::Engine(std::string &title, uint16_t width, uint16_t height, bool fullscreen) {
	auto [window, ec] = windows::SDL3Window::Create(title, width, height, fullscreen);
	if(ec != SDL3ErrorCodes::SETFULLSCREEN && ec != SDL3ErrorCodes::NONE) {
		throw std::runtime_error("Fatal error creating SDL3 window, check logs");
	}

	m_window = std::move(window);
}

}
