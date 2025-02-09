#ifndef CLSCURRENCYUPDATESCREEN_H
#define CLSCURRENCYUPDATESCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyUpdateScreen : protected clsScreen
{
private:
    static void _printCurrency(clsCurrency currency)
    {
        cout << "\nCurrency card:\n";
        cout << "_________________________________\n";
        cout << "\nCountry     : " << currency.country();
        cout << "\nCode        : " << currency.currencyCode();
        cout << "\nName        : " << currency.currencyname();
        cout << "\nRate(1$)    : " << currency.rate();
        cout << "\n_________________________________\n";
    }

    static string _readCurrencyCode()
    {

        string currencyCode = clsInputValidate::readString();
        return currencyCode;
    }

    static float _readNewRate()
    {

        float newRate = clsInputValidate::readNumber<float>();
        return newRate;
    }

public:
    static void showUpdateCurrencyScreen()
    {
        _drawScreenHeader("\tUpdate Currency Screen");

        cout << "Pleas enter currency code : ";
        string currencyCode = _readCurrencyCode();

        while (!clsCurrency::isCurrencyExist(currencyCode))
        {
            cout << "Currency does not exist, Enter another one :";
            string currencyCode = _readCurrencyCode();
        }
        clsCurrency currency1 = clsCurrency::findByCode(currencyCode);
        _printCurrency(currency1);

        char choise = 'N';
        cout << "\n\nAre you sure you want to update the rate of this currency [Y/N] ?";
        cin >> choise;
        if (toupper(choise) == 'Y')
        {
            cout << "Update Currency Rate : ";
            cout << "\n\n__________________\n\n";
            cout << "Enter the new rate : ";
            currency1.updateRate(_readNewRate());
            cout << "Rate updated successfully :-)\n";
            _printCurrency(currency1);
        }
        else
        {
            cout << "Update operation cancelled\n";
        }
    }
};

#endif