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

bool Engine::PollEvent() {
	return m_window->PollEvents();
}

EngineRet Engine::Create(std::string title, uint16_t width, uint16_t height, bool fullscreen) {
	Engine *engine = nullptr;

	logging::Logger::Get().Info("Creating engine");

	try {
		engine = new Engine(title, width, height, fullscreen);
	} catch(const std::runtime_error &e) {
		return std::make_pair(std::shared_ptr<Engine>(nullptr), false);
	}

	logging::Logger::Get().Info("Engine created successfully");

	return std::make_pair(std::shared_ptr<Engine>(engine), true);
}

Engine::Engine(std::string &title, uint16_t width, uint16_t height, bool fullscreen) {
	auto [window, ec] = windows::SDL3Window::Create(title, width, height, fullscreen);
	if(ec != SDL3ErrorCodes::SETFULLSCREEN && ec != SDL3ErrorCodes::NONE) {
		throw std::runtime_error("Fatal error creating SDL3 window, check logs");
	}

	m_window = std::move(window);
}

}
