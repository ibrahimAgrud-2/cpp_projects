#ifndef CLSSCREEN_H
#define CLSSCREEN_H

#pragma once
#include <iostream>
#include "clsUser.cpp"
#include "global.h"
#include"clsDate.cpp"


using namespace std;
class clsScreen
{
protected:
        static void _drawScreenHeader(string Title, string SubTitle = "")
        {
                cout << "\t\t\t\t\t______________________________________";
                cout << "\n\n\t\t\t\t\t  " << Title;
                if (SubTitle != "")
                {
                        cout << "\n\t\t\t\t\t  " << SubTitle;
                }
clsDate date1;
                cout << "\n\t\t\t\t\t______________________________________\n\n";
                cout << "\n\t\t\t\t\tUser : "<<currentUser.userName()<<endl;
                 cout << "\n\t\t\t\t\tDate : ";
                cout <<date1.day()<<"/"<<date1.month()<<"/"<<date1.year()<<endl<<endl;


        }

        static bool checkAccessRights(clsUser::enMainMenuePermissions permission)
        {
                if (!currentUser.CheckAccessPermission(permission))
                {
                        cout << "\t\t\t\t\t______________________________________";
                        cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
                        cout << "\n\t\t\t\t\t______________________________________\n\n";
                        return false;
                }
                else
                {
                        return true;
                }
        }
};

#endif