cmake_minimum_required(VERSION 3.0.0)
project(RadarGuiProject VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Create a list of source files
file(GLOB_RECURSE CPP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE CPP_GUI_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/GUI/src/*.cpp)
file(GLOB_RECURSE IMGUI_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/src/imGui/*.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/GUI/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/Dependencies/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/Dependencies/include/imGui)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
set(Boost_USE_STATIC_LIBS ON)


add_executable(RadarGuiProject main.cpp ${CPP_SOURCES} ${IMGUI_SOURCES} ${CPP_GUI_SOURCES})

# Add the path to the GLFW library
#libglfw3.a OpenGL libs
#opengl32.dll Windows System 
if(WIN32)
target_link_libraries(RadarGuiProject PRIVATE  
${CMAKE_CURRENT_LIST_DIR}/Dependencies/lib/libglfw3.a
${CMAKE_CURRENT_LIST_DIR}/Dependencies/lib/opengl32.dll
${Boost_LIBRARIES}
Ws2_32
)
endif()
if(UNIX)
    target_link_libraries(RadarGuiProject PRIVATE  
    ${Boost_LIBRARIES}
    pthread
    dl
    )

    find_package(glfw3 REQUIRED)
    if(glfw3_FOUND)
        target_link_libraries(RadarGuiProject PRIVATE glfw)
    endif()

    find_package(OpenGL REQUIRED)
    if(OpenGL_FOUND)
        target_link_libraries(RadarGuiProject PRIVATE ${OPENGL_LIBRARIES})
    endif()
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
