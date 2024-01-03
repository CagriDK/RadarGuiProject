cmake_minimum_required(VERSION 3.0.0)
project(RadarGuiProject VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_definitions(-DGLEW_STATIC)  # Add GLEW_STATIC preprocessor definition

# Create a list of source files
file(GLOB_RECURSE CPP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB_RECURSE IMGUI_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/src/imGui/*.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/Dependencies/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/Dependencies/include/imGui)

add_executable(RadarGuiProject main.cpp ${CPP_SOURCES} ${IMGUI_SOURCES})

# Add the path to the GLFW library
#libglfw3.a OpenGL libs
#opengl32.dll Windows System 
#glew32s.lib GLEW build and get from GLEW  
target_link_libraries(RadarGuiProject PRIVATE 
${CMAKE_CURRENT_LIST_DIR}/Dependencies/lib/libglfw3.a  
${CMAKE_CURRENT_LIST_DIR}/Dependencies/lib/opengl32.dll
${CMAKE_CURRENT_LIST_DIR}/Dependencies/lib/glew32s.lib 
${CMAKE_CURRENT_LIST_DIR}/Dependencies/lib/glew32s.lib 
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
