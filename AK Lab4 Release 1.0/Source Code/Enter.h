#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <conio.h>

using namespace std;
using namespace filesystem;

class Enter
{
public:
	static void enter_specific_dir(path* directories, string* file_types, int& dir_idx, int& ftypecount);
	static void enter_file_types(string* file_types, int& ftypecount);
};

