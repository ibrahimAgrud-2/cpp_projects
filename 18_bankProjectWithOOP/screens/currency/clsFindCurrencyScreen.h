#ifndef CLSFINDCURRENCYSCREEN_H
#define CLSFINDCURRENCYSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static string _readCountryName()
    {
        string counrtyName = "";
        cout << "Pleas enter the country name : ";
        counrtyName = clsInputValidate::readString();
        return counrtyName;
    }
    static string _readCurrencyCode()
    {
        string currencyCode = "";
        cout << "Pleas Enter The Currency  Code : ";
        currencyCode = clsInputValidate::readString();
        return currencyCode;
    }

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
    static void _showResult(clsCurrency currency)
    {
        if (currency.isEmpty())
        {
            cout << "\nCurrency Not Found :-(\n";
        }
        else
        {
            cout << "\nCurrency  Found :-)\n";
            _printCurrency(currency);
        }
    }

public:
    static void showFindCurrencyScreen()
    {
        _drawScreenHeader("\nFind Currency Screen");

        cout << "Find By : [1] Code [2] Country ?";
        short choise = clsInputValidate::readNumberBetween(1, 2);

        if (choise == 1)
        {
            string currencyCode = _readCurrencyCode();
            clsCurrency currency1 = clsCurrency::findByCode(currencyCode);
            _showResult(currency1);
        }
        else if (choise == 2)
        {
            string countryName = _readCountryName();
            clsCurrency currency2 = clsCurrency::findByCountry(countryName);
            _showResult(currency2);
        }
    }
};

#endif