#pragma once
#include "UIWindow.h"
#include <vector>
#include "Window.h"

namespace UI
{
	class WindowManager
	{
	public:
		WindowManager();
		~WindowManager();
		void Update();
		void Render();
		void AddWindow(std::unique_ptr<UIWindow> newWindow);
		bool shouldClose() { return mainWindow.WindowShouldClose(); }
	private:
		std::vector<std::unique_ptr<UIWindow>> windows;
		Window mainWindow;

		void setstyle();
		void showDockSpace(bool* p_open);
	};
}


