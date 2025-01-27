#pragma once
#include<iostream>
#include <iomanip>
using namespace std;
#include"clsScreen.h"
#include"ClsBankClient.h"
#include"clsInputValidate.h"


class clsUpdateCLientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient clinet)
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
    static void _readClientInfo(clsBankClient& client)
    {
        cout << "\nEnter First name : ";
        client.setFirstName(clsInputValidate::readString());

        cout << "\nEnter Last name : ";
        client.setLastName(clsInputValidate::readString());

        cout << "\nEnter Email : ";
        client.setEmail(clsInputValidate::readString());

        cout << "\nEnter Phone: ";
        client.setPhone(clsInputValidate::readString());

        cout << "\nEnter Pincode : ";
        client.setPinCode(clsInputValidate::readString());

        cout << "\nEnter Account balance  : ";
        client.setAccountBalance(clsInputValidate::readDblNumber(""));
    }

public:
    static void showUpdateClientScreen()
    {

        _drawScreenHeader("\tUpdate Client Screen");

        string accountNumber = "";
        cout << "\nPleas Enter client Accout number : ";
        accountNumber = clsInputValidate::readString();
        while (!clsBankClient::isClietnExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);
        _PrintClient(client1);
        char answer = 'N';

        cout << "Are you sure you want to Update this client [Y/N] ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";
            _readClientInfo(client1);
            clsBankClient::enSaveResults saveRuseult;
            saveRuseult = client1.save();
            switch (saveRuseult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClient(client1);
                break;
            case clsBankClient::enSaveResults::svFaildAccountNumberExists:
                cout << "\nError account was not saved because it's Empty";
                break;
            default:
                cout << "We got Issue in showUpdateClientScreen() funciton \n";
                break;
            }
        }
    }

};

