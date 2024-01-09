# RadarGuiProject
Crate Radars and Manage the Data Packages.

## Prerequisites WINDOWS BUILD

### VSCode

Download VSCode to build this project.

https://code.visualstudio.com/download

Download VSCode CMake Tools Extension 

https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools

### Compiler 

This project is supported gcc versions: 

9.3, 10.1, 10.2, 10.3, 11.1, 11.2, 11.3, 12.1, 12.2, 12.2

Mainly tests are applied on 12.2.0 version

### CMAKE

Download CMake to build GLFW library

https://cmake.org/download/

(Windows x64 Installer) 

https://github.com/Kitware/CMake/releases/download/v3.28.1/cmake-3.28.1-windows-x86_64.msi

### GLFW

Download include/GLFW to implement the glfw contexs.

https://github.com/glfw/glfw

Open Terminal
  ```
  mkdir build
  cd build
  cmake -g "Unix Makefiles" ..
  make install
  ```
(STATIC library) 
glfw-master/build/src/libglfw3.a

### IMGUI

Download imgui.h and imgui.cpp files to implement dearImGui contexs.

https://github.com/ocornut/imgui

### OpenGL

Most of the Windows system will have a preloaded opengl32.dll which located in 

C:\WINDOWS\system32\opengl32.dll

In case it doesn't appears

https://www.dll-files.com/opengl32.dll.html

## Prerequisites LINUX BUILD

This is an example of how to list things you need to use the software and how to install them.
1. Ubuntu Software Install VSCode install
2. VSCode Extension CMake install
3. VSCode Extension CMake Tools install
4. Ubuntu Software Install after terminal commands 
   ```
   sudo apt-get update
   sudo apt-get install build-essential
   sudo apt-get install cmake
   sudo apt-get install libboost-all-dev
   sudo apt-get install code
   sudo apt-get install libglfw3-dev
   sudo apt-get install libgl1-mesa-dev
   sudo apt-get install mesa-utils
   ```
