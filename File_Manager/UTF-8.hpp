#pragma once

#include <string>
#include <filesystem>
#include <windows.h>

namespace fs = std::filesystem;

std::string PathToUTF8(const fs::path& path);

