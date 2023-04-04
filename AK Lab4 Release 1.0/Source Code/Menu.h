#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <conio.h>

using namespace std;
using namespace filesystem;

class Menu
{
public:
	static void menu_start_screen(bool& error, path* directories, string* file_types, int dir_idx, int& ftypecount);
	static void menu_file_types(string* file_types, int& ftypecount);
	static void menu_end_screen();
};

