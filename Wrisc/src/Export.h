#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include <string>
#include "AppManager.h"
#include <iostream>
#include <fstream>
#include "MessageBox.h"
#include "src/duckx.hpp"
struct exportSettings
{
	bool centerTitle;
	bool centerSubtitle;
	bool NewChapterNewPage;
};

class BookExporter
{
public:
	static bool exportBook(Book b, exportSettings settings, int fileType)
	{
		bool succes = false;;
		switch (fileType)
		{
		case 0:
			succes = exportPDF(b, settings);
			break;
		case 1:
			succes = exportTXT(b, settings);
			break;
		case 2:
			succes = exportDOCX(b, settings);

			break;
		default:
			succes = false;//invalid type
			break;
		}
		return succes;
	}
private:
	static bool exportPDF(Book b, exportSettings settings)
	{
		return false;
	}
	static bool exportTXT(Book b, exportSettings settings)
	{
		std::ofstream myfile(b.title + ".txt");
		if (myfile.is_open())
		{
			myfile << b.title << "\n";
			myfile << b.author << "\n";
			myfile << b.publisher << "\n\n\n\n";

			for (auto i = 0; i < b.chapters.size(); i++)
			{
				myfile << b.chapters[i].h1 << "\n";
				myfile << b.chapters[i].h2 << "\n";
				myfile << b.chapters[i].text << "\n\n";
			}

			myfile.close();
		}
		else return false;

		return true;
	}
	static bool exportDOCX(Book b, exportSettings settings)
	{
	//	std::ofstream myfile(b.title + ".docx");
	//	myfile.close();
		duckx::Document doc("test.docx");
		doc.open();
		doc.paragraphs().add_run(b.title + "\n" + b.author + "\n" + b.publisher);
		//duckx::Paragraph p = doc.paragraphs().insert_paragraph_after(b.title + "\n" + b.author + "\n" + b.publisher);

		for (auto i = 0; i < b.chapters.size(); i++)
		{
			duckx::Paragraph p = doc.paragraphs().insert_paragraph_after(b.chapters[i].h1);
			p.add_run(b.chapters[i].h2);
			p.add_run(b.chapters[i].text);
		}
		doc.save();
		return true;
	}

};

namespace UI
{
	class ExportsettingsWindow : public UIWindow
	{
	public:
		ExportsettingsWindow(std::string name) : name{ name }, mb{ "Alert" }
		{
			filetype = 0;
		}
		~ExportsettingsWindow()
		{
		}
		virtual void update() override
		{
			mb.update();
			if (showing)
			{
				if (ImGui::Begin(name.c_str(), &showing))
				{
					ImGui::Text("Export settings");
					ImGui::Separator();

					ImGui::Text("Please note formatting is not supported for txt file export.");

					ImGui::Text("Center title:");
					ImGui::SameLine();
					ImGui::Checkbox("###1", &settings.centerTitle);


					ImGui::Text("Center subtitle:");
					ImGui::SameLine();
					ImGui::Checkbox("###2", &settings.centerSubtitle);

					ImGui::Text("Start chapter on new page:");
					ImGui::SameLine();
					ImGui::Checkbox("###3", &settings.NewChapterNewPage);

					//ImGui::Combo("###Output", &filetype, "PDF\0Plain text\0Word document\0");

					if (ImGui::Button("Export"))
					{
						if (!BookExporter::exportBook(AppManager::getInstance().book, settings, 1))
						{
							//fail box
							mb.setText("Exporting failed!");
							mb.Show();
						}
						else
						{
							//succes
							mb.setText("Exporting succeded!");
							mb.Show();
						}
					}

				}
				ImGui::End();
			}
		}
	private:
		std::string name;
		exportSettings settings;
		int filetype;
		ImGuiMessageBox mb;
	};
}