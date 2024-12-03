Bank Management System

This project is a Bank Management System implemented in C++. It is designed to manage clients' data, including their account information, balances, and personal details. The system provides functionalities to add, update, delete, and retrieve client records.
Basic C++ Concepts Required

Before understanding this code, familiarity with the following C++ concepts is essential:

    File Handling
        Reading and writing files using fstream.
        Handling file input (ios::in), output (ios::out), and append modes (ios::app).

          Struct

            Structures (struct) to group related data.
        Enumerations (enum) to define constant options for menu navigation.

    Standard Template Library (STL)
        Using vector for dynamic arrays.
        Using string for text manipulation.
        iomanip for formatted output (e.g., setw for aligning data).

    Functions
        Defining and calling functions for modular programming.
        Passing parameters by reference (&) and value.

    Control Flow
        Loops (for, while, do-while) and conditionals (if-else, switch).

    Error Handling
        Checking file operations for success using is_open().
        Validating user input (e.g., checking if a client already exists).

    System Commands
        Using system("cls") to clear the screen (Windows-specific).
        Using system("pause>0") to pause the execution.

Features

    List All Clients
        Display a table of all stored client data with formatted output.

    Add New Client
        Add a new client while ensuring the account number is unique.

    Update Client Info
        Modify an existing client's details, such as name or account balance.

    Delete Client
        Mark a client for deletion and remove their data from the file.

    Find Client
        Retrieve and display a client’s details by their account number.

    File Persistence
        All client data is stored in the Clients.txt file to maintain persistence.

How to Use

    Compile and Run the Program
        Use a C++ compiler (e.g., g++) to compile the code:

g++ main.cpp -o BankManagementSystem

Run the program:

        ./BankManagementSystem

    Main Menu
        The program starts with a main menu offering the following options:
            [1] Show Client List.
            [2] Add New Client.
            [3] Delete Client.
            [4] Update Client Info.
            [5] Find Client.
            [6] Exit.

    File Structure
      ##  The program uses Clients.txt to store client data. Ensure this file is in the same directory as the executable.

Code Structure
Main Components

    Struct sClient
        Represents a client's data, including account number, PIN code, name, phone, balance, and a delete flag.

    Helper Functions
        SplitString: Splits a string based on a delimiter.
        ConvertLineToRecord and ConvertRecordToLine: For converting between string and sClient objects.

    Core Functionalities
        AddNewClient, DeleteClientByAccountNumber, UpdateClientByAccountNumber, FindClientByAccountNumber, and LoadClientsDataFromFile.

    Menu Handling
        ShowMainMenue, ReadMainMenueOption, and PerfromMainMenueOption.

⚠️ Important Notes ⚠️

To avoid errors during file operations, it is essential to initialize the Clients.txt file with the following format:

AccountNumber#//#PinCode#//#Name#//#Phone#//#AccountBalance

Example:

A152#//#123456#//#ismail#//#3423#//#56.000000

Customization:

If you wish to modify this format, you can adjust the implementation of the ConvertRecordToLine and ConvertLinetoRecord functions in the code to suit your preferred structure.
