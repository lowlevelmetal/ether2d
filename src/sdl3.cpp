/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 3 2024
 *
 * sdl3.cpp
 */

// Local includes
#include "sdl3.hpp"
#include "logger.hpp"

namespace ether2d::core {

bool SDL3::m_initialized = false;

SDL3::SDL3() {
	if(!m_initialized) {
		if(!SDL_Init(initflags)) {
			logging::Logger::Get().Error("Failed to initialize SDL3");
		}

		m_initialized = true;
	}
}

SDL3::~SDL3() {

}

} // namespace ether2d::core
