#ifndef CLSFINDUSERSCREEN_H
#define CLSFINDUSERSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser user)
    {
        cout << "\n Client Card:\n";
        cout << "____________________\n";
        cout << "\nFirstName   : " << user.firstName();
        cout << "\nLastName    : " << user.lastName();
        cout << "\nFull Name   : " << user.fullName();
        cout << "\nEmail       : " << user.email();
        cout << "\nPhone       : " << user.phone();
        cout << "\nUser name   : " << user.userName();
        cout << "\npassword    : " << user.password();
        cout << "\npermission  : " << user.permission();
        cout << "\n___________________\n";
    }

public:
    static void showFindUserScreen()
    {
        _drawScreenHeader("\t  Find User Screen");
        string userName = "";
        cout << "\nPleas enter user name :\n";
        userName = clsInputValidate::readString();
        while (!clsUser::isUserExist(userName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::find(userName);
        if (!user1.isEmpty())
        {
           cout << "\nUser Found :-)\n";
        }
        else
        {
             cout << "\nUser not  Found :-(\n";
        }
        _PrintUser(user1);
    }
};

#endif