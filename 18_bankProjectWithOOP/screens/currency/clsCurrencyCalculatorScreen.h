#ifndef CLSCURRENCYCALCULATORSCREEN_H
#define CLSCURRENCYCALCULATORSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
    static void _printCurrency(clsCurrency currency, string title = "*")
    {
        cout << "\n"
             << title << endl;
        cout << "_________________________________\n";
        cout << "\nCountry     : " << currency.country();
        cout << "\nCode        : " << currency.currencyCode();
        cout << "\nName        : " << currency.currencyname();
        cout << "\nRate(1$)    : " << currency.rate();
        cout << "\n_________________________________\n";
    }
    static string _readCurrencyCode()
    {
        string currencyCode = "";
        currencyCode = clsString::readString();
        while (!clsCurrency::isCurrencyExist(currencyCode))
        {
            cout << "Currency does not exist , enter another one : ";
            currencyCode = clsString::readString();
        }
        return currencyCode;
    }

    static clsCurrency _getCurrency(string mesag)
    {
        cout << mesag << endl;
        string currencyCode = _readCurrencyCode();
        return clsCurrency::findByCode(currencyCode);
    }

    static float _readAmount()
    {
        float amount = 0;
        cout << "\n\nEnter Amount to Exchange : ";
        amount = clsInputValidate::readNumber<float>();
        return amount;
    }
    
    static void _printCalculationResult(float amount, clsCurrency currency1, clsCurrency currency2)
    {
        _printCurrency(currency1, "Conver From : ");
        float amountInUSD = currency1.convertCurrencyToUSD(amount);
        cout << endl
             << amountInUSD << " " << currency1.currencyCode()
             << " = " << amountInUSD << " USD " << endl;

      if (currency2.currencyCode()!="USD")
      {
        _printCurrency(currency2,"To:");
        cout<<endl<<amount<<" "<<currency1.currencyCode()<<" = "<<currency1.convertToOtherCurrency(amount,currency2)<<" "<<currency2.currencyCode()<<endl;

      }
      
    }

public:
    static void showCurrencyCalculaterScreen()
    {

        char choise = 'Y';
        do
        {
            system("cls");
            _drawScreenHeader("\tCurrency Calculator");

            clsCurrency currency1 = _getCurrency("Pleas enter Currency1 code : ");
            clsCurrency currency2 = _getCurrency("\n\nPleas enter Currency2 code : ");

            float amount = _readAmount();
            _printCalculationResult(amount, currency1, currency2);

            cout << "\n\nDo you want to perform another calculation? [Y/N] ";
            cin >> choise;
        } while (toupper(choise) == 'Y');
    }
};

#endif