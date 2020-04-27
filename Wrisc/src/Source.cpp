#include "WindowManager.h"
#include "textfieldWindow.h"
#include "MainMenu.h"
#include "BookLoader.h"
#include "AppManager.h"
#include "chapterListMenu.h"
int main()
{
	AppManager::getInstance().book = BookLoader::LoadBook("SavedData.book");
	UI::WindowManager ui;

	ui.AddWindow(std::unique_ptr<UI::TextFieldWindow>(new UI::TextFieldWindow("textView")));
	ui.AddWindow(std::unique_ptr<UI::MainMenu>(new UI::MainMenu()));
	ui.AddWindow(std::unique_ptr<UI::ChapterList>(new UI::ChapterList("chapters")));
	while (!ui.shouldClose())
	{
		ui.Update();
		ui.Render();
	}
	BookLoader::SaveBook(&AppManager::getInstance().book);
	return 0;
}