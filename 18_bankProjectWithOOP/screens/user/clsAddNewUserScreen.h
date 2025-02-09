#ifndef CLSADDNEWUSERSCREEN_H
#define CLSADDNEWUSERSCREEN_H

#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
{

private:
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            Permissions += clsUser::enMainMenuePermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pManageUsers;
        }
             cout << "\nShow register screen? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enMainMenuePermissions::pShowRegister;
        }


        return Permissions;
    }

    static void _readUserInfo(clsUser &user)
    {

        // ismail #//#agrud#//#ismail@.com#//#86#//#admin2#//#1234#//#-1

        cout << "\nEnter First name : ";
        user.setFirstName(clsInputValidate::readString());

        cout << "\nEnter Last name : ";
        user.setLastName(clsInputValidate::readString());

        cout << "\nEnter Email : ";
        user.setEmail(clsInputValidate::readString());

        cout << "\nEnter Phone: ";
        user.setPhone(clsInputValidate::readString());

        cout << "\nEnter password : ";
        user.setPasswprd(clsInputValidate::readString());

        cout << "\nEnter permission  : ";
        user.setPermission(_ReadPermissionsToSet());
    }

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
    static void showAddNewUserScreen()
    {
        _drawScreenHeader("\t  Add New User Screen");
        string usernName = "";
        cout << "Plead Enter user name  :  ";
        usernName = clsInputValidate::readString();
        while (clsUser::isUserExist(usernName))
        {
            cout << "\nUser name is already Used, Choose another one : ";
            usernName = clsInputValidate::readString();
        }
        clsUser newUser = clsUser::GetAddNewUserObject(usernName);
        _readUserInfo(newUser);

        clsUser::enSaveResults saveResult;
        saveResult = newUser.save();

        switch (saveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(newUser);
            break;
        case clsUser::enSaveResults::svFaildEmptyOBject:
            cout << "\nError User was not saved because it's Empty";
            break;
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;
        }
        default:
            cout << "We got issue in showAddNewUserScreen\n";
            system("pause>0");

            break;
        }
    }
};

#endif