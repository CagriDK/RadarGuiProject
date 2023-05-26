#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLEW/glew.h> // Will drag system OpenGL headers
#include <GLFW/glfw3.h> // Will drag system OpenGL headers


static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**){

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        {return 1;}


    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Dear!!! ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (window == nullptr)
        return 1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    if(glewInit() != GLEW_OK)
    {
        std::cout<< "Error! " << std::endl;
    }

    std::cout<<glGetString(GL_VERSION) <<std::endl;

    float positions[6] = {
        -0.5f,-0.5f,
        0.0f, 0.5f,
        0.5f,-0.5f
    };

    unsigned int buffer;
    glGenBuffers(1,&buffer);
    glBindBuffer(GL_ARRAY_BUFFER,buffer);
    glBufferData(GL_ARRAY_BUFFER,sizeof(positions),positions,GL_STATIC_DRAW);


    while (!glfwWindowShouldClose(window))
    {
        glClear(!glfwWindowShouldClose(window));

        glDrawArrays(GL_TRIANGLES,0,3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
