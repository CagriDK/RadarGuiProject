#include "../include/Tools.h"

bool Tools::isFileExist(std::string filePath)
{
    return std::ifstream(filePath.c_str()).good();
}