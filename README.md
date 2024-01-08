# RadarGuiProject
Crate Radars and Manage the Data Packages.

### WINDOWS BUILD

# CMAKE
https://cmake.org/download/
Download CMake to build GLFW library
(Windows x64 Installer) https://github.com/Kitware/CMake/releases/download/v3.28.1/cmake-3.28.1-windows-x86_64.msi

# GLFW
https://github.com/glfw/glfw
Download include/GLFW to implement the glfw contexs.

Open Terminal
mkdir build
cd build
cmake -g "Unix Makefiles" ..
make install
(STATIC library) glfw-master/build/src/libglfw3.a

# IMGUI
https://github.com/ocornut/imgui
Download imgui.h and imgui.cpp files to implement dearImGui contexs.

# OpenGL
Most of the Windows system will have a preloaded opengl32.dll which located in 
C:\WINDOWS\system32\opengl32.dll
In case it doesn't appears
https://www.dll-files.com/opengl32.dll.html

### LINUX BUILD

sudo apt-get install cmake
sudo apt-get install libglfw3-dev
sudo apt-get install libgl1-mesa-dev
sudo apt-get install mesa-utils
