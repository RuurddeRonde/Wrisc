#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include "TextEditor.h"
#include "AppManager.h"
#include<string>
namespace UI
{
	
	class TextFieldWindow : public UIWindow
	{
	public:
		TextFieldWindow(std::string name): name {name}
		{
			t.SetText(AppManager::getInstance().book.chapters[AppManager::getInstance().book.chapterindex].text.c_str());
			previndex = AppManager::getInstance().book.chapterindex;
		}
		~TextFieldWindow()
		{
		}
		virtual void update() override
		{
			if (showing)
			{
				if (ImGui::Begin(name.c_str(), &showing))
				{
					if (AppManager::getInstance().book.chapterindex != previndex)
					{
						t.SetText(AppManager::getInstance().book.chapters[AppManager::getInstance().book.chapterindex].text.c_str());
						previndex = AppManager::getInstance().book.chapterindex;
					}
					t.Render("chapter");
					if (t.IsTextChanged())
					{
						AppManager::getInstance().book.chapters[AppManager::getInstance().book.chapterindex].text = t.GetText();
					}
				}
				ImGui::End();

			}
		}
	private:
		std::string name;
		TextEditor t;
		int previndex;
	};
}