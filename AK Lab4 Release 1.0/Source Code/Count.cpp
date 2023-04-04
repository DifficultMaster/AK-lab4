#include "Menu.h"
#include "Enter.h"
#include "Count.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <conio.h>

using namespace std;
using namespace filesystem;

void Count::count_current_dir(bool& error, int ftypecount, string* file_types)
{   
    system("CLS");

    cout << "--------------------------------------------------------\n" << endl;

    cout << "Attempting to count files in the current directory...\n" << endl;

    path current_directory;
    current_directory = filesystem::current_path();
    int count = 0;

    if (!exists(current_directory))
    {
        error = true;
        cout << "\nDirectory " << current_directory << " not found.\n";
        cout << "Check spelling and try again.\n" << endl;

        cout << "--------------------------------------------------------\n" << endl;

        system("pause\n");
        error ? EXIT_FAILURE : EXIT_SUCCESS;
        return;
    }
    else
    {
        if (ftypecount > 0)
        {
            for (const auto& dirEntry : recursive_directory_iterator(current_directory))
            {
                if (is_regular_file(dirEntry.path()))
                {
                    for (int i = 0; i < ftypecount - 1; i++)
                    {
                        if (dirEntry.path().extension() == file_types[i])
                        {                            
                            count++;
                            break;
                        }
                    }
                }
            }

            cout << "The directory " << current_directory << " contains " << count << " files of types";
            for (int i = 0; i < ftypecount - 1; i++)
            {
                cout << " '" << file_types[i] << "'";
                if (i < ftypecount - 2)
                {
                    cout << ",";
                }
            }
            cout << "." << endl << endl;
        }

        else
        {
            for (const auto& dirEntry : recursive_directory_iterator(current_directory))
            {
                if (is_regular_file(dirEntry.path()))
                {
                    count++;
                }
            }

            cout << "The directory " << current_directory << " contains " << count << " files.\n" << endl;
        }        

        cout << "--------------------------------------------------------\n" << endl;
    }

    system("pause\n");
    error ? EXIT_FAILURE : EXIT_SUCCESS;
}

void Count::count_specified_dir(bool& error, int dir_idx, int ftypecount, path* directories, string* file_types)
{  
    system("CLS");

    cout << "--------------------------------------------------------\n" << endl;

    if (dir_idx == 0)
    {
        error = true;
        cout << "You have not entered any directory paths.\n" << endl;

        cout << "--------------------------------------------------------\n" << endl;

        system("pause\n");
        error ? EXIT_FAILURE : EXIT_SUCCESS;
        return;
    }

    if (dir_idx > 1)
    {
        cout << "Attempting to count files in the specified directories..." << endl;
    }
    else cout << "Attempting to count files in the specified directory..." << endl;

    int total_count = 0;

    for (int i = 0; i < dir_idx; i++)
    {
        path current_directory = directories[i];
        int count = 0;

        if (!exists(current_directory))
        {
            error = true;
            cout << "\nDirectory " << current_directory << " not found.\n";
            cout << "Check spelling and try again.\n" << endl;

            cout << "--------------------------------------------------------\n" << endl;

            system("pause\n");
            error ? EXIT_FAILURE : EXIT_SUCCESS;
            return;
        }

        else
        {
            if (ftypecount > 0)
            {
                for (const auto& dirEntry : recursive_directory_iterator(current_directory))
                {
                    if (is_regular_file(dirEntry.path()))
                    {
                        for (int i = 0; i < ftypecount - 1; i++)
                        {
                            if (dirEntry.path().extension() == file_types[i])
                            {
                                count++;
                                break;
                            }
                        }
                    }
                }

                cout << "\nThe directory " << current_directory << " contains " << count << " files of types";
                for (int i = 0; i < ftypecount - 1; i++)
                {
                    cout << " '" << file_types[i] << "'";
                    if (i < ftypecount - 2)
                    {
                        cout << ",";
                    }
                }
                cout << "." << endl;

                total_count += count;
            }

            else
            {
                for (const auto& dirEntry : recursive_directory_iterator(current_directory))
                {
                    if (is_regular_file(dirEntry.path()))
                    {
                        count++;
                    }
                }

                cout << "\nThe directory " << current_directory << " contains " << count << " files." << endl;
                total_count += count;
            }                   
        }
    }

    cout << endl;

    if (dir_idx > 1)
    {
        cout << "Total number of";

        for (int i = 0; i < ftypecount - 1; i++)
        {
            cout << " '" << file_types[i] << "'";
            if (i < ftypecount - 2)
            {
                cout << ",";
            }
        }        
            
        cout << " files in all specified directories is: " << total_count << endl << endl;
    }

    cout << "--------------------------------------------------------\n" << endl;

    system("pause\n");
    error ? EXIT_FAILURE : EXIT_SUCCESS;
}

