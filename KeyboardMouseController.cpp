/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#include "KeyboardMouseController.h"
#include "Mouse.h"
#include "Keyboard.h"

using namespace NCL;
float	KeyboardMouseController::GetAxis(uint32_t axis) const {
	if (axis == XAxis) {
		if (keyboard->KeyPressed(NCL::KeyCodes::A)) {
			return -1.0f;
		}
		if (keyboard->KeyPressed(NCL::KeyCodes::D)) {
			return 1.0f;
		}
	}
	else if (axis == ZAxis) {
		if (keyboard->KeyPressed(NCL::KeyCodes::W)) {
			return 1.0f;
		}
		if (keyboard->KeyPressed(NCL::KeyCodes::S)) {
			return -1.0f;
		}
	}
	else if (axis == YAxis) {
		if (keyboard->KeyPressed(NCL::KeyCodes::LSHIFT)) {
			return -1.0f;
		}
		if (keyboard->KeyPressed(NCL::KeyCodes::SPACE)) {
			return 1.0f;
		}
	}

	return 0.0f;
}

float	KeyboardMouseController::GetButtonAnalogue(uint32_t button) const {
	return GetButton(button);
}

bool	KeyboardMouseController::GetButton(uint32_t button)  const {
	if (button == LeftMouseButton) {
		return mouse->ButtonDown(NCL::MouseButtons::Left);
	}
	if (button == RightMouseButton) {
		return mouse->ButtonDown(NCL::MouseButtons::Right);
	}
	return 0.0f;
}