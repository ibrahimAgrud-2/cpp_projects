Bank Management System - README

This project is an enhanced version of the previous BankProject. To fully grasp the functionality of this system, it is recommended to review the earlier version first.
Prerequisites

Before diving into this project, ensure you have a solid understanding of Bitwise Operations in C++. Without this knowledge, the logic behind certain functionalities may be challenging to comprehend.
Suggested Resources on Bitwise Operations

    Bitwise Operators Explained (Video 1)
    Understanding Bitwise Operations (Video 2)
    Practical Bitwise Applications (Video 3)
    Deep Dive into Bitwise Logic (Video 4)

Features Overview
Previous Features:

    Show Clients.
    Add New Client.
    Delete Client.
    Update Client.
    Find Client.
    Transactions.
    Exit.

Newly Added Features:

    Show Clients.
    Add New Client.
    Delete Client.
    Update Client.
    Find Client.
    Transactions.
    Manage Users.
    Logout.

Key Enhancement: Manage Users

With the addition of the Manage Users feature, the system now incorporates the concept of Users alongside Clients. Users and Clients are handled as separate entities, each with their own data files. Users can only access the operations specified for them in the User Permissions file.
User Permissions System:

    Each user has a defined permission level.
    Permissions determine which functions a user can access.
    For example:
        An Admin has full access to all functionalities, including managing users and clients.
        A regular User might only have access to Show Clients and Find Client.
    The Admin assigns these permissions during user creation.

System Workflow

    Login Screen:
        Users must log in with a username and password.
        Incorrect credentials result in a loop until valid inputs are provided.

    Main Menu:
        Once logged in, users are presented with the menu options available to their permission level.

    Manage Users Menu:
    Accessible only to Admins, this menu offers:
        List Users
        Add New User
        Delete User
        Update User
        Find User
        Return to Main Menu

User Permission Encoding

When adding a new user, the system prompts the Admin to specify access for each Main Menu option (Yes/No). Permissions are encoded as a binary value using Bitwise operations.
Example:

A user (user1) has access only to Show Clients and Find Client.

    This results in a permission level of 17 (in binary: 10001).
    The system stores this information in the following format:

    username#//#password#//#permission_level

Sample Entry:

user1#//#23456#//#17  

Customization Options

You can modify the file formats or logic according to your needs by adjusting relevant functions like ConvertRecordToLine and ConvertLinetoRecord.
Default Client File Format:

AccountNumber#//#PinCode#//#Name#//#Phone#//#AccountBalance  

Default User File Format:

username#//#password#//#permission_level  

Feel free to adapt these formats to suit your specific requirements.
Final Notes

This system combines client management with user access control for enhanced flexibility and security. By leveraging Bitwise operations, it ensures efficient permission handling while maintaining scalability for future enhancements.