#pragma once

#include "GuiPage.h"
#include "AppConfig.h"
#include "ClientApi.h"

class MainMenuPage : public GuiPage
{

private:
    unsigned int m_Buffer;
    bool m_ShouldClose = false; // Sayfanın kapanıp kapanmadığını kontrol etmek için bir bool değişken
    uint16_t m_serverPort = 0;
    char windowTitle[256];
    std::vector<Config::UDPIPPort> m_udp_addres;
    ClientApi *clntApi = nullptr;
    std::thread *m_thread = nullptr;

public:
    void Init() override
    {
        Config &config = Config::getInstance();
        m_serverPort = config.getServerPort();
        int i = 0;
        for (auto idx : config.getUDPRadarIPPort())
        {
            Config::UDPIPPort temp;
            memcpy(&temp, &idx, sizeof(Config::UDPIPPort));
            m_udp_addres.push_back(temp);
        }

        clntApi = new ClientApi("127.0.0.1", 55000);
        m_thread = new std::thread([this]() {
            while (true)
            {
                if (clntApi->getConnectionStatus())
                {
                    std::cout << "Connected to server"
                              << "\n";
                    break;
                }
                else
                {
                    std::cout << "Waiting for connection"
                              << "\n";
                    clntApi->ConnectServer();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        });
    }

    void Update() override
    {
        // Her karede gerçekleştirilmesi gereken güncelleme işlemleri bu fonksiyon içinde yapılır.
        // Örneğin: animasyonları güncellemek, kullanıcı girdilerini işlemek vb.
    }

    void Render() override
    {
        glClear(GL_COLOR_BUFFER_BIT);

        if (ImGui::Begin("Radar Central Panel", NULL, ImGuiWindowFlags_MenuBar  | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove )) 
        {
            if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("Options"))
                {
                    if (ImGui::MenuItem("Minimize", "Ctrl+M"))
                    {
#ifdef _WIN32
                        HWND hwnd = GetForegroundWindow();
                        if (hwnd != NULL)
                        {
                            ShowWindow(hwnd, SW_MINIMIZE);
                        }
#elif defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__)

#endif
                    }
                    if (ImGui::MenuItem("Exit", "Ctrl+Backspace"))
                    {
                        exit(0);
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            for (size_t i = 0; i < m_udp_addres.size(); ++i)
            {
                // Her bir radar için benzersiz bir ID ittir
                ImGui::PushID(i);

                // Her radar için ayrı bir başlık oluştur
                sprintf(windowTitle, "Radar #%zu", i);

                if (ImGui::CollapsingHeader(windowTitle))
                {
                    // Her bir radar için bir grup kutusu oluştur
                    ImGui::BeginGroup();
                    ImGui::Text("IP: %s", m_udp_addres[i].ip.c_str());
                    ImGui::Text("Port: %d", m_udp_addres[i].port);
                    ImGui::Checkbox("TrackPlot", &m_udp_addres[i].trackPlot);
                    ImGui::Checkbox("RadarPlot", &m_udp_addres[i].radarPlot);
                    // ImGui::InputInt("Integer Input", &m_udp_addres[i].multiInstance);
                    ImGui::Text("MultiInstance:");

                    float fullWidth = ImGui::GetContentRegionAvail().x;
                    ImGui::SetNextItemWidth(fullWidth);
                    ImGui::DragInt("##MultiInstance", &m_udp_addres[i].multiInstance, 0.01f, 1, 100);

                    ImVec2 buttonSize = ImVec2(fullWidth, 0);
                    if (ImGui::Button("Send", buttonSize))
                    {
                        json jData;
                        clntApi->sendJsonMessage(jData,"RadarMessage");
                    }
                    ImGui::EndGroup();

                    // Grup kutuları arasında boşluk bırak
                    ImGui::Spacing();
                }
                // Benzersiz ID'yi geri al
                ImGui::PopID();
            }
        }
        ImGui::End();
    }

    void Terminate() override
    {
        glDeleteBuffers(1, &m_Buffer);
        m_thread->join();
    }

    bool ShouldClose() override
    {
        return m_ShouldClose;
    }
};
