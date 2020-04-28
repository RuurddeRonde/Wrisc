#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include<string>
#include "AppManager.h"
namespace UI
{
	class Booksettings : public UIWindow
	{
	public:
		Booksettings(std::string name) : name{ name }
		{
			
		}
		~Booksettings()
		{
		}
		virtual void update() override
		{
			if (showing)
			{
				if (ImGui::Begin(name.c_str(), &showing))
				{
					static char Booktitle[128];
					ImGui::Text(AppManager::getInstance().book.title.c_str());
					ImGui::Text("Book title:");
					ImGui::InputText("###bkttl", Booktitle, sizeof(Booktitle));
					if (ImGui::Button("Apply"))
					{
						if (Booktitle[0] != ' '&& Booktitle[0] != '\0')
						{
							AppManager::getInstance().book.title = Booktitle;
						}
					}
					static char author[128];
					ImGui::Text(AppManager::getInstance().book.author.c_str());
					ImGui::Text("Author:");
					ImGui::InputText("###author", author, sizeof(author));
					if (ImGui::Button("Apply"))
					{
						if (author[0] != ' '&& author[0] != '\0')
						{
							AppManager::getInstance().book.author = author;
						}
					}
					static char publisher[128];
					ImGui::Text(AppManager::getInstance().book.publisher.c_str());
					ImGui::Text("Publisher:");
					ImGui::InputText("###publisher", publisher, sizeof(publisher));
					if (ImGui::Button("Apply"))
					{
						if (publisher[0] != ' '&& publisher[0] != '\0')
						{
							AppManager::getInstance().book.publisher = publisher;
						}
					}
					ImGui::SameLine();
					if (ImGui::Button("Apply all"))
					{
						if (Booktitle[0] != ' ' && Booktitle[0] != '\0')
						{
							AppManager::getInstance().book.title = Booktitle;
						}
						if (author[0] != ' '&& author[0] != '\0')
						{
							AppManager::getInstance().book.author = author;
						}
						if (publisher[0] != ' '&& publisher[0] != '\0')
						{
							AppManager::getInstance().book.publisher = publisher;
						}
					}
					ImGui::Separator();

					if (ImGui::Button("Close"))
					{
						showing = false;
					}
				}
				ImGui::End();
			}
		}
	private:
		std::string name;
	};
}