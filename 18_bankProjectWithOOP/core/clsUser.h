#ifndef CLSUSER_H
#define CLSUSER_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include"clsUtil.h"

string userFileName = "vsUsers.txt";
class clsUser : public clsPerson
{
public:
    struct stLOginRegisterRecord
    {
        string sDateAndTime;
        string sUsernmae;
        string sPassword;
        int sPermissions;
    };


private:
    enum enMode
    {
        eEmptymode = 0,
        eUpdateMode = 1,
        eAddNewMode = 2
    };
    enMode _mode;
    string _userName;
    string _password;
    int _permissions;
    bool _markForDelete = false;
    // first class
    static clsUser _convertLineToUserObject(string line, string sperator = "#//#")
    {
        // Mohammed#//#Abu-Hadhoud#//#Mo@gmail.com#//#0799997886#//#A101#//#1234#//#5000.000000

        vector<string> vUserData = clsString::Split(line, sperator);
        return clsUser(enMode::eUpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], clsUtil::decryptStringWords(vUserData[5]), stoi(vUserData[6]));
    }
    static string 
    _ConvertUserObjecttoLine(clsUser user, string Seperator = "#//#")
    {
        string userRecord = "";
        userRecord = user.firstName() + Seperator;
        userRecord += user.lastName() + Seperator;
        userRecord += user.email() + Seperator;
        userRecord += user.phone() + Seperator;
        userRecord += user.userName() + Seperator;
        userRecord += clsUtil::encryptStringWords(user.password()) + Seperator;
        userRecord += to_string(user.permission());

        return userRecord;
    }
    static vector<clsUser> _loadUsersDataFromFile()
    {
        vector<clsUser> vUsers;

        fstream file;
        file.open(userFileName, ios::in);
        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {

                if (line == "")
                {
                    continue;
                }
                clsUser user = _convertLineToUserObject(line);
                vUsers.push_back(user);
            }
            file.close();
        }
        else
        {
            cout << "File could not open ---> Func.Name : _loadUsersDataFromFile \n";
            system("pause>0");
        }
        return vUsers;
    }
    static void _SaveUserDataToFile(vector<clsUser> vUsers)
    {
        fstream file;
        file.open(userFileName, ios::out);
        if (file.is_open())
        {
            string line = "";
            for (clsUser C : vUsers)
            {
                if (C.markForDelete() == false)
                {
                    // we only write records that are not marked for delete.
                    line = _ConvertUserObjecttoLine(C);
                    file << line << endl;
                }
            }
            file.close();
        }
        else
        {
            cout << "File could not open \n";
            system("pause>0");
        }
    }
    void _upDate()
    {
        vector<clsUser> vUsers;
        vUsers = _loadUsersDataFromFile();
        for (clsUser &C : vUsers)
        {
            if (C.userName() == _userName)
            {
                C = *this;
                break;
            }
        }
        _SaveUserDataToFile(vUsers);
    }
    void _addUserDataLineToFile(string line)
    {
        fstream file;
        file.open(userFileName, ios::out | ios::app);
        if (file.is_open())
        {
            file << line << endl;
            file.close();
        }
        else
        {
            cout << "File could not open ---> _addUserDataLineToFile() \n ";
            system("pause>0");
        }
    }
    string _prepareLogInRecord(string seperator = "#//#")
    {
        string line = clsDate::getSystemDateAsString() + " - ";
        line += clsDate::getSystemTimeAsString() + seperator;
        line += _userName + seperator;
        line += clsUtil::encryptStringWords(_password) + seperator;
        line += to_string(_permissions);
        return line;
    }
  
    void _addNew()
    {
        _addUserDataLineToFile(_ConvertUserObjecttoLine(*this));
    }
    static clsUser _getEmptyUserObject()
    {
        return clsUser(enMode::eEmptymode, "", "", "", "", "", "", 0);
    }

    static stLOginRegisterRecord _ConvertLoginRegisterLineToRecord(string line, string sperator = "#//#")
    {
        stLOginRegisterRecord registreLogin;
        vector<string> vString = clsString::Split(line, sperator);

        registreLogin.sDateAndTime = vString[0];
        registreLogin.sUsernmae = vString[1];
        registreLogin.sPassword = clsUtil::decryptStringWords(vString[2]);
        registreLogin.sPermissions = stoi(vString[3]);
        return registreLogin;
    }
   

public:
    enum enMainMenuePermissions
    {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClients = 8,
        pFindClient = 16,
        pTranactions = 32,
        pManageUsers = 64,
        pShowRegister = 128

    };
    clsUser(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permission) : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _userName = userName;
        _password = password;
        _permissions = permission;
    }

    bool isEmpty()
    {
        return (_mode == enMode::eEmptymode);
    }
    bool markForDelete()
    {
        return _markForDelete;
    }
    string userName()
    {
        return _userName;
    }
    void setUserName(string userName)
    {
        _userName = userName;
    }
    string password()
    {
        return _password;
    }
    void setPasswprd(string password)
    {
        _password = password;
    }
    static bool isUserExist(string userName)
    {
        clsUser clietn1 = clsUser::find(userName);
        return (!(clietn1.isEmpty()));
    }
    int permission()
    {
        return _permissions;
    }
    void setPermission(int permission)
    {
        _permissions = permission;
    }
    static clsUser GetAddNewUserObject(string userName)
    {

        return clsUser(eAddNewMode, "", "", "", "", userName, "", 0);
    }

    static clsUser find(string userName)
    {
        // Bu vector neden var bir en sona bir bak
        vector<clsUser> vClients;

        fstream file;
        file.open(userFileName, ios::in); // read mode
        if (file.is_open())
        {

            string line = "";
            while (getline(file, line))
            {
                if (line == "")
                {
                    break;
                }

                clsUser user = _convertLineToUserObject(line);

                if (user.userName() == userName)
                {
                    file.close();
                    return user;
                }

                vClients.push_back(user);
            }

            file.close();
        }
        else
        {
            cout << "File could not open in function  find(string userName)\n";
            system("pause>0");
        }
        return _getEmptyUserObject();
    }
    static clsUser find(string userName, string password)
    {
        // Bu vector neden var bir en sona bir bak
        vector<clsUser> vClients;

        fstream file;
        file.open(userFileName, ios::in); // read mode
        if (file.is_open())
        {

            string line = "";
            while (getline(file, line))
            {
                clsUser user = _convertLineToUserObject(line);
                if (user.userName() == userName && user.password() == password)
                {
                    file.close();
                    return user;
                }

                vClients.push_back(user);
            }

            file.close();
        }
        return _getEmptyUserObject();
    }

    enum enSaveResults
    {
        svFaildEmptyOBject = 0,
        svSucceeded = 1,
        svFaildUserExists = 2
    };
    enSaveResults save()
    {
        switch (_mode)
        {
        case enMode::eEmptymode:
            return enSaveResults::svFaildEmptyOBject;
        case enMode::eUpdateMode:

            _upDate();

            return enSaveResults::svSucceeded;
        case enMode::eAddNewMode:
        {
            // This will add new record to file or database
            if (clsUser::isUserExist(_userName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _addNew();

                // We need to set the mode to update after add new
                // the object still in the memory so we should update the mode
                _mode = enMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }

        default:
            cout << "We got error at save funciton \n ";
            system("puase>0");
            break;
        }
    }

    bool deleteUser()
    {
        vector<clsUser> vUser = _loadUsersDataFromFile();
        for (clsUser &i : vUser)
        {
            if (i.userName() == _userName)
            {
                i._markForDelete = true;
                break;
            }
        }

        _SaveUserDataToFile(vUser);
        // we should delete object from memory too
        *this = _getEmptyUserObject();
        return true;
    }
    static vector<clsUser> GetUsersList()
    {
        return _loadUsersDataFromFile();
    }

    bool CheckAccessPermission(enMainMenuePermissions Permission)
    {
        if (this->_permissions == enMainMenuePermissions::eAll)
            return true;

        if ((Permission & this->_permissions) == Permission)
            return true;
        else
            return false;
    }

    void registerLogIn()
    {
        string dataLine = _prepareLogInRecord();
        fstream file;
        file.open("loginRegister.txt", ios::out | ios::app);
        if (file.is_open())
        {
            file << dataLine << endl;
            file.close();
        }
        else
        {
            cout << "File could not open ---> registerLogIn() \n ";
            system("pause>0");
        }
    }

    static vector<stLOginRegisterRecord> getLoginRegisterlist()
    {
        vector<stLOginRegisterRecord> vLoginRegisterRecord;

        fstream file;
        file.open("loginRegister.txt", ios::in);
        if (file.is_open())
        {
            string line = "";
            stLOginRegisterRecord loginRegisterRecord;
            while (getline(file, line))
            {

                if (line == "")
                {
                    continue;
                }
                loginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);
                vLoginRegisterRecord.push_back(loginRegisterRecord);
            }
            file.close();
        }
        else
        {
            cout << "File could not open ---> Func.Name : getLoginRegisterlist\n";
            system("pause>0");
        }
        return vLoginRegisterRecord;
    }


  
};

#endif