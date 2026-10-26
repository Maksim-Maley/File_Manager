# C++ File Manager

[English](#english) | [Русский](#русский)

<a id="english"></a>
## English

A command-line file manager written in C++20 for Windows. The project uses `std::filesystem` to navigate directories and perform common file operations.

### Features

- Display the current working directory (`pwd`).
- Change the current directory (`cd`).
- List directory entries and distinguish files from directories (`ls`).
- Create directories and files (`mkdir`, `create`).
- Write a line of text to a file (`write`).
- Copy files, including creating a `_copy` file when no destination directory is supplied (`copy`).
- Move and rename files (`move`, `rename`).
- Display basic information about a regular file (`info`).
- Remove files or directory trees (`remove`).
- Display the command list (`help`).

### Technology

- C++20
- Standard Library: `std::filesystem`, file streams and string streams
- Windows console APIs for UTF-8 console code-page configuration

### Requirements

- Windows
- Visual Studio with the C++ desktop development workload and a compatible toolset for the project
- C++20 support

### Build and run

1. Clone or download this repository.
2. Open `File_Manager.slnx` in a compatible version of Visual Studio.
3. Select a configuration such as **Debug | x64**.
4. Build the solution and run the console application.

The build has not been independently verified as part of this README preparation.

### Commands

Run commands in the application's console:

| Command | Usage | Description |
|---|---|---|
| `pwd` | `pwd` | Print the current directory. |
| `cd` | `cd path` or `cd ..` | Change the current directory. |
| `ls` | `ls` or `ls path` | List entries in a directory. |
| `mkdir` | `mkdir folder` | Create a directory. |
| `create` | `create file.txt` | Create or open a file for output. |
| `write` | `write file.txt` | Prompt for one line and write it to the file. |
| `copy` | `copy file.txt` or `copy file.txt destination_folder` | Copy a file. With no destination folder, create a sibling named with the `_copy` suffix. |
| `move` | `move file.txt destination_folder` | Move a file into a destination directory. |
| `rename` | `rename old.txt new.txt` | Rename a file or filesystem entry. |
| `remove` | `remove path` | Remove a file or directory tree. |
| `info` | `info file.txt` | Show basic information about a regular file. |
| `help` | `help` | Print the command list. |
| `close` | `close` | Exit the application. |

### Important notes and current limitations

- **Destructive operation:** `remove` uses `std::filesystem::remove_all`, so removing a directory can delete its contents recursively. Check the path carefully before using it.
- **Overwrite behavior:** `write` opens the target with `std::ios::trunc`, replacing the file's previous contents with the single line entered.
- **Command parsing:** the current parser extracts whitespace-separated tokens. Paths containing spaces are not reliably supported.
- `copy` treats its optional second argument as a destination directory, not as a complete destination filename.
- `move` uses `std::filesystem::rename`; behavior can differ when moving across volumes.
- The displayed modification time is currently the raw filesystem clock representation rather than a formatted date and time.

### Project structure

```text
File_Manager/
├── main.cpp          # Command loop and command dispatch
├── Enter.hpp/.cpp    # Read and parse console input
├── Commands.hpp/.cpp # File-system command implementations
├── UTF-8.hpp/.cpp    # Path-to-UTF-8 conversion helper
└── File_Manager.vcxproj
```

### Purpose

This project is a practical exercise in C++ filesystem operations, console input parsing, error handling, and separating command dispatch from command implementation.

---

<a id="русский"></a>
## Русский

Консольный файловый менеджер на C++20 для Windows. Проект использует `std::filesystem` для навигации по каталогам и выполнения распространённых файловых операций.

### Возможности

- Показ текущего рабочего каталога (`pwd`).
- Переход в другой каталог (`cd`).
- Просмотр содержимого каталога с различением файлов и папок (`ls`).
- Создание каталогов и файлов (`mkdir`, `create`).
- Запись одной строки текста в файл (`write`).
- Копирование файлов; если каталог назначения не указан, создаётся копия с суффиксом `_copy` (`copy`).
- Перемещение и переименование (`move`, `rename`).
- Вывод основной информации об обычном файле (`info`).
- Удаление файлов и деревьев каталогов (`remove`).
- Вывод списка команд (`help`).

### Технологии

- C++20
- Стандартная библиотека: `std::filesystem`, файловые и строковые потоки
- Windows Console API для настройки кодовой страницы UTF-8

### Требования

- Windows
- Visual Studio с компонентом разработки классических приложений на C++ и совместимым toolset
- Поддержка C++20

### Сборка и запуск

1. Клонируйте репозиторий или скачайте его архив.
2. Откройте `File_Manager.slnx` в совместимой версии Visual Studio.
3. Выберите конфигурацию, например **Debug | x64**.
4. Соберите решение и запустите консольное приложение.

Сборка не проверялась отдельно в рамках подготовки этого README.

### Команды

| Команда | Использование | Описание |
|---|---|---|
| `pwd` | `pwd` | Показать текущий каталог. |
| `cd` | `cd path` или `cd ..` | Перейти в каталог. |
| `ls` | `ls` или `ls path` | Показать содержимое каталога. |
| `mkdir` | `mkdir folder` | Создать каталог. |
| `create` | `create file.txt` | Создать файл или открыть его для вывода. |
| `write` | `write file.txt` | Запросить одну строку и записать её в файл. |
| `copy` | `copy file.txt` или `copy file.txt destination_folder` | Скопировать файл. Без каталога назначения создаётся копия с суффиксом `_copy`. |
| `move` | `move file.txt destination_folder` | Переместить файл в каталог назначения. |
| `rename` | `rename old.txt new.txt` | Переименовать файл или другой элемент файловой системы. |
| `remove` | `remove path` | Удалить файл или дерево каталогов. |
| `info` | `info file.txt` | Показать основную информацию об обычном файле. |
| `help` | `help` | Вывести список команд. |
| `close` | `close` | Завершить работу программы. |

### Важные замечания и текущие ограничения

- **Опасная операция:** `remove` использует `std::filesystem::remove_all`, поэтому при удалении каталога его содержимое также удаляется рекурсивно. Внимательно проверяйте путь.
- **Перезапись файла:** `write` открывает файл с `std::ios::trunc`, удаляет предыдущее содержимое и записывает одну введённую строку.
- **Разбор команд:** текущий парсер разделяет ввод по пробельным символам. Пути с пробелами надёжно не поддерживаются.
- Второй аргумент `copy` трактуется как каталог назначения, а не как полное имя целевого файла.
- `move` использует `std::filesystem::rename`; перемещение между разными томами может работать иначе.
- Время изменения файла пока выводится в сыром формате часов файловой системы, а не как привычные дата и время.

### Структура проекта

```text
File_Manager/
├── main.cpp          # Цикл команд и выбор обработчика
├── Enter.hpp/.cpp    # Ввод и разбор командной строки
├── Commands.hpp/.cpp # Реализация файловых команд
├── UTF-8.hpp/.cpp    # Преобразование путей в UTF-8
└── File_Manager.vcxproj
```

### Цель проекта

Практика работы с файловой системой в C++, разбора консольного ввода, обработки ошибок и разделения диспетчеризации команд и их реализации.
