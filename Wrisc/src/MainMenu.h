#pragma once
#include "UIWindow.h"
#include "imgui.h"
#include "TextEditor.h"
#include<string>

namespace UI
{
	class MainMenu : public UIWindow
	{
	public:
		MainMenu()
		{
		}
		~MainMenu()
		{
		}
		virtual void update() override
		{
            if (ImGui::BeginMainMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Save", "CTRL+S")) {}
                    if (ImGui::MenuItem("Open", "CTRL+O")) {}  // Disabled item
                    ImGui::Separator();
                    if (ImGui::MenuItem("New", "CTRL+N")) {}
                    if (ImGui::MenuItem("Export", "CTRL+E")) {}
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Edit"))
                {
                    if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
                    if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
                    ImGui::Separator();
                    if (ImGui::MenuItem("Cut", "CTRL+X")) {}
                    if (ImGui::MenuItem("Copy", "CTRL+C")) {}
                    if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
		}
	private:
	};
}