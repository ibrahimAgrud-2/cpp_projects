#ifndef CLSMANAGEUSERSSCREEN_H
#define CLSMANAGEUSERSSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include "clsInputValidate.h"
#include"clsScreen.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManageUsersScreen:protected clsScreen
{
private:
    enum enManageusersManuOption
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenue = 6

    };
    static short _readManageusersManuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do : [1 to 6] ";
        short choise = clsInputValidate::readNumberBetween(1, 6, "Enter number between 1 to 6 : ");
        return choise;
    }
    static void _goBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to manager users menu...";
        system("pause>0");
        showManageUsersMenu();
    }
    static void _showListUsersScreen()
    {
       
      clsListUsersScreen::showUserList();
    }
    static void _showAddNewUserScreen()
    {
      //  cout << " Add new client screen  will be here.\n";
      clsAddNewUserScreen::showAddNewUserScreen();
    }
    static void _showDeleteUserScreen()
    {
        //cout << "Delete user screen will be here.\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }
    static void _showUpdateUserScreen()
    {
        //cout << "Update user screen will be here.\n";
        clsUpdateUserScreen::showUpdateUserScreen();
    }
    static void _showFindUserScreen()
    {
      //  cout << "Find user screen will be here.\n";
      clsFindUserScreen::showFindUserScreen();
    }
    static void _performManageUsersMenuOption(enManageusersManuOption ManageusersManuOption)

    {
        switch (ManageusersManuOption)
        {
        case enManageusersManuOption::eListUsers:
        {
            system("cls");
            _showListUsersScreen();
            _goBackToManageUsersMenu();
            break;
        }
        case enManageusersManuOption::eAddNewUser:
        {
            system("cls");
            _showAddNewUserScreen();
            _goBackToManageUsersMenu();
            break;
        }
        case enManageusersManuOption::eDeleteUser:
        {
            system("cls");
            _showDeleteUserScreen();
            _goBackToManageUsersMenu();
        }

        break;
        case enManageusersManuOption::eUpdateUser:
        {
            system("cls");
            _showUpdateUserScreen();
            _goBackToManageUsersMenu();
        }
        break;
        case enManageusersManuOption::eFindUser:
        {
            system("cls");
            _showFindUserScreen();
            _goBackToManageUsersMenu();
        }
        break;
        case enManageusersManuOption::eMainMenue:
        {
            // do nothing here the main screen will handle it
        }
        break;
        default:
        {

            cout << "We got Issue in _performManageUsersMenuOption \n";
            system("pause>0");
            break;
        }
        break;
        }
    }

public :
 static void showManageUsersMenu()
 {
       if (!checkAccessRights(clsUser::enMainMenuePermissions::pManageUsers))
    {
        return ;// this will exit the function and it will not continue
    }
    
    system("cls");
    _drawScreenHeader("\t Manage Users Screen");
         cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
 _performManageUsersMenuOption((enManageusersManuOption)_readManageusersManuOption());

 }
};

#endif