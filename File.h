#ifndef File
#include<iostream>
#include<filesystem>
#include<system_error>
#include<fstream>
#include<Windows.h>
using namespace std;
using namespace std::filesystem;
class file
{
public:
	//function 1
	void move_file()
	{
		string path1, path2;
		cout << "\nEnter the source path of the file\n";
		cin.ignore(200, '\n');
		getline(cin, path1);
		cout << "\nEnter the distination path of the file\n";
		getline(cin, path2);
		try {
			rename(path1, path2);
			cout << "\nFile moved successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 2
	void Rename_file()
	{
		string path1, path2;
		cout << "\nEnter the source path of the file\n";
		cin.ignore(200, '\n');
		getline(cin, path1);
		cout << "\nEnter the distination path of the file with new name\n";
		getline(cin, path2);
		try {
			rename(path1, path2);
			cout << "\n File renamed successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 3
	void Copy_file()
	{
		string path1, path2;
		cout << "\nEnter the source path of the file\n";
		cin.ignore(200, '\n');
		getline(cin, path1);
		cout << "\nEnter the distination path of the file\n";
		getline(cin, path2);
		try {
			copy_file(path1, path2);
			cout << "\n File copyed successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 4
	void remove_file()
	{
		string path;
		cout << "\nEnter the path of the file to be removed \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		try {
			remove(path);
			cout << "\n File removed successfully\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 5
	void list_all_files()
	{
		string path;
		cout << "\nEnter the path of the folder: \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		try {
			for (auto& entry : directory_iterator(path))
			{
				if (!entry.is_directory())
				{
					cout << entry.path().filename() << "\n";
				}
			}
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 6
	void list_all_files_of_specific_extension()
	{
		string path, extension;
		cout << "\nEnter the path of the folder: \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		cout << "\nEnter the extension \n";
		cin >> extension;
		try {
			for (auto& entry : directory_iterator(path))
			{
				if (entry.path().extension() == extension)
				{
					cout << entry.path().filename() << "\n";
				}
			}
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}

	//function 7
	void count_files()
	{
		string path;
		cout << "\nEnter the path of the folder: \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		try {
			int counter = 0;
			for (auto& entry : directory_iterator(path))
			{
				if (!entry.is_directory())
					counter++;
			}
			cout << "number of files: " << counter << "\n";
		}
		catch (const system_error& e)
		{
			cout << e.what() << "\n";
		}
	}
};
#endif File
#pragma once
