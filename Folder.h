#ifndef Folder
#include<iostream>
#include<filesystem>
#include<system_error>
#include<fstream>
#include<Windows.h>
using namespace std;
using namespace std::filesystem;

class folder {

public:
	// function 1
	void create_folder()
	{
		string path;
		cout << "\nEnter path of the folder you want to create\n";
		cin.ignore(200, '\n');
		getline(cin, path);
		try {
			create_directory(path);
			cout << "\nFolder created successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 2
	void move_folder()
	{
		string path1, path2;
		cout << "\nEnter the source path of the folder\n";
		cin.ignore(200, '\n');
		getline(cin, path1);
		cout << "\nEnter the distination path of the folder\n";
		getline(cin, path2);
		try {
			rename(path1, path2);
			cout << "\nFolder moved successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 3
	void rename_folder()
	{
		string path1, path2;
		cout << "\nEnter the source path of the folder\n";
		cin.ignore(200, '\n');
		getline(cin, path1);
		cout << "\nEnter the distination path of the folder with new name\n";
		getline(cin, path2);
		try {
			rename(path1, path2);
			cout << "\nFolder renamed successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 4
	void remove_folder()
	{
		string path;
		cout << "\nEnter the path of the folder to be removed \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		try {
			remove_all(path);
			cout << "\nFolder removed successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 5
	void list_all_folders()
	{
		string path;
		cout << "\nEnter the path of the folder: \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		try {
			for (auto& entry : directory_iterator(path))
			{
				if (entry.is_directory())
				{
					cout << entry.path().filename()  <<"\n";
				}
			}
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 6
	void count_folders()
	{
		string path;
		cout << "\nEnter the path of the folder: \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		try {
			int counter = 0;
			for (auto& entry : directory_iterator(path))
			{
				if (entry.is_directory())
					counter++;
			}
			cout << "number of folders: " << counter << "\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	
};
//C:\\Users\\M.C 28-06-2023\\source\\repos\\File_handling_application\\File_handling_application\\wow
#endif Folder
#pragma once
