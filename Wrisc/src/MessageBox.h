#pragma once
#include "UIWindow.h"
#include "imgui.h"

namespace UI
{
	class ImGuiMessageBox : public UIWindow
	{
	public:
		ImGuiMessageBox(std::string name) : name{ name }
		{
			Hide();
		}
		~ImGuiMessageBox()
		{
		}
		virtual void update() override
		{
			if (showing)
			{
				if (ImGui::Begin(name.c_str(), &showing))
				{
					ImGui::Text(text.c_str());
					if (ImGui::Button("OK"))
					{
						this->Hide();
					}
					ImGui::End();
				}
			}
		}
		void setText(std::string text)
		{
			this->text = text;
		}
	private:
		std::string name;
		std::string text;
	};
}