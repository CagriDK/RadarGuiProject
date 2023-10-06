#pragma once

#include "GuiPage.h"

class MainMenuPage : public GuiPage {
private:
    unsigned int m_Buffer;
    float m_Positions[6];
    bool m_ShouldClose = false; // Sayfanın kapanıp kapanmadığını kontrol etmek için bir bool değişken

public:
    void Init() override {
        m_Positions[0] = -0.5f; m_Positions[1] = -0.5f;
        m_Positions[2] = 0.0f;  m_Positions[3] = 0.5f;
        m_Positions[4] = 0.5f;  m_Positions[5] = -0.5f;

        glGenBuffers(1, &m_Buffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(m_Positions), m_Positions, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Update() override {
        // Her karede gerçekleştirilmesi gereken güncelleme işlemleri bu fonksiyon içinde yapılır.
        // Örneğin: animasyonları güncellemek, kullanıcı girdilerini işlemek vb.
    }

    void Render() override {
        std::cout<<"Job Started;";
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        if (ImGui::Begin("Main Menu")) {
            if (ImGui::Button("Start Game")) {
                // Oyunu başlatma kodları...
            }
            if (ImGui::Button("Settings")) {
                // Ayarlar sayfasını açma kodları...
            }
            if (ImGui::Button("Exit")) {
                // Oyunu kapatma kodları...
            }
            ImGui::End();
        }

        std::cout<<"Job finished;";
    }

    void Terminate() override {
        glDeleteBuffers(1, &m_Buffer);
    }

    bool ShouldClose() override {
        return m_ShouldClose;
    }
};
