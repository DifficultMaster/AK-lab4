#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <conio.h>

using namespace std;
using namespace filesystem;

class Count
{
public:
	static void count_current_dir(bool& error, int ftypecount, string* file_types);
	static void count_specified_dir(bool& error, int dir_idx, int ftypecount, path* directories, string* file_types);
};

