#include "Enter.hpp"

Enter::Enter()
{
	input = "";
}

void Enter::Input()
{
	std::cout << ">";
	std::getline(std::cin, input);

	command = "";
	argument = "";
	argument1 = "";

	std::stringstream ss(input);

	ss >> command;
	ss >> argument;
	ss >> argument1;
}

std::string Enter::GetCommand()
{
	return command;
}

std::string Enter::GetArgument()
{
	return argument;
}

std::string Enter::GetArgument1()
{
	return argument1;
}