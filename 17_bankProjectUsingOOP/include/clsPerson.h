#pragma once 
#include<iostream>
using namespace std;


class clsPerson
{

private:
 
    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:

    clsPerson( string FirstName, string LastName, string Email, string Phone)
    {
       
        _firstName = FirstName;
        _lastName = LastName;
        _email = Email;
        _phone = Phone;
    }

 
    //Property Set
    void setFirstName(string FirstName)
    {
        _firstName = FirstName;
    }



    //Property Get
    string firstName()
    {
        return _firstName;
    }
    //Property Set
    void setLastName(string LastName)
    {
        _lastName = LastName;
    }

    //Property Get
    string lastName()
    {
        return _lastName;
    }
    //Property Set
    void setEmail(string Email)
    {
        _email = Email;
    }

    //Property Get
    string email()
    {
        return _email;
    }  
    
    //Property Set
    void setPhone(string Phone)
    {
        _phone = Phone;
    }

    //Property Get
    string phone()
    {
        return _phone;
    }
   
    string fullName()
    {
        return _firstName + " " + _lastName;
    }


 
};