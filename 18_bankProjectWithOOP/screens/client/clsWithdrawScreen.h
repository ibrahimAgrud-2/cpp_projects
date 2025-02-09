#ifndef CLSWITHDRAWSCREEN_H
#define CLSWITHDRAWSCREEN_H

#pragma once
#include <iostream>

using namespace std;

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{

private:
    static void _printClient(clsBankClient clinet)
    {
        cout << "\n Client Card:\n";
        cout << "____________________\n";
        cout << "\nFirstName   : " << clinet.firstName();
        cout << "\nLastName    : " << clinet.lastName();
        cout << "\nFull Name   : " << clinet.fullName();
        cout << "\nEmail       : " << clinet.email();
        cout << "\nPhone       : " << clinet.phone();
        cout << "\nAcc. Number : " << clinet.accountNumber();
        cout << "\nPassword    : " << clinet.pincCode();
        cout << "\nBalance     : " << clinet.accountBalance();
        cout << "\n___________________\n";
    }
    static string _readAccountNumber()
    {
        string accountNumbet = "";
        cout << "\nPleas enter Account number : ";
        accountNumbet = clsInputValidate::readString();
        return accountNumbet;
    }

public:
    static void showWithdrawScreen()
    {
        _drawScreenHeader("\t   Withdraw Screen");
        string accountNumber = _readAccountNumber();
        while (!clsBankClient::isClietnExist(accountNumber))
        {
            cout << "\nClient with [" << accountNumber << "] does not exist.\n";
            accountNumber = _readAccountNumber();
        }
        clsBankClient client = clsBankClient::find(accountNumber);
        _printClient(client);

        double amount = 0;

        
////7*-*----------------------
        char Answer = '*';
        do
        {
            Answer = '*';
            cout << "\nPleas Enter Withdraw amount : ";
            amount = clsInputValidate::readNumber<double>();
            if (amount > client.accountBalance())
            {

                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << amount;
                cout << "\nYour Balance is: " << client.accountBalance();

                cout << "\n\nDo you want to try again ? [Y/N]";
                cin >> Answer;
            }
        } while (toupper(Answer) == 'Y');

     
        
          if ((Answer) == '*')
        {

            char answer = 'Y';
            cout << "Are you sure you want to perform this transaction : [Y/N]";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {

                client.Withdraw(amount);
                cout << "\nAmount Withdraw successfully.\n";
                cout << "\nnew balance is : " << client.accountBalance();
            }
            else
            {
                cout << "\nOpertaion was cancelled.\n";
            }
        }
    }
};

#endif