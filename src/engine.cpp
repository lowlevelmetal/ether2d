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

namespace ether2d {

Engine& Engine::Get() {
	static Engine engine;
	return engine;
}

}
