/**
 * ether2d - asteroids
 *
 * Matthew Todd Geiger
 * Nov 5 2024
 *
 * asteroids.cpp
 */

// Standard includes
#include <cstdlib>

// Engine includes
#include "ether2d/engine.hpp"

int main(int argc, char **argv) {
	auto [engine, ec] = ether2d::Engine::Create("Asteroids", 800, 600, false);

	while(engine->PollEvent()) {
		// Game loop
	}

	return EXIT_SUCCESS; 
}
