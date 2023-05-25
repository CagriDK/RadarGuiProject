cmake_minimum_required(VERSION 3.0.0)
project(RadarGuiProject VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Create a list of source files
file(GLOB_RECURSE CPP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB_RECURSE IMGUI_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/imGui/*.cpp)

add_executable(RadarGuiProject main.cpp ${CPP_SOURCES} ${IMGUI_SOURCES})

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include/imGui)

# Add the path to the GLFW library
target_link_libraries(RadarGuiProject PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/libglfw3.a ${CMAKE_CURRENT_LIST_DIR}/lib/opengl32.dll)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
