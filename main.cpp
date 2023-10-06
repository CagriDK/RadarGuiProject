#include <iostream>
#include "MainMenuPage.h"
#include "GuiManager.h"
#include <string>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**){

    MainMenuPage* mainMenuPage = new MainMenuPage();
    GuiManager guiManager;
    guiManager.AddPage(mainMenuPage,std::string{"MainPage"});
    guiManager.SetActivePage(std::string{"MainPage"});

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        {return 1;}

    GLFWwindow* window = glfwCreateWindow(640, 480, "Dear!!! ImGui GLFW+OpenGL3 example", nullptr, nullptr);

    if (window == nullptr)
        {return 1;}

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(glewInit()) << std::endl;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window) && !mainMenuPage->ShouldClose())
    {
        glClear(!glfwWindowShouldClose(window));

        glDrawArrays(GL_TRIANGLES,0,3);

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
    
}
