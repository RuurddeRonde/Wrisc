#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include "TextEditor.h"
#include "AppManager.h"
#include<string>
namespace UI
{
#define MEM_SIZE_16MB   ( 16 * 1024 * 1024 )

	
	class TextFieldWindow : public UIWindow
	{
	public:
		TextFieldWindow(std::string name): name {name}
		{
			t.SetText(AppManager::getInstance().book.chapters[AppManager::getInstance().book.chapterindex].text.c_str());
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
					
					t.Render("chapter");
				}
				ImGui::End();

			}
		}
	private:
		std::string name;
		TextEditor t;
	};
}