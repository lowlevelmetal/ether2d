/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 5 2024
 *
 * engine.hpp
 */

#pragma once

// Local includes
#include "sdl3.hpp"

namespace ether2d {

class Engine : public core::SDL3 {
public:
	static Engine& Get();

private:
	Engine() = default;
};

} // namespace ether2d
