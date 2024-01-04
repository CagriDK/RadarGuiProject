#pragma once

#define ValueTypeX(value) std::remove_reference<decltype(value)>::type

#define GET(Type, MemberName, FaceName) \
    Type get##FaceName() const          \
    {                                   \
        return MemberName;              \
    }                                   

#define SET(Type, MemberName, FaceName) \
    Type set##FaceName(Type value)      \
    {                                   \
        MemberName = value;             \
    }

#define GETSET(Type, MemberName, FaceName) \
    GET(Type, MemberName, FaceName)        \
    SET(Type, MemberName, FaceName)

#ifdef _WIN32
#include <winsock2.h>
#include <Windows.h>
#elif defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__)
#include <X11/Xlib.h>
#endif

#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../Dependencies/include/nlohmann/json.hpp"
#include <algorithm>

using json = nlohmann::json;

class Tools
{
    public:
    /// @brief Check if file exist
    /// @param filePath Path of file
    /// @return true if file exist, false if not
    static bool isFileExist(std::string filePath);
};