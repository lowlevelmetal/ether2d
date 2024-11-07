/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 5 2024
 *
 * engine.hpp
 */

#pragma once

// Standard includes
#include <string>
#include <memory>

// Local includes
#include "sdl3.hpp"
#include "sdl3errorcodes.hpp"
#include "sdl3window.hpp"

namespace ether2d {

class Engine;
using EngineRet = std::pair<std::shared_ptr<Engine>, bool>;

class Engine : public core::SDL3 {
public:
	static EngineRet Create(std::string title, uint16_t width, uint16_t height, bool fullscreen = false);

	bool PollEvent();

private:
	Engine(std::string &title, uint16_t width, uint16_t height, bool fullscreen = false);

	std::shared_ptr<windows::SDL3Window> m_window;
};

} // namespace ether2d
