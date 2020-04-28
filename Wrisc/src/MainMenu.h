#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include<string>
#include "BookLoader.h"
#include "AppManager.h"
#include "bookSettings.h"
#include "Export.h"

namespace UI
{
	class MainMenu : public UIWindow
	{
	public:
		MainMenu():booksettingswindow{"Book settings"}, exportwindow{"Export"}
		{
			booksettingswindow.Hide();
			exportwindow.Hide();
		}
		~MainMenu()
		{
		}
		virtual void update() override
		{
			booksettingswindow.update();
			exportwindow.update();
            if (ImGui::BeginMainMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Save", "CTRL+S")) 
                    {
                        BookLoader::SaveBook(&AppManager::getInstance().book);
                    }
                    if (ImGui::MenuItem("Open", "CTRL+O")) {}  
                    ImGui::Separator();
                    if (ImGui::MenuItem("New", "CTRL+N")) 
					{
						BookLoader::SaveBook(&AppManager::getInstance().book);
						AppManager::getInstance().book = Book();
					}
                    ImGui::EndMenu();
                }
				if (ImGui::BeginMenu("Book"))
				{
					if (ImGui::MenuItem("settings"))
					{
						booksettingswindow.Show();
					}
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Export"))
				{
					if (ImGui::MenuItem("settings"))
					{
						exportwindow.Show();
					}
					ImGui::EndMenu();
				}
               
                ImGui::EndMainMenuBar();
            }
		}
	private:
		Booksettings booksettingswindow;
		ExportsettingsWindow exportwindow;
	};
}