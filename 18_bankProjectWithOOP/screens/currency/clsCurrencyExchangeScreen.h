#ifndef CLSCURRENCYEXCHANGESCREEN_H
#define CLSCURRENCYEXCHANGESCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clslistCurrenciesScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsCurrencyUpdateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{

    enum enCurrencyMenu
    {
        List = 1,
        Find = 2,
        Update = 3,
        CurrencyCalculator = 4,
        mainMenu = 6
    };
    static short _readMainMenueOption()
    {
        cout << setw(27) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short choice = clsInputValidate::readNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
        return choice;
    }
    static void _goBackToCurrencyMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        showCurrencyExchangeScreen();
    }

    static void _showListCurrencyScreen()
    {
      //  cout << "Currency list screen will be here\n";
      clslistCurrenciesScreen::showCurrenciesScreen();
    }
    static void _showFindCurrencyScreen()
    {
       // cout << "Find Currency Screen will be here\n";
     clsFindCurrencyScreen::showFindCurrencyScreen();
    }
    static void _showUpdateRateScreen()
    {
       // cout << "Update Rate Screen will be here\n";
    clsCurrencyUpdateScreen::showUpdateCurrencyScreen();
    }
    static void _showCurrencyCalculatorScreen()
    {
        //cout << "Currency calculator Screen will be here\n";
        clsCurrencyCalculatorScreen::showCurrencyCalculaterScreen();
    }

    static void _performCurrencyMenuOPtion(enCurrencyMenu currencyOPtion)
    {
        switch (currencyOPtion)
        {
        case List:
            system("cls");
            _showListCurrencyScreen();
            _goBackToCurrencyMenu();
            break;
        case Find:
            system("cls");
            _showFindCurrencyScreen();
            _goBackToCurrencyMenu();
            break;
        case Update:
            system("cls");
            _showUpdateRateScreen();
            _goBackToCurrencyMenu();
            break;

        case CurrencyCalculator:
            system("cls");
            _showCurrencyCalculatorScreen();
            _goBackToCurrencyMenu();
            break;
        case mainMenu:
            // do nothing main menu will handle it
            break;
        }
    }

public:
    static void showCurrencyExchangeScreen()
    {
        _drawScreenHeader("\tCurrency Exchange screen");
        system("cls");
        cout << setw(27) << left << "" << "_________________________________________________\n\n";
        cout << setw(37) << left << "" << "Currency Exchange Menu\n";
        cout << setw(27) << left << "" << "_________________________________________________\n\n";
        cout << setw(37) << left << "" << "[1] List Currencies\n";
        cout << setw(37) << left << "" << "[2] Find Currency\n";
        cout << setw(37) << left << "" << "[3] Update Rate\n";
        cout << setw(37) << left << "" << "[4] Currency Calculator\n";
        cout << setw(37) << left << "" << "[5] Main Menu\n";
        cout << setw(27) << left << "" << "_________________________________________________\n";
        _performCurrencyMenuOPtion((enCurrencyMenu)_readMainMenueOption());
    }
};

#endif