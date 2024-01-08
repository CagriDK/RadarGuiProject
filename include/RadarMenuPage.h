#pragma once

#include "GuiPage.h"
#include "AppConfig.h"
#include "ClientApi.h"

class RadarMenuPage : public GuiPage
{
public:
    RadarMenuPage();
    ~RadarMenuPage();

    void Init() override;
    void Update() override;
    void Render() override;
    void Terminate() override;
    bool ShouldClose() override;

private:
    bool m_ShouldClose = false;
    uint16_t m_serverPort = 0;
    char windowTitle[256];
    std::vector<Config::UDPIPPort> m_udp_addres;
    ClientApi *clntApi = nullptr;
    std::thread *m_thread = nullptr;
};
