/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once
#include "Keyboard.h"
#include "Mouse.h"

#include "Vector.h"

#include <functional>

namespace NCL {
	class GameTimer;
	namespace Rendering {
		class RendererBase;
	};
	using namespace Rendering;

	enum class WindowEvent {
		Minimize,
		Maximize,
		Resize,
		Fullscreen,
		Windowed
	};

	using WindowEventHandler = std::function<void(WindowEvent e, uint32_t w, uint32_t h)>;
	
	class Window {
	public:
		static Window* CreateGameWindow(std::string title = "NCLGL!", int sizeX = 800, int sizeY = 600, bool fullScreen = false, int offsetX = 100, int offsetY = 100);

		static void DestroyGameWindow() {
			delete window;
			window = nullptr;
		}

		bool		IsMinimised() const { return minimised;	 }

		bool		UpdateWindow();

		bool		HasInitialised()	const { return init; }

		float		GetScreenAspect()	const {
			return (float)size.x / (float)size.y;
		}

		Vector2i		GetScreenSize()		const { return size; }
		Vector2i		GetScreenPosition()	const { return position; }

		const std::string&  GetTitle()   const { return windowTitle; }
		void				SetTitle(const std::string& title) {
			windowTitle = title;
			UpdateTitle();
		};

		virtual void	LockMouseToWindow(bool lock) {};
		virtual void	ShowOSPointer(bool show) {};

		virtual void	SetWindowPosition(int x, int y) {};
		virtual void	SetFullScreen(bool state) {};
		virtual void	SetConsolePosition(int x, int y) {};
		virtual void	ShowConsole(bool state) {};

		static const Keyboard*	 GetKeyboard() { return keyboard; }
		static const Mouse*		 GetMouse() { return mouse; }
		static const GameTimer&	 GetTimer() { return timer; }

		static Window*	const GetWindow() { return window; }

		void SetWindowEventHandler(WindowEventHandler& e) {
			eventHandler = e;
		}
	protected:
		Window();
		virtual ~Window();

		virtual void UpdateTitle() {}

		virtual bool InternalUpdate() = 0;

		WindowEventHandler eventHandler;

		bool				minimised;
		bool				init;
		Vector2i			position;
		Vector2i			size;
		Vector2i			defaultSize;

		std::string			windowTitle;

		static Window*		window;
		static Keyboard*	keyboard;
		static Mouse*		mouse;

		static GameTimer	timer;
	};
}
