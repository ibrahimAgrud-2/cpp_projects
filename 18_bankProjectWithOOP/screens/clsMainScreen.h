#ifndef CLSMAINSCREEN_H
#define CLSMAINSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include "global.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clslogInRegisterListScreen.h"
#include "clsCurrencyExchangeScreen.h"


class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions
    {
        eListClient = 1,
        eAddNewClinet = 2,
        edeleteClient = 3,
        eUpdateClinet = 4,
        eFindClinet = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eShowRegisterLoginMenu = 8,
         eCurrencyExchange = 9,
        eExit = 10

    };

    static short _readMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short choice = clsInputValidate::readNumberBetween(1, 10, "Enter Number between 1 to 10 ? ");
        return choice;
    }
    static void _goBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        showMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::showClientList();
    }
    static void _showAddNewClientScreen()
    {
        // cout << "\nNew clinet screen will be here...\n";
        clsAddNewClientScreen::addNewClient();
    }
    static void _deleteClientScreen()
    {
        // cout << "\n Delete  clinet screen will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }
    static void _showUpdateClinetScreen()
    {
        // cout << "\n Update clinet screen will be here...\n";
        clsUpdateClientScreen::showUpdateClientScreen();
    }

    static void _showFindClinetScreen()
    {
        // cout << "\n Find clinet  screen will be here...\n";
        clsFindClientScreen::showFindClietScreen();
    }
    static void _showTransactionsMenu()
    {
        // cout << "\n Transactions Menu screen will be here...\n";
        clsTransactionsScreen::showTransactionsMenue();
    }
    static void _showManageUsersMenue()
    {
        //  cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::showManageUsersMenu();
    }

    // static void _showEndScreen()
    // {
    //     cout << "\n End screen will be here...\n";
    // }
    static void _showRegisterLoginMenu()
    {

        logInRegisterListScreen::showlogInRegisterListScreen();
    }
  static void _showCurrencyExchangeMenu()
    {

     //cout<<"Currency Exchange Menu will be here\n";
     clsCurrencyExchangeScreen::showCurrencyExchangeScreen();
         }

    static void _logOut()
    {
        currentUser = clsUser::find("", "");
        // then it will back to main menu screen
    }
    static void _performMainMenuOption(enMainMenuOptions MainMenueOtions)
    {
        switch (MainMenueOtions)
        {
        case eListClient:
            system("cls");
            _ShowAllClientsScreen();
            _goBackToMainMenu();
            break;
        case eAddNewClinet:
            system("cls");
            _showAddNewClientScreen();
            _goBackToMainMenu();
            break;
        case edeleteClient:
            system("cls");
            _deleteClientScreen();
            _goBackToMainMenu();
            break;
        case eUpdateClinet:
            system("cls");
            _showUpdateClinetScreen();
            _goBackToMainMenu();
            break;
        case eFindClinet:
            system("cls");
            _showFindClinetScreen();
            _goBackToMainMenu();
            break;
        case eShowTransactionsMenue:
            system("cls");
            _showTransactionsMenu();
            _goBackToMainMenu();
            break;
        case eManageUsers:
            system("cls");
            _showManageUsersMenue();
            _goBackToMainMenu();
            break;
        case eShowRegisterLoginMenu:
            system("cls");
            _showRegisterLoginMenu();
            _goBackToMainMenu();
            break;
              case eCurrencyExchange:
            system("cls");
            _showCurrencyExchangeMenu();
            _goBackToMainMenu();
            break;
        case eExit:
            system("cls");
            _logOut();

            break;
        default:
            cout << "We got issue function ---> _performMainMenuOption";
            system("pause>0");

            break;
        }
    }

public:
    static void showMainMenue()

    {

        system("cls");
        _drawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1]  Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2]  Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3]  Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4]  Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5]  Find Client.\n";
        cout << setw(37) << left << "" << "\t[6]  Transactions.\n";
        cout << setw(37) << left << "" << "\t[7]  Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8]  Show registered login menu.\n";
        cout << setw(37) << left << "" << "\t[9]  Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performMainMenuOption((enMainMenuOptions)_readMainMenueOption());
    }
};

#endif