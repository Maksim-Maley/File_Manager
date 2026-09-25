#pragma once
#include <iostream>
#include <string>
#include <sstream>


class Enter
{
public:
	Enter();
	void Input();
    std::string GetCommand();
    std::string GetArgument();
    std::string GetArgument1();

private:
    std::string command;
    std::string argument;
    std::string argument1;
    std::string input;
};
