#include "Enter.hpp"
#include "Commands.hpp"

Enter enter;
Commands commands;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    namespace fs = std::filesystem;

    std::cout << "==============================\n";
    std::cout << "       C++ FILE MANAGER\n";
    std::cout << "=============================\n";
    std::cout << "\n";

    std::cout << "Current directory:" << std::endl;
    std::cout << PathToUTF8(fs::current_path()) << '\n'; 
    std::cout << "\n";

    std::cout << "Commands:" << std::endl;
    std::cout << "pwd" << std::endl;
    std::cout << "cd     " << "[path]|[..]" << std::endl;
    std::cout << "ls     " << "[none]|[path]" << std::endl;
    std::cout << "mkdir  " << "[namedir|pathdir]" << std::endl;
    std::cout << "create " << "[filename]" << std::endl;
    std::cout << "write  " << "[filename]" << std::endl;
    std::cout << "copy   " << "[filename][path|filename]" << std::endl;
    std::cout << "move   " << "[filename][path]" << std::endl;
    std::cout << "rename " << "[oldname][newname]" << std::endl;
    std::cout << "remove " << "[filename|dirname]" << std::endl;
    std::cout << "info   " << "[filename]" << std::endl;
    std::cout << "close" << std::endl;
    std::cout << "help" << std::endl;
    std::cout << "\n";

    for (;;)
    {
        enter.Input();

        std::string command = enter.GetCommand();
        std::string argument = enter.GetArgument();
        std::string argument1 = enter.GetArgument1();

        if (command == "close")
            break;

        if (command == "pwd")
            commands.pwd();

        else if (command == "cd")
        {
            commands.cd(argument);
        }

        else if (command == "ls")
        {
            commands.ls(argument);
        }

        else if (command == "mkdir")
        {
            commands.mkdir(argument);
        }

        else if (command == "create")
        {
            commands.create(argument);
        }

        else if (command == "write")
        {
            commands.write(argument);
        }

        else if (command == "copy")
        {
            commands.copy(argument, argument1);
        }

        else if (command == "move")
        {
            commands.move(argument, argument1);
        }

        else if (command == "rename")
        {
            commands.rename(argument, argument1);
        }

        else if (command == "remove")
        {
            commands.remove(argument);
        }

        else if (command == "info")
        {
            commands.info(argument);
        }

        else if (command == "help")
        {
            commands.help();
        }

    }


}
