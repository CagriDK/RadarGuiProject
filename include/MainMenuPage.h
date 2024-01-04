#pragma once

#include "GuiPage.h"
#include "AppConfig.h"

class MainMenuPage : public GuiPage
{

private:
    unsigned int m_Buffer;
    float m_Positions[6];
    bool m_ShouldClose = false; // Sayfanın kapanıp kapanmadığını kontrol etmek için bir bool değişken
    uint16_t m_serverPort = 0;
    std::vector<Config::UDPIPPort> m_udp_addres;

public:
    void Init() override
    {
        Config &config = Config::getInstance();
        m_serverPort = config.getServerPort();
        std::copy(config.getUDPRadarIPPort().begin(), config.getUDPRadarIPPort().end(), m_udp_addres.begin());
    }

    void Update() override
    {
        // Her karede gerçekleştirilmesi gereken güncelleme işlemleri bu fonksiyon içinde yapılır.
        // Örneğin: animasyonları güncellemek, kullanıcı girdilerini işlemek vb.
    }

    void Render() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        if (ImGui::Begin("Main Menu", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize))
        {
            if (ImGui::Button("Start Game"))
            {
                std::cout << "Game is starting...\n";
                std::cout << "Server port: " << m_serverPort << "\n";

                // Oyunu başlatma kodları...
            }
            if (ImGui::Button("Settings"))
            {
                std::cout << "Settings page opening...\n";
                // Ayarlar sayfasını açma kodları...
            }
            if (ImGui::Button("Exit"))
            {
                std::cout << "Program closing...\n";
                std::exit(-1);
            }
            ImGui::End();
        }
    }

    void Terminate() override
    {
        glDeleteBuffers(1, &m_Buffer);
    }

    bool ShouldClose() override
    {
        return m_ShouldClose;
    }
};
