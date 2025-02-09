#ifndef CLSDELETECLIENTSCREEN_H
#define CLSDELETECLIENTSCREEN_H

#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsUser.h"



class clsDeleteClientScreen:protected clsScreen
{
    private :

static void _PrintClinet(clsBankClient clinet)
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
    public :

    static void ShowDeleteClientScreen()
    {
		   if (!checkAccessRights(clsUser::enMainMenuePermissions::pDeleteClient))
    {
        return ;// this will exit the function and it will not continue
    }
    
		    _drawScreenHeader("\tDelete Client Screen");
        string accountNumber = "";
	cout << "\nPlease Enter Account Number: ";
	accountNumber = clsInputValidate::readString();

	
	while (!clsBankClient::isClietnExist(accountNumber))
	{
		cout << "\nAccount number is not found, choose another one: ";
		accountNumber = clsInputValidate::readString();
	}
	clsBankClient client1 = clsBankClient::find(accountNumber);
	_PrintClinet(client1);

	char answer = 'Y';
	cout << "\nAre you sure you want to delete this client y/n? ";
    cin>>answer;
	if (toupper(answer)=='Y')
	{
		if (client1.deleteClient())
		{
			 cout << "\nClient Deleted Successfully :-)\n";
           _PrintClinet(client1);
		}
		
	}
	 else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    
	


    }
};

#endif