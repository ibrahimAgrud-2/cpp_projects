#ifndef CLSUPDATEUSERSCREEN_H
#define CLSUPDATEUSERSCREEN_H
#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{

private:
    static void _readUserInfo(clsUser &user)
    {
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

public:
    static void showUpdateUserScreen()
    {
  
    
        _drawScreenHeader("\tUpdate User Screen");
        string userName = "";
        cout << "\nPleas enter user name :\n";
        userName = clsInputValidate::readString();
        while (!clsUser::isUserExist(userName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            userName = clsInputValidate::readString();
        }
        clsUser user1 = clsUser::find(userName);
        _PrintUser(user1);
        cout << "\nAre you sure you want to update this User y/n? ";

        char answer = 'N';
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";
            _readUserInfo(user1);
            clsUser::enSaveResults saveResult;

            saveResult = user1.save();
            switch (saveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(user1);
                break;
            case clsUser::enSaveResults::svFaildEmptyOBject:
                cout << "\nError User was not saved because it's Empty";
                break;
            default:
                cout << "WE got issue in showUpdateUserScreen() \n ";
                system("pause>0");

                break;
            }
        }
    }
};

#endif