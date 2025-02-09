#ifndef CLSDELETEUSERSCREEN_H
#define CLSDELETEUSERSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsDeleteUserScreen: protected clsScreen
{
private :
  static void _PrintUser(clsUser user)
    {
        cout << "\n Client Card:\n";
        cout << "____________________\n";
        cout << "\nFirstName   : " << user.firstName();
        cout << "\nLastName    : " << user.lastName();
        cout << "\nFull Name   : " << user.fullName();
        cout << "\nEmail       : " << user.email();
        cout << "\nPhone       : " << user.phone();
        cout << "\nUser name   : " << user.userName();
        cout << "\npassword    : " << user.password();
        cout << "\npermission  : " << user.permission();
        cout << "\n___________________\n";
    }
public :
static void ShowDeleteUserScreen()
    {
		    _drawScreenHeader("\tDelete User Screen");
        string accountNumber = "";
	cout << "\nPlease Enter User name : ";
	accountNumber = clsInputValidate::readString();

	
	while (!clsUser::isUserExist(accountNumber))
	{
		cout << "\nUser name is not found, choose another one: ";
		accountNumber = clsInputValidate::readString();
	}
	clsUser user = clsUser::find(accountNumber);
	_PrintUser(user);

	char answer = 'Y';
	cout << "\nAre you sure you want to delete this user y/n? ";
    cin>>answer;
	if (toupper(answer)=='Y')
	{
		if (user.deleteUser())
		{
			 cout << "\nuser Deleted Successfully :-)\n";
           _PrintUser(user);
		}
		
	}
	 else
        {
            cout << "\nError user Was not Deleted\n";
        }
    
	


    }
};
#endif