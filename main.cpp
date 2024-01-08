#include <iostream>
#include "RadarMenuPage.h"
#include "GuiManager.h"

int main(int, char**)
{
    RadarMenuPage* mainMenuPage = new RadarMenuPage();
    GuiManager guiManager;
    guiManager.AddPage(mainMenuPage,std::string{"Radar Control Interface"});
    mainMenuPage->Init();
    guiManager.SetActivePage(std::string{"Radar Control Interface"});

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        {return 1;}

    GLFWwindow* window = glfwCreateWindow(640, 480, "Radar Kontrol Arayuz", nullptr, nullptr);

    if (window == nullptr)
        {return 1;}

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);

    #ifdef _WIN32
    ImGui_ImplOpenGL3_Init("#version 330");
    #elif defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__)
    ImGui_ImplOpenGL3_Init("#version 140");
    #endif
    

    while (!glfwWindowShouldClose(window) && !mainMenuPage->ShouldClose())
    {
        glClear(!glfwWindowShouldClose(window));

        guiManager.RenderActivePage();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    delete mainMenuPage;

    return 0;
}
