# Database Management System (DBMS)

## Overview
This project implements a Database Management System (DBMS) from scratch using C++. It enables users to manage folders and files, as well as perform operations on a fixed-length file-based database. Key functionalities include creating, moving, renaming, and deleting folders and files, along with inserting, updating, deleting, and retrieving database records.

## Table of Contents
- [Features](#features)
  - [Folder Operations](#folder-operations)
  - [File Operations](#file-operations)
  - [Database Operations](#database-operations)
- [Installation](#installation)
- [Usage](#usage)

## Features

### Folder Operations
- **Create**: Create a new folder at a specified path.
- **Rename**: Rename an existing folder.
- **Move**: Move a folder to a new location.
- **Delete**: Remove a specified folder.
- **Count**: Count the number of folders in a directory.
- **List**: Display all folders in a specified directory.

### File Operations
- **Move**: Move a file to a new location.
- **Rename**: Rename an existing file.
- **Copy**: Copy a file to a specified location.
- **Delete**: Remove a specified file.
- **List All**: Display all files in a directory.
- **List by Extension**: List files with a specific extension.
- **Count**: Count the number of files in a directory.

### Database Operations
- **Create**: Create a new database and define its attributes.
- **Open**: Open an existing database.
- **Insert**: Add a new record to the database.
- **Update**: Modify an existing record.
- **Delete**: Remove a record by its key.
- **Retrieve**: Retrieve a record by its key.
- **Display All**: Show all records in the database.
- **Filter**: Filter records based on specific criteria.
- **Sort**: Sort records by a specified attribute.
- **Encrypt/Decrypt**: Encrypt and decrypt database files.
- **Convert**: Convert the database into an HTML file.

## Installation

To set up the Database Management System on your local machine, follow these steps:

### Prerequisites:
1. Ensure you have a C++ compiler installed (e.g., Visual Studio, g++, clang).
2. Ensure Git is installed to clone the repository.
3. Optionally, use an Integrated Development Environment (IDE) like **Visual Studio**, **Code::Blocks**, or **CLion** to edit and run the code.

### Steps to Install:
1. **Clone the Repository**:
   - Open your terminal (or command prompt) and run the following command to clone the project repository to your local machine:
   ```bash
   git clone https://github.com/hazem2211/DMS.git
   ```

2. **Navigate to the Project Directory**:
   - Change your current directory to the newly cloned project folder:
   ```bash
   cd <project-directory>
   ```

3. **Open the Project in an IDE**:
   
   #### Using Visual Studio:
   1. Open **Visual Studio**.
   2. Go to **File > Open > Project/Solution** and navigate to the folder containing the cloned project.
   3. Open the C++ source file(s) (e.g., `main.cpp`).
   4. Press **Ctrl + Shift + B** to build the project.
   5. Once the build is successful, press **Ctrl + F5** to run the application.

   #### Using Code::Blocks:
   1. Open **Code::Blocks**.
   2. Go to **File > Open** and navigate to the folder containing the source file (e.g., `main.cpp`).
   3. Compile and run the code using the IDE's built-in tools.

   #### Using CLion:
   1. Open **CLion**.
   2. Select **Open** and choose the project directory.
   3. CLion will automatically detect the CMake configuration.
   4. Click on **Build** to compile the project, and use **Run** to execute the application.

4. **Run the Application**:
   - Once the build is successful, run the program using the IDE's execution command (e.g., **Ctrl + F5** in Visual Studio).

### Usage
1. Run the application.
2. Follow the on-screen menu to perform various operations.

