/**
 * ether2d
 *
 * Matthew Todd Geiger
 * Nov 6 2024
 *
 * windowtemplate.hpp
 */

#pragma once

// Standard includes
#include <cstdint>

namespace ether2d::core {

enum class WindowPollStates {
	CONTINUE,
	QUIT,
	MOUSE_MOTION
};

typedef struct MouseCoordinates {
	float x, y;
} MouseCoordinates;

typedef struct WindowEvent {
	WindowPollStates state;
	union {
		MouseCoordinates mouse_coords;
	};
} WindowEvent;

// Any window classes are required to inherit this template
class WindowTemplate {
public:
	WindowTemplate() = default;
	~WindowTemplate() = default;

	virtual bool EnableFullscreen() = 0;
	virtual bool SetResolution(uint16_t resx, uint16_t resy) = 0;
	virtual WindowEvent PollEvents() = 0;

};

} // namespace ether2d::core
