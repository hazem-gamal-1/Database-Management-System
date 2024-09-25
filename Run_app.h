#ifndef Run_app
#include<iostream>
#include"Folder.h"
#include"File.h"
#include"Database.h"
#include<iomanip>
using namespace std;
class Folder_Handling_Interface
{
public:
	void run()
	{
		int choice;
		folder f;
		do
		{
			cout << "Press to list the menu \n";
			_getwch();
			system("cls");
			system("Color E5");
			cout << "\n[1]Create folder \n";
			cout << "\n[2]Rename folder \n";
			cout << "\n[3]Move folder \n";
			cout << "\n[4]Delete folders \n";
			cout << "\n[5]Count number folders \n";
			cout << "\n[6]List all folders \n";
			cout << "\n[7]Return to the previous menue\n";
			cin >> choice;
			switch (choice)
			{

			case 1:
				f.create_folder();
				break;
			case 2:
				f.rename_folder();
				break;
			case 3:
				f.move_folder();
				break;
			case 4:
				f.remove_folder();
				break;
			case 5:
				f.count_folders();
				break;
			case 6:
				f.list_all_folders();
				break;
			default:
				break;
			}
		} while (choice >= 1 && choice <= 6);
	}
};
class Files_Handling_Interface {
public:
	void run()
	{
		int choice;
		file f;
		do
		{
			cout << "\npress to list the menu\n";
			_getwch();
			system("cls");
			system("Color E5");
			cout << "\n[1]Rename File \n";
			cout << "\n[2]Copy File \n";
			cout << "\n[3]Delete file \n";
			cout << "\n[4]Move file \n";
			cout << "\n[5]Count number files \n";
			cout << "\n[6]List all file \n";
			cout << "\n[7]List all files of specific extension \n";
			cout << "\n[8]Return to the previous menue\n";
			cin >> choice;
			switch (choice)
			{

			case 1:
				f.Rename_file();
				break;
			case 2:
				f.Copy_file();
				break;
			case 3:
				f.remove_file();
				break;
			case 4:
				f.move_file();
				break;
			case 5:
				f.count_files();
				break;
			case 6:
				f.list_all_files();
				break;
			case 7:
				f.list_all_files_of_specific_extension();
				break;
			default:
				break;
			}
		} while (choice >= 1 && choice <= 7);
	}
};
class Database_Interface
{
public:
	void run()
	{
		int choice1,choice2;
		Fixed_Length_File_Based_Database f;
		do
		{
			cout << "\npress to list the menu\n";
			_getwch();
			system("cls");
			system("Color E5");
			cout << "\n[1]To create a database\n";
			cout << "\n[2]To open a database\n";
			cout << "\n\[3]To return to the previous menu \n";
			cin >> choice1;
			switch (choice1)
			{
			case 1:
				f.creat();
				break;
			case 2:
				f.open();
				do
				{
					cout << "\npress to list the menu\n";
					_getwch();
					system("cls");
					system("Color E5");
					cout << "\n[1]To display attributes\n";
					cout << "\n[2]To insert a record\n";
					cout << "\n[3]To retrieve a record\n";
					cout << "\n[4]To update a record\n";
					cout << "\n[5]To delete record \n";
					cout << "\n[6]To search for a record\n";
					cout << "\n[7]To search for a record and save result \n";
					cout << "\n[8]To sort based on specific attribute\n";
					cout << "\n[9]To display all records in the database\n";
					cout << "\n[10]To filter based on criteria\n";
					cout << "\n[11]To encrypt the database \n";
					cout << "\n[12]To decrypt the database \n";
					cout << "\n[13]To convert database into html file\n";
					cout << "\n[14]To merge based on criteria\n";
					cout << "\n[15]To display the merged file \n";
					cout << "\n\[15]To return to the previous menu\n";
					cin >> choice2;
					switch (choice2)
					{
					case 1:
						f.display_attributes();
						break;
					case 2:
						f.Insert_record();
						break;
					case 3:
						f.Retreive_record();
						break;
					case 4:
						f.Updata_record();
						break;
					case 5:
						f.Delete_record();
						break;
					case 6:
						f.Search_for_record();
						break;
					case 7:
						f.Search_for_record_and_save_on_a_separate_file();
						break;
					case 8:
						f.sort_based_on_speific_field();
						break;
					case 9:
						f.Display_all();
						break;
					case 10:
						f.Filter_based_on_criteria();
						break;
					case 11:
						f.encypt();
						break;
					case 12:
						f.decrypt();
						break;
					case 13:
						f.convert_database_into_html_file();
						break;
					case 14:
						f.merge_based_on_criteria();
						break;
					case 15:
						f.Display_merged_file();
						break;
					default:
						break;
					}
				} while (choice2 >= 1 && choice2 <= 15);
				break;
			default:
				break;
			}
		} while (choice1 >= 1 && choice1 <= 2);
	}


};
class app
{
public:
	void run()
	{
		Folder_Handling_Interface f1;
		Files_Handling_Interface f2;
		Database_Interface f3;
		int choice;
		system("color E5");
		string s="Files and database managament application\nDeveloped by Hazem Gamal\n";
		for (int i = 0; i < s.size(); i++)
		{
			Sleep(100);
			cout << s[i];
		}
		cout << "\n Press any key to start \n";
		_getwch();
		do
		{
			system("color B0");
			system("cls");
			cout << "\n[1]To handle folders \n";
			cout << "\n[2]To handle files \n";
			cout << "\n[3]To handle Databases\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				f1.run();
				break;
			case 2:
				f2.run();
				break;
			case 3:
				f3.run();
			default:
				break;
			}
		} while (choice >= 1 && choice <= 3);
	}
};
#endif
#pragma once
