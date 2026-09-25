#include "Commands.hpp"

void Commands::pwd()
{
    std::cout << PathToUTF8(fs::current_path()) << '\n';
}

void Commands::cd(const std::string& argument)
{
    if (argument.empty())
    {
        std::cout << "Укажите путь\n";
        return;
    }

    try
    {
        if (argument == "..")
        {
            fs::current_path(fs::current_path().parent_path());
        }
        else
        {
            fs::current_path(argument);
        }

        std::cout << PathToUTF8(fs::current_path()) << '\n';
    }
    catch (const fs::filesystem_error& e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }
}

void Commands::ls(const std::string& argument)
{
    try
    {
        fs::path targetPath;

        if (!argument.empty())
            targetPath = argument;
        else
            targetPath = fs::current_path();

        for (const auto& entry : fs::directory_iterator{ targetPath })
        {
            if (entry.is_directory())
                std::cout << "[DIR] ";
            else
                std::cout << "[FILE] ";

            std::cout << PathToUTF8(entry.path().filename()) << '\n';
        }
    }
    catch (const fs::filesystem_error& e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }
}

void Commands::mkdir(const std::string& argument)
{
    if (argument.empty())
    {
        std::cout << "Укажите имя каталога\n";
    }
    else
    {
        try
        {
            if (fs::create_directory(argument))
                std::cout << "Каталог создан\n";
            else
                std::cout << "Каталог уже существует\n";
        }
        catch (const fs::filesystem_error& e)
        {
            std::cout << "Ошибка: " << e.what() << '\n';
        }
    }
}

void Commands::create(const std::string& argument)
{
    if (argument.empty())
    {
        std::cout << "Укажите имя файла\n";
    }
    else
    {
        std::ofstream file(argument);

        if (file)
            std::cout << "Файл создан\n";
        else
            std::cout << "Не удалось создать файл\n";
    }
}

void Commands::write(const std::string& argument)
{
    if (argument.empty())
    {
        std::cout << "Укажите имя файла\n";
    }
    else
    {
        std::cout << "Ввод: ";

        std::string text;
        std::getline(std::cin, text);

        std::ofstream file(argument, std::ios::trunc);

        if (file.is_open())
        {
            file << text;
            file.close();
            std::cout << "Файл записан\n";
        }
        else
        {
            std::cout << "Ошибка открытия файла\n";
        }
    }
}

void Commands::copy(const std::string& argument, const std::string& argument1)
{
    fs::path source = argument;
    fs::path destination;

    try
    {
        if (argument1.empty())
        {
            destination = source.parent_path() /
                (source.stem().string() + "_copy" + source.extension().string());
        }
        else
        {
            destination = fs::path(argument1) / source.filename();
        }

        fs::copy_file(
            source,
            destination,
            fs::copy_options::overwrite_existing
        );

        std::cout << "Файл скопирован: "
            << PathToUTF8(destination.filename()) << '\n';
    }
    catch (const fs::filesystem_error& e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }
}

void Commands::move(const std::string& argument, const std::string& argument1)
{
    try
    {
        if (argument.empty())
        {
            std::cout << "Укажите исходный файл\n";
        }
        else if (argument1.empty())
        {
            std::cout << "Укажите директорию назначения\n";
        }
        else
        {
            fs::path source = argument;
            fs::path destination = fs::path(argument1) / source.filename();
            fs::rename(source, destination);
        }
    }
    catch (const fs::filesystem_error& e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }
}

void Commands::rename(const std::string& argument, const std::string& argument1)
{
    try
    {
        if (argument.empty())
        {
            std::cout << "Укажите старое имя\n";
        }
        else if (argument1.empty())
        {
            std::cout << "Укажите новое название\n";
        }
        else
        {
            fs::path lastname = argument;
            fs::path newname = argument1;
            fs::rename(lastname, newname);
        }
    }
    catch (const fs::filesystem_error& e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }
}

void Commands::remove(const std::string& argument)
{
    if (argument.empty())
    {
        std::cout << "Укажите файл или каталог\n";
    }
    else
    {
        try
        {
            std::uintmax_t count = fs::remove_all(argument);

            if (count == 0)
                std::cout << "Файл или каталог не найден\n";
            else
                std::cout << "Удалено объектов: "
                << count << '\n';
        }
        catch (const fs::filesystem_error& e)
        {
            std::cout << "Ошибка: " << e.what() << '\n';
        }
    }
}

void Commands::info(const std::string& argument)
{
    fs::path source = argument;

    if (argument.empty())
    {
        std::cout << "Укажите имя файла\n";
    }
    else
    {
        if (!fs::exists(source))
        {
            std::cout << "Файл не существует\n";
            return;
        }

        if (!fs::is_regular_file(source))
        {
            std::cout << "Это не обычный файл\n";
            return;
        }

        std::cout << "=============================\n";
        std::cout << "File information\n";
        std::cout << "=============================\n";
        std::cout << "\n";

        std::cout << "Name:       " << PathToUTF8(source.filename()) << std::endl;
        std::cout << "Path:       " << PathToUTF8(fs::absolute(source).parent_path()) << std::endl;
        std::cout << "Size:       " << HumanReadable{ fs::file_size(source) } << std::endl;
        std::cout << "Extension:  " << PathToUTF8(source.extension()) << std::endl;
        std::cout << "\n";
        std::cout << "Last modified:" << std::endl;
        std::cout << fs::last_write_time(source) << std::endl;

        /*fs::is_regular_file(argument);
        fs::is_directory(argument);*/
    }
}

void Commands::help()
{
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
}