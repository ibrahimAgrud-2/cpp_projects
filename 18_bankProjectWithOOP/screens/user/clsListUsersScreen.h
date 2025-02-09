#ifndef CLSLISTUSERSSCREEN_H
#define CLSLISTUSERSSCREEN_H

#pragma once

#include <iostream>
#include<iomanip>
using namespace std;

#include "clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"


class clsListUsersScreen:protected clsScreen
{
private : 
static void _printUserRecordLine(clsUser clinet)
{
cout << setw(8) << left << "" << "| " << setw(15) << left << clinet.userName();
cout<<"| "<<setw(25)<<left<<clinet.fullName();
cout<<"| "<<setw(12)<<left<<clinet.phone();
cout<<"| "<<setw(20)<<left<<clinet.email();
cout<<"| "<<setw(10)<<left<<clinet.password();
cout<<"| "<<setw(12)<<left<<clinet.permission();

} 
public :


static void showUserList()
{
    if (!checkAccessRights(clsUser::enMainMenuePermissions::pListClients))
    {
        return ;// this will exit the function and it will not continue
    }
    
    vector<clsUser>vCLient=clsUser::GetUsersList();
    string title="\t  User List Screen";
    string Subtitle="\t  ("+to_string(vCLient.size())+") User(s)";
   _drawScreenHeader(title,Subtitle);

           cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "User name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "permission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCLient.size()==0)
        {
            cout << "\t\t\t\tNo Users Available In the System!";
        }
        else
        {
            for (clsUser i :vCLient)
            {
              _printUserRecordLine(i);
              cout<<endl;
            }
            
        }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

}

};

#endif