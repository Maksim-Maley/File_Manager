#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdint>
#include <windows.h>
#include "UTF-8.hpp"

namespace fs = std::filesystem;

struct HumanReadable
{
	std::uintmax_t size{};

private:
	friend std::ostream& operator<<(std::ostream& os, HumanReadable hr)
	{
		int o{};
		double mantissa = static_cast<double>(hr.size);
		for (; mantissa >= 1024.; mantissa /= 1024., ++o);
		os << std::ceil(mantissa * 10.) / 10. << "BKMGTPE"[o];
		return o ? os << "B (" << hr.size << ')' : os;
	}
};

class Commands
{
public:
	void pwd();
	void cd(const std::string& argument);
	void ls(const std::string& argument);
	void mkdir(const std::string& argument);
	void create(const std::string& argument);
	void write(const std::string& argument);
	void copy(const std::string& argument, const std::string& argument1);
	void move(const std::string& argument, const std::string& argument1);
	void rename(const std::string& argument, const std::string& argument1);
	void remove(const std::string& argument);
	void info(const std::string& argument);
	void help();
};

