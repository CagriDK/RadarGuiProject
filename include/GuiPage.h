#pragma once

#include "imgui.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLEW/glew.h> // Will drag system OpenGL headers
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

class GuiPage {
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Terminate() = 0;
    virtual bool ShouldClose() = 0;
};