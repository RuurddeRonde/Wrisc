#include "UIWindow.h"


namespace UI
{
	void UIWindow::Show()
	{
		showing = true;
	}
	void UIWindow::Hide()
	{
		showing = false;
	}
	std::string UIWindow::GetName()
	{
		return name;
	}
}
