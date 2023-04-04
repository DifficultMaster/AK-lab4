#include "Menu.h"
#include "Enter.h"
#include "Count.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <conio.h>

using namespace std;
using namespace filesystem;

void Menu::menu_start_screen(bool& error, path* directories, string* file_types, int dir_idx, int& ftypecount)
{
    system("CLS");

    cout << "--------------------------------------------------------\n" << endl;

    cout << "Do you wish to search in current directory or specific directories?\n" << endl;
    cout << "[1] --- CURRENT DIRECTORY (" << filesystem::current_path() << ")" << endl;
    cout << "[2] --- SPECIFIC DIRECTORIES" << endl << endl;

    cout << "--------------------------------------------------------\n" << endl;

    int keyPress = _getch();
    switch (keyPress)
    {
    case '1':
        menu_file_types(file_types, ftypecount);
        Count::count_current_dir(error, ftypecount, file_types);
        break;

    case '2':
        Enter::enter_specific_dir(directories, file_types, dir_idx, ftypecount);
        Count::count_specified_dir(error, dir_idx, ftypecount, directories, file_types);
        break;

    default:
        menu_start_screen(error, directories, file_types, dir_idx, ftypecount);
    }

    system("CLS");
}

void Menu::menu_file_types(string* file_types, int& ftypecount)
{
    system("CLS");

    cout << "--------------------------------------------------------\n" << endl;

    cout << "Do you wish to only count the files of specific types instead of all files?\n" << endl;

    cout << "[1] --- ALL FILES" << endl;
    cout << "[2] --- SPECIFIC FILES" << endl << endl;

    cout << "--------------------------------------------------------\n" << endl;

    int keyPress = _getch();
    switch (keyPress)
    {
    case '1':
        ftypecount = 0;
        break;

    case '2':
        Enter::enter_file_types(file_types, ftypecount);
        break;

    default:
        menu_file_types(file_types, ftypecount);
    }

    system("CLS");
}

void Menu::menu_end_screen()
{
    system("CLS");

    cout << "--------------------------------------------------------\n" << endl;

    cout << "Developed by Shevchenko Vladyslav, 2023\n" << endl;

    cout << "--------------------------------------------------------\n" << endl;

    system("pause\n");
}
