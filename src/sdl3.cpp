/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 3 2024
 *
 * sdl3.cpp
 */

// Local includes
#include "ether2d/sdl3.hpp"
#include "ether2d/logger.hpp"
#include "ether2d/sdl3errorcodes.hpp"

// Third party includes
extern "C" {
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_version.h>
}

// Standard includes
#include <system_error>

namespace ether2d::core {

bool SDL3::m_initialized = false;

SDL3::SDL3() {
	if(!m_initialized) {
		logging::Logger::Get().Info(SDL_GetRevision());

		if(!SDL_Init(initflags)) {
			const char *const error = SDL_GetError();
			std::error_code ec((int)SDL3ErrorCodes::INIT, std::generic_category());
			throw std::system_error(ec, error);
		}

		m_initialized = true;
	}
}

SDL3::~SDL3() noexcept {
	if(m_initialized)
		SDL_Quit();
}

} // namespace ether2d::core
