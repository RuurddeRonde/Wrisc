#include "WindowManager.h"
#include "textfieldWindow.h"
#include "MainMenu.h"
#include "BookLoader.h"
int main()
{
	BookLoader::SaveBook(new Book());

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