#ifndef CLSLISTCURRENCIESSCREEN_H
#define CLSLISTCURRENCIESSCREEN_H

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clslistCurrenciesScreen : protected clsScreen
{

private:
 static    void _printCurrency(clsCurrency currency)
    {

        cout << setw(8) << left << "" << "| " << left << setw(35) << currency.country();
        cout << "| " << left << setw(10) << currency.currencyCode();
        cout << "| " << left << setw(35) << currency.currencyname();
        cout << "| " << left << setw(10) << currency.rate();
    }

public:
    static void showCurrenciesScreen()
    {
        vector<clsCurrency> vCurrencies = clsCurrency::getCurrencyList();
        string title = "\tList Currencies Screen";
        string subtitle = "(" + to_string(vCurrencies.size()) + ") Currency";

        _drawScreenHeader(title, subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(35) << "Name";
        cout << "| " << left << setw(10) << "Rate";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vCurrencies.size() == 0)
        {
            cout << "Not available data in system\n";
        }
        else
        {
            for (clsCurrency C :vCurrencies)
            {
                
                _printCurrency(C);
                cout<<endl;
            }
            
        }
         cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n";
    }
};

#endif