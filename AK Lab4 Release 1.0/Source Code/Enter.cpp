#include "Menu.h"
#include "Enter.h"
#include "Count.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <conio.h>

using namespace std;
using namespace filesystem;

void Enter::enter_specific_dir(path* directories, string* file_types, int& dir_idx, int& ftypecount)
{
    system("CLS");

    cout << "--------------------------------------------------------\n" << endl;

    cout << "Enter directory paths separated by commas ',' with NO SPACES, excluding any symbols not present within the actual path:\n" << endl;

    string input;
    getline(cin, input);

    istringstream check(input);
    string path;

    while (getline(check, path, ','))
    {
        directories[dir_idx++] = path;
    }

    system("CLS");

    Menu::menu_file_types(file_types, ftypecount);
}

void Enter::enter_file_types(string* file_types, int& ftypecount)
{
    system("CLS");

    cout << "--------------------------------------------------------\n" << endl;

    cout << "Enter only the file types you want to count separated by spaces, such as '.exe .jpeg .txt':\n" << endl;

    string input;
    getline(cin, input);
    istringstream stream(input);

    do
    {
        stream >> file_types[ftypecount++];
    } while (stream);

    system("CLS");
}
