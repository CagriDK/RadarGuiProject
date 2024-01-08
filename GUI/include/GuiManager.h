#pragma once

#include <map>
#include "GuiPage.h"

class GuiManager {
private:
    std::map<std::string, GuiPage*> m_Pages;
    GuiPage* m_ActivePage;

public:
    GuiManager() : m_ActivePage(nullptr) {}

    void AddPage(GuiPage* page, const std::string& pageName) {
        m_Pages[pageName] = page;
    }

    void SetActivePage(const std::string& pageName) {
        m_ActivePage = m_Pages[pageName];
    }

    void UpdateActivePage() {
        if (m_ActivePage) {
            m_ActivePage->Update();
        }
    }

    void RenderActivePage() {
        if (m_ActivePage) {

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        m_ActivePage->Render();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            
        }
    }

    ~GuiManager() {
        for (auto& pair : m_Pages) {
            delete pair.second;
        }
    }
};
