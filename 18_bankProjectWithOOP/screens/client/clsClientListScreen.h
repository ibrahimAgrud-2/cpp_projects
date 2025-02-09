#ifndef CLSCLIENTLISTSCREEN_H
#define CLSCLIENTLISTSCREEN_H

#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

using namespace std;

class clsClientListScreen:protected clsScreen
{
private : 
static void _printClinetRecordLine(clsBankClient clinet)
{
cout << setw(8) << left << "" << "| " << setw(15) << left << clinet.accountNumber();
cout<<"| "<<setw(20)<<left<<clinet.fullName();
cout<<"| "<<setw(12)<<left<<clinet.phone();
cout<<"| "<<setw(20)<<left<<clinet.email();
cout<<"| "<<setw(10)<<left<<clinet.pincCode();
cout<<"| "<<setw(8)<<left<<clinet.accountBalance();

} 
public :
static void showClientList()
{

       if (!checkAccessRights(clsUser::enMainMenuePermissions::pListClients))
    {
        return ;// this will exit the function and it will not continue
    }
    
    vector<clsBankClient>vCLient=clsBankClient::getClientsList();
    string title="\t  Client List Screen";
    string Subtitle="\t  ("+to_string(vCLient.size())+") Client(s)";
   _drawScreenHeader(title,Subtitle);

           cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCLient.size()==0)
        {
            cout << "\t\t\t\tNo clinets Available In the System!";
        }
        else
        {
            for (clsBankClient i :vCLient)
            {
              _printClinetRecordLine(i);
              cout<<endl;
            }
            
        }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

}
};

#endif