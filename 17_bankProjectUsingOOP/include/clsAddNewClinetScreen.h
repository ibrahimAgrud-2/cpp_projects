#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>

using namespace std;
#include "ClsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsAddNewClinetScreen: protected clsScreen
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
    //buraya koyulur mu emin de�ilim ama static olmal� mutlaka
    static void readClientInfo(clsBankClient& client)
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

    //save nerede olur bilmiyorum ancak sonu�ta buras�da bir ekran ve save bence burda lolur
    static  void addNewClient()
    {
        // vector<clsBankClient> vCLient = clsBankClient::getClientsList();
        string title = "\t  Add New Client  Screen";

        _drawScreenHeader(title, "");
        string accountNumber = "";
        cout << "Plead Enter Acount Number :  ";
        accountNumber = clsInputValidate::readString();
        while (clsBankClient::isClietnExist(accountNumber))
        {
            cout << "\nAccount number is already Used, Choose another one : ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);

        readClientInfo(newClient);

        clsBankClient::enSaveResults saveResult;

        saveResult = newClient.save();

        switch (saveResult)
        {

        case clsBankClient::svFaildEmptyOBject:
            cout << "\n\n*Error account was not saved because it's Empty";
            break;
        case clsBankClient::svSucceeded:
            cout << "\n\n*the update process has been completed successfully = )\n";
            _PrintClinet(newClient);

            break;
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            cout << "\n\n*Error account was not saved because account number is used!\n";
            break;
        default:
            cout << "Error at  saveResult \n";
            system("pause>0");
            break;
        }
    }


};

