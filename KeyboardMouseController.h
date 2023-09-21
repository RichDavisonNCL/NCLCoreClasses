/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#include "Controller.h"

namespace NCL {
	class Keyboard;
	class Mouse;

	class KeyboardMouseController : public Controller {
		const uint32_t LeftMouseButton	= 0;
		const uint32_t RightMouseButton = 0;

		const uint32_t XAxis = 0;
		const uint32_t ZAxis = 1;
		const uint32_t YAxis = 2;

	public:
		KeyboardMouseController(Keyboard* k, Mouse* m) {
			keyboard	= k;
			mouse		= m;
		}
		virtual ~KeyboardMouseController() {
		}

		float	GetAxis(uint32_t axis) const override;
		float	GetButtonAnalogue(uint32_t button) const override;
		bool	GetButton(uint32_t button) const override;

	protected:
		Keyboard*	keyboard;
		Mouse*		mouse;
	};
}