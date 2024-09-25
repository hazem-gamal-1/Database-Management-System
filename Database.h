#ifndef Database
#include<iostream>
#include<fstream>
#include<filesystem>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
using namespace std::filesystem;
class Fixed_Length_File_Based_Database
{
private:
	path path_of_database;
	path path_of_attributes;
	int number_of_attributes;
	int number_of_records ;
public:
	// function 1
	void creat()
	{
		system("cls");
		try
		{
			string p;
			cout << "\nEnter the path of the database folder\n";
			cin.ignore(200, '\n');
			getline(cin, p);
			create_directory(p);


			int num;
			cout << "\nEnter number of attributes: \n";
			cin >> num;
			number_of_attributes = num;
			char attribute[30];
			path file_path = (path)p / "attributes.txt";
			path_of_attributes = file_path;
			ofstream out_file(file_path);
			for (int i = 0; i < num; i++)
			{
				cout << "\nEnter Attribute " << i+1<< "\n";
				cin >> attribute;
				out_file << attribute << ' ';
			}
			path_of_database = (path)p / "table.txt";
			ofstream outFile;
			outFile.open(path_of_database, ios::_Noreplace);
			cout << "\Created successfully \n";
		}
		catch (const exception& e)
		{
			cout << e.what();
		}
	}
	// function 2
	void open()
	{
		system("cls");
		try {
			string path;
			cout << "\nEnter the path of the database folder\n";
			cin.ignore(200, '\n');
			getline(cin, path);
			for (const auto& entry : directory_iterator(path))
			{
				if (entry.path().filename() == "attributes.txt")
				{
					path_of_attributes = entry.path().string();
				}
				else if (entry.path().filename() == "table.txt")
				{
					path_of_database = entry.path().string();
				}
			}
			ifstream file_to_read_attributes(path_of_attributes);
			int count = 0;
			string word;
			while (file_to_read_attributes >> word)
				count++;
			number_of_attributes = count;
			count_records();
			cout << "Opened successfully \n";
		}
		catch (const exception& e)
		{
			cout << e.what();
		}
	}
	// function 3
	void Retreive_record()
	{
		system("cls");
		char key[30], line[30];
		cout << "Enter key of record you want to retrieve: ";
		cin >> key;
		ifstream file_to_read(path_of_database);
		file_to_read.seekg(0, ios::beg);
		vector<string> attributes(number_of_attributes);
		int count = 0;
		while (file_to_read.read(line, 30))
		{
			attributes[count] = line;
			count++;
			if (count == number_of_attributes)
			{
				display_attributes();
				if (attributes[0] == key)
				{
					Display_record_(attributes);
					return;
				}
				count = 0;
			}
		}

		cout << "Not Found \n";
	}
	// function 4
	void Insert_record()
	{
		system("cls");
		ofstream file_to_write(path_of_database, ios::out | ios::app);
		ifstream file_to_read_attributes(path_of_attributes);
		string attribute;
		file_to_write.seekp(0, ios::end);
		char input[30];
		while (file_to_read_attributes >> attribute)
		{
			cout << "\nEnter " << attribute << "\n";
			cin >> input;
			file_to_write.write(input,30);
		}
		cout << "Inserted Successfully\n";
		number_of_records++;
	}
	// function 5
	void Updata_record()
	{
		system("cls");
		char key[30], line[30];
		cout << "Enter key of record you want to update: ";
		cin >> key;
		ifstream file_to_read(path_of_database);
		ifstream file_to_read_attributes(path_of_attributes);
		ofstream file_to_write(path_of_database, ios::out | ios::in);
		file_to_read.seekg(0, ios::beg);
		file_to_write.seekp(0, ios::beg);
		file_to_read_attributes.seekg(0, ios::beg);
		vector<string> attributes(number_of_attributes);
		int count = 0;
		while (file_to_read.read(line, 30))
		{
			attributes[count] = line;
			count++;
			if (count == number_of_attributes)
			{
				if (attributes[0] == key)
				{
					int cur = file_to_read.tellg();
					file_to_write.seekp(cur - number_of_attributes * 30);
					string attribute;
					char input[30];
					while (file_to_read_attributes >> attribute)
					{
						cout << "\nEnter " << attribute << "\n";
						cin >> input;
						file_to_write.write(input, 30);
					}
					cout << "Updated successfully\n";
					return;
				}
				count = 0;
			}
		}

		cout << "Not Found \n";
	}
	// function 6
	void Delete_record()
	{
		system("cls");
		char key[30], line[30];
		cout << "Enter key of record you want to delete: ";
		cin >> key;
		ifstream file_to_read(path_of_database);
		ofstream file_to_write(path_of_database, ios::out | ios::in);
		file_to_read.seekg(0, ios::beg);
		file_to_write.seekp(0, ios::beg);
		vector<string> attributes(number_of_attributes);
		int count = 0;
		while (file_to_read.read(line, 30))
		{
			attributes[count] = line;
			count++;
			if (count == number_of_attributes)
			{
				if (attributes[0] == key)
				{
					int cur = file_to_read.tellg();
					file_to_write.seekp(cur - number_of_attributes * 30);
					char attribute[30];
					char input[30] = "";
					for (int i = 0; i < number_of_attributes; i++)
						file_to_write.write(input, 30);
					return;
					cout << "Deleted successfully\n";
				}
				count = 0;
			}
		}
		cout << "Not Found \n";
	}
	// function 7
	void Search_for_record()
	{
		system("cls");
		char key[30], line[30];
		cout << "Enter key of record you want to retrieve: ";
		cin >> key;
		ifstream file_to_read(path_of_database);
		file_to_read.seekg(0, ios::beg);
		vector<string> attributes(number_of_attributes);
		int count = 0;
		while (file_to_read.read(line, 30))
		{
			attributes[count] = line;
			count++;
			if (count == number_of_attributes)
			{
				if (attributes[0] == key)
				{
					cout << "Found \n";
					return;
				}
				count = 0;
			}
		}

		cout << "Not Found \n";
	}
	// function 8
	void Search_for_record_and_save_on_a_separate_file()
	{
		system("cls");
		char key[30], line[30];
		cout << "Enter key of record you want to retrieve: ";
		cin >> key;
		ifstream file_to_read(path_of_database);
		file_to_read.seekg(0, ios::beg);
		vector<string> attributes(number_of_attributes);
		int count = 0;
		while (file_to_read.read(line, 30))
		{
			attributes[count] = line;
			count++;
			if (count == number_of_attributes)
			{
				if (attributes[0] == key)
				{
					cout << "Enter path of the file to save result \n";
					string path;
					cin.ignore(200, '\n');
					getline(cin, path);
					ofstream file(path, ios::out | ios::app);
					for (int i = 0; i < number_of_attributes; i++)
					{
						const char* str = attributes[i].c_str();
						char entry[30];
						strcpy_s(entry, 30, str);
						file.write(entry, 30);
					}
					cout << "Saved successfully\n";
					return;
				}
				count = 0;
			}
		}

		cout << "Not Found \n";
	}
	// function 9
	void sort_based_on_speific_field()
	{
		system("cls");
		int num,condition;
		display_attributes();
		cout << "Enter number of attribute you want to sort by\n ";
		cin >> num;
		cout << "\n[1]string\n";
		cout << "\n[2]int\n";
		cin >> condition;
		vector<string> attributes_of_record_1(number_of_attributes);
		vector<string> attributes_of_record_2(number_of_attributes);
		ifstream file_to_read(path_of_database);
		ofstream file_to_write(path_of_database, ios::in | ios::out);
		file_to_read.seekg(0, ios::beg);
		file_to_write.seekp(0, ios::beg);
		char key1[30], key2[30];
		for (int i = 0; i < number_of_records-1; i++)
		{
			for (int j = 0; j < number_of_records-i-1; j++)
			{
				file_to_read.seekg(j * number_of_attributes * 30, ios::beg);
				file_to_write.seekp(file_to_read.tellg(), ios::beg);
				for (int f = 0; f < number_of_attributes; f++)
				{
					file_to_read.read(key1, 30);
					attributes_of_record_1[f] = key1;
				}
				for (int f = 0; f < number_of_attributes; f++)
				{
					file_to_read.read(key2, 30);
					attributes_of_record_2[f] = key2;
					

				}
				if(condition==1){
					string cmp1 = attributes_of_record_1[num - 1];
					string cmp2 = attributes_of_record_2[num - 1];
					if (cmp1 > cmp2)
					{
						for (int e = 0; e < number_of_attributes; e++)
						{
							const char* word = attributes_of_record_2[e].c_str();
							char key[30];
							strcpy_s(key, word);
							file_to_write.write(key, 30);
						}

						for (int e = 0; e < number_of_attributes; e++)
						{
							const char* word = attributes_of_record_1[e].c_str();
							char key[30];
							strcpy_s(key, word);
							file_to_write.write(key, 30);
						}
					}
				}
				else {
					const char *str= attributes_of_record_1[num - 1].c_str();
					int cmp1 = atoi(str);
					str = attributes_of_record_2[num - 1].c_str();
					int cmp2 = atoi(str);
					if (cmp1 > cmp2)
					{
						for (int e = 0; e < number_of_attributes; e++)
						{
							const char* word = attributes_of_record_2[e].c_str();
							char key[30];
							strcpy_s(key, word);
							file_to_write.write(key, 30);
						}

						for (int e = 0; e < number_of_attributes; e++)
						{
							const char* word = attributes_of_record_1[e].c_str();
							char key[30];
							strcpy_s(key, word);
							file_to_write.write(key, 30);
						}
					}
				}
				
			}
		}
		cout << "\nSorted successfully\n";
	}
	// function 10
	void Filter_based_on_criteria()
	{
		system("cls");
		char line[30];
		string value;
		int num, choice = 0;
		display_attributes();
		cout << "\nEnter number of attribute you want to filter by\n ";
		cin >> num;
		cout << "\n[1]Start with: \n";
		cout << "\n[2]End with: \n";
		cout << "\n[3]Greater than: \n";
		cout << "\n[4]Less than: \n";
		cout << "\n[5]Equal: \n";
		cin >> choice;
		cout << "Enter value to filter by \n";
		cin >> value;
		display_attributes();
		try {
			ifstream file_to_read(path_of_database, ios::in);
			file_to_read.seekg(0, ios::beg);
			vector<string> attributes(number_of_attributes);
			int count = 0;
			while (file_to_read.read(line, 30))
			{
				string temp = "";
				int co = 1;
				attributes[count] = line;
				count++;
				if (count == number_of_attributes)
				{
					string v = value;
					const char* str = attributes[num - 1].c_str();
					int cmp1 = atoi(str);
					str = v.c_str();
					int cmp2 = atoi(str);
					switch (choice)
					{
					case 1:
						if (attributes[num - 1].substr(0, value.size()) == value)
							Display_record_(attributes);
						break;
					case 2:
						for (int i = attributes[num-1].size() - 1; i >= 0&&co<=value.size();i--,co++)
							temp +=attributes[num-1][i];
						reverse(temp.begin(), temp.end());
						if (temp == value)
							Display_record_(attributes);
						break;
					case 3:
						if (cmp1 > cmp2)
							Display_record_(attributes);
						break;
					case 4:
						if (cmp1 < cmp2)
							Display_record_(attributes);
						break;
					case 5:
						if (attributes[num - 1] == value)
							Display_record_(attributes);
						break;
					default:
						break;
					}
					count = 0;
				}
			}
		}
		catch (const exception& e) 
		{
			cout << e.what()<<"\n";
		}
	}
	// function 11
	void Display_all()
	{
		system("cls");
		ifstream file_to_read(path_of_database);
		display_attributes();
		file_to_read.seekg(0, ios::beg);
		char key[30];
		int count = 0;
		while (file_to_read.read(key, 30))
		{
			string word = key;
			count++;
			if (count == number_of_attributes)
			{
				if(word!="")
				cout << setiosflags(ios::left) << setw(30) << key << "\n";
				count = 0;
			}
			else
			{
				if(word!="")
				cout << setiosflags(ios::left) << setw(30) << key;
			}
		}
	}
	// function 12
	void Display_record_(vector<string>& attributes)
	{
		for (int i = 0; i < attributes.size(); i++) {
			cout << setiosflags(ios::left) << setw(30) << attributes[i];
		}
		cout << "\n";
	}
	// function 13
	void display_attributes()
	{
		system("cls");
		ifstream file_to_read_attributes(path_of_attributes);
		file_to_read_attributes.seekg(0, ios::beg);
		string key;
		int count = 0;
		while (file_to_read_attributes >> key)
		{
			cout << setiosflags(ios::left) << setw(30) << key;
		}
		cout << "\n";
	}
	// function 14
	void encypt()
	{
		system("cls");
		int key;
		cout << "\nEnter key to encrypt using it\n";
		cin >> key;
		ifstream file_to_read(path_of_database);
		ofstream file_to_write(path_of_database, ios::out | ios::in);
		file_to_read.seekg(0, ios::beg);
		file_to_write.seekp(0, ios::beg);
		char c;
		while (file_to_read >> c)
		{
			c += key;
			file_to_write << c;
		}
		cout << "\nEncypted successfully\n";

	}
	// function 15
	void decrypt()
	{
		system("cls");
		int k;
		cout << "\nEnter key to decrypt using it\n";
		cin >> k;
		ifstream file_to_read(path_of_database);
		ofstream file_to_write(path_of_database, ios::out | ios::in);
		file_to_read.seekg(0, ios::beg);
		file_to_write.seekp(0, ios::beg);
		char c;
		while (file_to_read >> c)
		{
			c -= k;
			file_to_write << c;
		}
		cout << "\nDecypted successfully\n";
	}
	// function 16
	void count_records()
	{
		system("cls");
		char line[30];
		ifstream file_to_read(path_of_database);
		file_to_read.seekg(0, ios::beg);
		vector<string> attributes(number_of_attributes);
		int count = 0, records = 0;
		while (file_to_read.read(line, 30))
		{
			attributes[count] = line;
			count++;
			if (count == number_of_attributes)
			{
				records++;
				count = 0;
			}
		}
		number_of_records = records;
	};
	//function 17
	void convert_database_into_html_file()
	{
		system("cls");
		string tag1, tag2, tag3, tag4,path;
		tag2 = "<tr>";
		tag1 = "<th>";
		tag2 = "</th>";
		tag4= "</tr>";
		cout << "\nEnter path of the html file \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		ofstream file_to_write(path,ios::app);
		string p = "C:\\Users\\M.C 28-06-2023\\source\\repos\\File_handling_application\\File_handling_application\\tags.txt";
		ifstream file_to_read_tags(p);
		ifstream file_to_read_attributes(path_of_attributes);
		file_to_read_attributes.seekg(0, ios::beg);
		string line;
		while (getline(file_to_read_tags,line))
		{
			if (line == "1")
			{
				string key;
				while (file_to_read_attributes >> key)
				{
					file_to_write << tag1 << '\n';
					file_to_write << key << "\n";
					file_to_write << tag2 << '\n';
				}
				file_to_write << tag4;
			}
			else if (line == "2")
			{
				tag1 = "<tr>";
				tag2 = "<td>";
				tag3 = "</td>";
				tag4 = "</tr>";
				ifstream file_to_read(path_of_database);
				file_to_read.seekg(0, ios::beg);
				char key[30];
				int count = 0;
				while (file_to_read.read(key, 30))
				{
					string word = key;
					if (count == 0)
						file_to_write << tag1;
					count++;
					if (count == number_of_attributes)
					{
						if (word != "") {
							file_to_write << tag2 << '\n';
							file_to_write << word << '\n';
							file_to_write << tag3 << '\n';
							file_to_write << tag4;
						}
						count = 0;
					}
					else
					{
						if (word != "") {
							file_to_write << tag2 << '\n';
							file_to_write << word << '\n';
							file_to_write << tag3 << '\n';
						}
					}
				}
			}
			else
				file_to_write << line << '\n';
		}
		cout << "\nFile created successfully\n";
	}
	//function 18
	vector<string> search_(string key,path path)
	{
		char line[30];
		ifstream file_to_read(path);
		file_to_read.seekg(0, ios::beg);
		vector<string> attributes(number_of_attributes);
		int count = 0;
		while (file_to_read.read(line, 30))
		{
			attributes[count] = line;
			count++;
			if (count == number_of_attributes)
			{
				if (attributes[0] == key)
				{
					return attributes;
				}
				count = 0;
			}
		}

		return vector<string> ();
	}
	//function 19
	void merge_based_on_criteria()
	{
		system("cls");
		string path2, path3;
		int num,choice;
		cout << "\n Enter the path of the second file \n";
		cin.ignore(200, '\n');
		getline(cin, path2);
		cout << "\n Enter the path of file used to merge\n";
		getline(cin, path3);
		cout << "\nEnter number of the attribute to merge by\n";
		cin >> num;
		cout << "\n[1]Max\n";
		cout << "\n[2]Min\n";
		cout << "\n[3]Summation\n";
		cout << "\n[4]Difference\n";
		cout << "\n[5]Averge\n";
		cin >> choice;
		ifstream file_to_read(path2);
		ofstream file_to_write(path3,ios::out|ios::app);
		file_to_read.seekg(0, ios::beg);
		file_to_write.seekp(0, ios::beg);
		char line[30];
		int count = 0;
		vector<string> attributes_2(number_of_attributes);
		try {
			while (file_to_read.read(line, 30))
			{
				attributes_2[count] = line;
				count++;
				if (count == number_of_attributes)
				{
					vector<string> attributes_1 = search_(attributes_2[0],path_of_database);
					if (attributes_1.size())
					{
						const char* str = attributes_1[num - 1].c_str();
						double value1 = stod(str);
						str = attributes_2[num - 1].c_str();
						double value2 = stod(str);
						switch (choice)
						{
						case 1:
							attributes_2[num - 1] = to_string(max(value1, value2));
							break;
						case 2:
							attributes_2[num - 1] = to_string(min(value1, value2));
							break;
						case 3:
							attributes_2[num - 1] = to_string(value1 + value2);
							break;
						case 4:
							attributes_2[num - 1] = to_string(value1 - value2);
							break;
						case 5:
							attributes_2[num - 1] = to_string((value1 + value2) / 2);
							break;
						default:
							break;
						}
						for (int i = 0; i < number_of_attributes; i++)
						{
							const char* str = attributes_2[i].c_str();
							char word[30];
							strcpy_s(word,sizeof(word), str);
							file_to_write.write(word, 30);
						}
					}
					else
					{
						for (int i = 0; i < number_of_attributes; i++)
						{
							const char* str = attributes_2[i].c_str();
							char word[30];
							strcpy_s(word,sizeof(word), str);
							file_to_write.write(word, 30);
						}
					}
					count = 0;
				}

			}
			file_to_read.close();
			ifstream file_to_read_2(path_of_database);
			file_to_read_2.seekg(0, ios::beg);
			count = 0;
			while (file_to_read_2.read(line, 30))
			{
	
				attributes_2[count] = line;
				count++;
				if (count == number_of_attributes)
				{
		
					vector<string> attributes_1 = search_(attributes_2[0],path2);
				
					if (attributes_1.size()==0)
					{
					
						for (int i = 0; i < number_of_attributes; i++)
						{
							const char* str = attributes_2[i].c_str();
							char word[30];
							strcpy_s(word,sizeof(word), str);
							file_to_write.write(word, 30);
						}
					}
					count = 0;
				}

			}
			cout << "Merged successfully \n";

		}
		catch (const exception &e)
		{
			cout << e.what() << "\n";
		}

	}
	//function 20
	void Display_merged_file()
	{
		system("cls");
		string path;
		cout << "\n Enter the path of the file \n";
		cin.ignore(200, '\n');
		getline(cin, path);
		ifstream file_to_read(path);
		display_attributes();
		file_to_read.seekg(0, ios::beg);
		char key[30];
		int count = 0;
		while (file_to_read.read(key, 30))
		{
			string word = key;
			count++;
			if (count == number_of_attributes)
			{
				if (word != "")
					cout << setiosflags(ios::left) << setw(30) << key << "\n";
				count = 0;
			}
			else
			{
				if (word != "")
					cout << setiosflags(ios::left) << setw(30) << key;
			}
		}
	}
};
#endif
#pragma once