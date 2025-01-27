#pragma once

#include<iostream>
#include <iomanip>
using namespace std;
#include"clsScreen.h"
#include"ClsBankClient.h"
#include"clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
{

private:

    static void _PrintClinet(clsBankClient clinet)
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


public:
    static void showFindClietScreen()
    {
      

        _drawScreenHeader("\tFind Client Screen");
        string accountNumber = "";
        cout << "Enter accunt number : ";
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClietnExist(accountNumber))
        {

            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient client1 = clsBankClient::find(accountNumber);
        if (!client1.isEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }
        _PrintClinet(client1);

    }

};

