#include "UTF-8.hpp"

std::string PathToUTF8(const fs::path& path)
{
    std::wstring wide = path.wstring();

    int size = WideCharToMultiByte(
        CP_UTF8,
        0,
        wide.c_str(),
        -1,
        nullptr,
        0,
        nullptr,
        nullptr
    );

    std::string result(size - 1, '\0');

    WideCharToMultiByte(
        CP_UTF8,
        0,
        wide.c_str(),
        -1,
        result.data(),
        size,
        nullptr,
        nullptr
    );

    return result;
}