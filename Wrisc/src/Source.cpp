#include "WindowManager.h"
#include "textfieldWindow.h"
#include "MainMenu.h"
int main()
{
	UI::WindowManager ui;

	ui.AddWindow(std::unique_ptr<UI::TextFieldWindow>(new UI::TextFieldWindow("textView")));
	ui.AddWindow(std::unique_ptr<UI::MainMenu>(new UI::MainMenu()));
	while (true)
	{
		ui.Update();
		ui.Render();
	}
	return 0;
}