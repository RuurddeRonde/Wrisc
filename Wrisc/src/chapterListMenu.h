#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include "AppManager.h"
#include<string>
namespace UI
{


	class ChapterList : public UIWindow
	{
	public:
		ChapterList(std::string name) : name{ name }
		{
			popupshow = false;
		}
		~ChapterList()
		{
		}
		virtual void update() override
		{
			if (showing)
			{
				
				if (ImGui::Begin(name.c_str(), NULL, ImGuiWindowFlags_NoCollapse))
				{
					for (auto i = 0; i < AppManager::getInstance().book.chapters.size(); i++)
					{
						if (ImGui::TreeNode((void*)(intptr_t)i, AppManager::getInstance().book.chapters[i].h1.c_str()))
						{
							//ImGui::SameLine();
							if (ImGui::Button("Edit text"))
							{
								AppManager::getInstance().book.chapterindex = i;
							}
							if (ImGui::Button("Edit titels"))
							{
								popupshow = true;
								popupeditID = i;
							}

							ImGui::TreePop();
						}
					}
					if (popupshow)
					{
						showPopUp(popupeditID);
					}

					ImGui::Spacing();
					if (ImGui::Button("Add new Chapter"))
					{
						AppManager::getInstance().book.newChapter();
					}
				}
				ImGui::End();
			}
		}
	private:
		std::string name;
		bool popupshow;
		int popupeditID;
		void showPopUp(int chapterID)
		{
			//ImGui::SetNextWindowPos(ImVec2((ImGui::GetWindowWidth() / 2), ImGui::GetWindowHeight() / 2));
			if (ImGui::Begin("Edit chapter", &showing))
			{
				ImGui::Text(AppManager::getInstance().book.chapters[chapterID].h1.c_str());
				ImGui::Text(AppManager::getInstance().book.chapters[chapterID].h2.c_str());
				ImGui::Spacing();
				ImGui::Spacing();

				static char titleBuf[128];
				ImGui::Text("Set new title:");
				//ImGui::SameLine();
				ImGui::InputText("###h1", titleBuf, sizeof(titleBuf));
				if (ImGui::Button("Apply"))
				{
					if (titleBuf[0] != ' '&& titleBuf[0] != '\0')
					{
						AppManager::getInstance().book.chapters[chapterID].h1 = titleBuf;
					}
				}
				ImGui::Spacing();

				static char undertitleBuf[128];
				ImGui::Text(AppManager::getInstance().book.chapters[chapterID].h2.c_str());
				ImGui::Text("Set new Subtitle:");
				//ImGui::SameLine();
				ImGui::InputText("###h2", undertitleBuf, sizeof(undertitleBuf));
				if (ImGui::Button("Apply"))
				{
					if (undertitleBuf[0] != ' '&& undertitleBuf[0] != '\0')
					{
						AppManager::getInstance().book.chapters[chapterID].h1 = undertitleBuf;
					}
				}
				if (ImGui::Button("Close"))
				{
					popupshow = false;
				}


				ImGui::End();
			}
		}
	};
}