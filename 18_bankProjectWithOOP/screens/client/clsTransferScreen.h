#ifndef CLSTRANSFERSCREEN_H
#define CLSTRANSFERSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsTransferScreen : protected clsScreen
{

private:
    static void _printClinet(clsBankClient user)
    {
        cout << "\nClient Card :  \n";
        cout << "__________________________ \n\n";
        cout << "\nFull name : " << user.fullName();
        cout << "\nAcc. Number : " << user.accountNumber();
        cout << "\nBalance : " << user.accountBalance();
        cout << "\n__________________________ \n\n";
    }
    static string _readAccountNumber()
    {
        string accountNumber = "";
        accountNumber = clsInputValidate::readString();
        while (!clsBankClient::isClietnExist(accountNumber))
        {
            cout << "Account number [" << accountNumber << "] does not exist, Choes another one : ";
            accountNumber = clsInputValidate::readString();
        }
        return accountNumber;
    }
   

public:
    static void showTransferScreen()
    {

        _drawScreenHeader("\tTransfer Screen");
         string accountNumber = "";
        cout << "Pleas enter Account number to transfer from : ";
        accountNumber = _readAccountNumber();
        clsBankClient sourceClinet = clsBankClient::find(accountNumber);
        _printClinet(sourceClinet);

        cout << "Pleas enter Account number to transfer to : ";
        accountNumber = _readAccountNumber();
        clsBankClient destinationClinet = clsBankClient::find(accountNumber);
        _printClinet(destinationClinet);
        cout << "Pleas enter transfer amount : ";
        double amount = clsInputValidate::readNumber<double>();
        while (amount > sourceClinet.accountBalance())
        {
           cout<<"Amount exceeds the available balanc,Enter another Amount : ";
           amount = clsInputValidate::readNumber<double>();
        }
        char answer = 'N';
        cout << "Do you want to perfornm this operation :[Y/N]";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {

            if ( sourceClinet.transfer(destinationClinet, amount))
            {
               
                cout << "\nTransfer done successfully\n";
                 _printClinet(sourceClinet);
            _printClinet(destinationClinet);
            }
            else
            {
                cout<<"Transfer Faild\n";
            }
           
           
           
        }
        else
        {
            cout << "\nOpertaion was cancelled.\n";
        }
    }
};

#endif