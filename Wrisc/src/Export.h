#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include<string>
struct exportSettings
{
	bool centerTitle;
	bool centerSubtitle;
	bool NewChapterNewPage;
};
namespace UI
{
	class ExportsettingsWindow : public UIWindow
	{
	public:
		ExportsettingsWindow(std::string name) : name{ name }
		{
		}
		~ExportsettingsWindow()
		{
		}
		virtual void update() override
		{
			if (showing)
			{
				if (ImGui::Begin(name.c_str(), &showing))
				{
					ImGui::Text("Export settings");
					ImGui::Separator();
					ImGui::Text("Center title:");
					ImGui::SameLine();
					ImGui::Checkbox("###1", &settings.centerTitle);


					ImGui::Text("Center subtitle:");
					ImGui::SameLine();
					ImGui::Checkbox("###2", &settings.centerSubtitle);

					ImGui::Text("Start chapter on new page:");
					ImGui::SameLine();
					ImGui::Checkbox("###3", &settings.NewChapterNewPage);

					ImGui::Combo("###Output", &filetype, "PDF\0Plain text\0Word document\0");

				}
				ImGui::End();
			}
		}
	private:
		std::string name;
		exportSettings settings; 
		int filetype = 0;
	};
}