#ifndef CLSDEPOSITSCREEN_H
#define CLSDEPOSITSCREEN_H
#pragma once

#include <iostream>

using namespace std;

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDepositScreen:protected clsScreen
{
private :
  static void _printClient(clsBankClient clinet)
    {
       cout << "\n Client Card:\n";
		cout << "____________________\n";
		cout << "\nFirstName   : " << clinet.firstName();
		cout << "\nLastName    : " << clinet.lastName();
		cout << "\nFull Name   : " << clinet.fullName();
		cout << "\nEmail       : " << clinet.email();
		cout << "\nPhone       : " <<clinet.phone();
		cout << "\nAcc. Number : " << clinet.accountNumber();
		cout << "\nPassword    : " << clinet.pincCode();
		cout << "\nBalance     : " << clinet.accountBalance();
		cout << "\n___________________\n";

    }
static string _readAccountNumber()
{
    string accountNumbet="";
    cout<<"\nPleas enter Account number : ";
    accountNumbet=clsInputValidate::readString();
    return accountNumbet;
}
public :

static void showDepositScreen()
{
    _drawScreenHeader("\t   Deposit Screen");
   string accountNumber= _readAccountNumber();
   while (!clsBankClient::isClietnExist(accountNumber))
   {
     cout << "\nClient with [" << accountNumber << "] does not exist.\n";
            accountNumber= _readAccountNumber();
   }
   clsBankClient clinet1=clsBankClient::find(accountNumber);
   _printClient(clinet1);

   double amount=0;
   cout<<"\nPleas Enter deposit amount : ";
   amount=clsInputValidate::readNumber<double>();
char answer='Y';
cout<<"Are you sure you want to perform this transaction : [Y/N]";
cin>>answer;
if (toupper(answer)=='Y')
{
   clinet1.Deposit(amount);
   cout<<"\nAmount deposited successfully.\n";
   cout<<"\nnew balance is : "<<clinet1.accountBalance();

}
else
{
    cout<<"\nOpertaion was cancelled.\n";
}

}
};

#endif