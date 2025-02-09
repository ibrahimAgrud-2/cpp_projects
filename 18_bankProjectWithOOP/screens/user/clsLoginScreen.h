#ifndef CLSLOGINSCREEN_H
#define CLSLOGINSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include"clsMainScreen.h"
#include "clsScreen.h"
#include"clsuser.h"
#include"clsInputValidate.h"
#include "clsAddNewClientScreen.h"
#include"global.h"
#include"clsDate.h"

class clsLoginScreen:protected clsScreen
{

private :
static bool _login()
{
    bool loginFailde=false;
    string username,password;
   
    
    do
    {
       if (loginFailde)
       {
       cout << "\nInvlaid Username/Password!\n\n";
       cout<<"You have to "<<sayac<< " Trial(s) to login.\n\n";  
       sayac--;
       }
       cout<<"Enter user name : ";
       username=clsInputValidate::readString();
         cout<<"Enter password : ";
       password=clsInputValidate::readString();
        currentUser=clsUser::find(username,password);
loginFailde=currentUser.isEmpty();
        
    } while (loginFailde&&sayac>0);
  
 if (!currentUser.isEmpty())
 {
     currentUser.registerLogIn();
 clsMainScreen::showMainMenue();
 sayac=2;
 }
 else
 {
  cout << "\nYour are Locked after 3 faild trails \n\n";
 }
 
}

public : 
static void showLoginScreen()
{
    system("cls");
    _drawScreenHeader("\t  Login Screen");
    _login();

}
};

#endif