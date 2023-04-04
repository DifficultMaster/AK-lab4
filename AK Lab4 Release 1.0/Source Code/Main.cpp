#include "Menu.h"
#include "Enter.h"
#include "Count.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <conio.h>

using namespace std;
using namespace filesystem;

int main(int argc, char* argv[]) 
{   
    path directories[50];
    string file_types[50];
    int dir_idx = 0;
    int count = 0;
    int totalcount = 0;
    int ftypecount = 0;
    bool error = false;    

    if (argc == 1) 
    {        
        Menu::menu_start_screen(error, directories, file_types, dir_idx, ftypecount);             
    } 
    else 
    {
        for (int i = 1; i < argc; i++)
        {
            directories[dir_idx++] = argv[i];
        }   
        Menu::menu_file_types(file_types, ftypecount);
        Count::count_specified_dir(error, dir_idx, ftypecount, directories, file_types);
    }     
    
    Menu::menu_end_screen();

    if (error)
    {
        cout << "\nProgram exited with error code 1." << endl;
        return EXIT_FAILURE;
    }

    else return EXIT_SUCCESS;
}
