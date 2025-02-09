#ifndef CLSTRANSACTIONSSCREEN_H
#define CLSTRANSACTIONSSCREEN_H

#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include"clsShowTransferRegisterScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions
    {
        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eTransfer = 4,
        eShowTransferLog = 5,
        eShowMainMenue = 6
    };
    static short _readTransactiionMenueOption()
    {
        cout << setw(37) << left << "" << "choose what do you wabt to do ? [1 to 6]?";
        short choise = clsInputValidate::readNumberBetween(1, 6, "Enter number between 1 to 6 ?");
        return choise;
    }
    static void _showDepositScreen()
    {
        // cout << "Deposit screen will be here ";
        clsDepositScreen::showDepositScreen();
    }

    static void _showWithdrawScreen()
    {
        // cout << "Withdraw screen will be here ";
        clsWithdrawScreen::showWithdrawScreen();
    }

    static void _showTotalBalanceScreen()
    {
        clsTotalBalancesScreen::showTotalBalances();
    }

    static void _goBackToTransactionMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        showTransactionsMenue();
    }

    static void _showTransferLogScreen()
    {
       // cout << "Transfer register login screen will be here\n";
    clsShowTransferRegisterScreen::showTransferRegisterScreen();
    }

    static void _showTransferScreen()
    {
        clsTransferScreen::showTransferScreen();
    }

    static void _performTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _showDepositScreen();
            _goBackToTransactionMenu();
            break;
        }
        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _showWithdrawScreen();
            _goBackToTransactionMenu();
            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _showTotalBalanceScreen();
            _goBackToTransactionMenu();
            break;
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _showTransferScreen();
            _goBackToTransactionMenu();
            break;
        }
        case enTransactionsMenueOptions::eShowTransferLog:
        {
            system("cls");
            _showTransferLogScreen();
            _goBackToTransactionMenu();
            break;
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {
            // do nothing here main menu will handle it
            break;
        }
        default:
        {
            cout << "We got Issue in _performTransactionsMenueOption \n";
            system("pause>0");
            break;
        }
        }
    }

public:
    static void showTransactionsMenue()
    {
        if (!checkAccessRights(clsUser::enMainMenuePermissions::pTranactions))
        {
            return; // this will exit the function and it will not continue
        }

        system("cls");
        _drawScreenHeader("\t Transactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Trasfer lg..\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _performTransactionsMenueOption((enTransactionsMenueOptions)_readTransactiionMenueOption());
    }
};

#endif