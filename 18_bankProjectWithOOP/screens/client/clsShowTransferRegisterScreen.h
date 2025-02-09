#ifndef CLSSHOWTRANSFERREGISTERSCREEN_H
#define CLSSHOWTRANSFERREGISTERSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include "clsScreen.h"
#include"clsBankClient.h"

class clsShowTransferRegisterScreen : clsScreen
{

private:
    static void _printUsers(clsBankClient::stTransferRegisterRecord info)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << info.sDateAndTime;
        cout << "| " << setw(15) << left << info.accountNumberClient1;
        cout << "| " << setw(12) << left << info.accountNumberClinet2;
        cout << "| " << setw(12) << left << info.transferdAmount;
        cout << "| " << setw(12) << left << info.clinet1AccountBalance;
        cout << "| " << setw(12) << left << info.client2AccountBalance;
        cout << "| " << setw(12) << left << info.performedby;
    }

public:
    static void showTransferRegisterScreen()
    {
        vector<clsBankClient::stTransferRegisterRecord> vRegisterData=clsBankClient::getTransferRegisterlist();

        string title = "\tTransfer Log List Screen\n";
        string subTitle = "\t(" + to_string(vRegisterData.size()) + ") Record(s)\n";

        _drawScreenHeader(title, subTitle);
        //    cout << setw(8) << left << "" << "| " << setw(25) << left << info.sDateAndTime;
        // cout << "| " << setw(15) << left << info.accountNumberClient1;
        // cout << "| " << setw(12) << left << info.accountNumberClinet2;
        // cout << "| " << setw(20) << left << info.transferdAmount;
        // cout << "| " << setw(20) << left << info.clinet1AccountBalance; 
        // cout << "| " << setw(20) << left << info.client2AccountBalance;
        // cout << "| " << setw(20) << left << info.performedby;
        cout << setw(8) << left << "" << "____________________________________________________________________________________";
        cout << "_________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time";
        cout << "| " << setw(15) << left << "s.Acct";
        cout << "| " << setw(12) << left << "d.Acct";
        cout << "| " << setw(12) << left << "Amount";
        cout << "| " << setw(12) << left << "s.Balance";
        cout << "| " << setw(12) << left << "d.Balance";
        cout << "| " << setw(12) << left << "Performed by";
        cout << setw(8) << left << "" << "\t___________________________________________________________________________________";
        cout << "__________________________________\n\n";

        if (vRegisterData.size() == 0)
        {
            cout << "\t\t\tNot available Record in system\n\n";
        }
        else
        {
            for (clsBankClient::stTransferRegisterRecord C : vRegisterData)
            {
                _printUsers(C);
                cout << endl;
            }
           
        }
          cout << setw(8) << left << "" << "____________________________________________________________________________________";
        cout << "_________________________________\n\n";
    }
};

#endif