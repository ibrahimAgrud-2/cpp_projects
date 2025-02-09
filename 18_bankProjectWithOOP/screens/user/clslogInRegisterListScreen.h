#ifndef LOGINREGISTERLISTSCREEN_H
#define LOGINREGISTERLISTSCREEN_H

#pragma once
#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

#include "clsScreen.h"
#include"clsUser.h"


class logInRegisterListScreen :protected clsScreen
{
    private:
    static void _printUsers(clsUser::stLOginRegisterRecord user)
    {
;
        cout << setw(8) << left << "" << "| " << setw(25) << left << user.sDateAndTime;
cout<<"| "<<setw(15)<<left<<user.sUsernmae;
cout<<"| "<<setw(12)<<left<<user.sPassword;
cout<<"| "<<setw(20)<<left<<user.sPermissions;

    }
public:

static void showlogInRegisterListScreen()
{  
if (!checkAccessRights(clsUser::enMainMenuePermissions::pShowRegister))
{
 return;
}



vector<clsUser::stLOginRegisterRecord>vUsers=clsUser::getLoginRegisterlist();


    string title="\t   Login Register List Screen";
    string subTitle="\t\t("+to_string(vUsers.size())+") Record(s)";

    _drawScreenHeader(title,subTitle);

    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(12) << "Password";
    
        cout << "| " << left << setw(20) << "permission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    if (vUsers.size()==0)
    {
        cout<<"No availble users in system \n";
    }
    else
    {
      for (clsUser::stLOginRegisterRecord C:vUsers)
      {
       _printUsers(C);
       cout<<endl;
      }
      
    }
      cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

}
};

#endif