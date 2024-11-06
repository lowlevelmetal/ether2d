/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 3 2024
 *
 * sdl3.hpp
 */

// For documentation on how this works
// https://wiki.libsdl.org/SDL3/README/main-functions

#pragma once

// Third party includes
extern "C" {
#include <SDL3/SDL_init.h>
}

/*
 * Anything that requires SDL3 can use this class
 */

namespace ether2d::core {

class SDL3 {
public:
	SDL3();
	~SDL3() noexcept;

	static const SDL_InitFlags initflags = SDL_INIT_AUDIO | SDL_INIT_VIDEO;

private:
	static bool m_initialized;
};

} // namespace ether2d::core
