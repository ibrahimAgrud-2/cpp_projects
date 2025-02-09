#ifndef CLSTOTALBALANCESSCREEN_H
#define CLSTOTALBALANCESSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _printClinetRecordBalanceLine(clsBankClient clinet)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << clinet.accountNumber();
        cout << "| " << setw(40) << left << clinet.fullName();
        cout << "| " << setw(12) << left << clinet.accountBalance();
    }

public:
    static void showTotalBalances()
    {
        vector<clsBankClient> vClient = clsBankClient::getClientsList();
        string title = "\t  Balances List Screen";
        string subtitle = "\t         (" + to_string(vClient.size()) + ")";
        _drawScreenHeader(title, subtitle);
       
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n"
             << endl;
        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t_____________________________________________________";
        cout << "__________________________\n"
             << endl;
        double totalBalances = clsBankClient::getTotalBalances();
        if (vClient.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else
        {
            for (clsBankClient C : vClient)
            {
                _printClinetRecordBalanceLine(C);
                cout << endl;
            }
        }
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n"
             << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\tTotal Balances = " << totalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t ( " << clsUtil::NumberToText(totalBalances) << ")";
    }
};

#endif