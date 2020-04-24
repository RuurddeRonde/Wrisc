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
		}
		~ChapterList()
		{
		}
		virtual void update() override
		{
			if (showing)
			{
				if (ImGui::Begin(name.c_str(), &showing))
				{
					for (auto i = 0; i < AppManager::getInstance().book.chapters.size(); i++)
					{
						//if (ImGui::TreeNode("%s###%u", AppManager::getInstance().book.chapters[i].h1.c_str(), i))
						if (ImGui::TreeNode((void*)(intptr_t)i, AppManager::getInstance().book.chapters[i].h1.c_str()))
						{
							ImGui::SameLine();
							if (ImGui::Button("Edit"))
							{
								AppManager::getInstance().book.chapterindex = i;
							}
							static char titleBuf[128];
							ImGui::Text("Set new title:");
							//ImGui::SameLine();
							ImGui::InputText("###1", titleBuf, sizeof(titleBuf));
							if (ImGui::Button("Apply"))
							{
								if (titleBuf[0] != ' ')
								{
									AppManager::getInstance().book.chapters[i].h1 = titleBuf;
								}
							}
							static char undertitleBuf[128];
							ImGui::Text(AppManager::getInstance().book.chapters[i].h2.c_str());
							ImGui::Text("Set new Subtitle:");
							//ImGui::SameLine();
							ImGui::InputText("###2", undertitleBuf, sizeof(undertitleBuf));
							if (ImGui::Button("Apply"))
							{
								if (undertitleBuf[0] != ' ')
								{
									AppManager::getInstance().book.chapters[i].h1 = undertitleBuf;
								}
							}
							if (ImGui::Button("Edit"))
							{
								AppManager::getInstance().book.chapterindex = i;
							}
							ImGui::TreePop();
						}
						else
						{
							ImGui::SameLine();
							if (ImGui::Button("Edit"))
							{
								AppManager::getInstance().book.chapterindex = i;
							}
						}
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
	};
}