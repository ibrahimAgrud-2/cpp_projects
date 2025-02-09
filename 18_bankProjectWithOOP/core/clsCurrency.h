#ifndef CLSCURRENCY_H
#define CLSCURRENCY_H

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "clsString.h"

class clsCurrency
{

private:
    enum enMode
    {
        emptyMode = 0,
        updateMode = 1
    };
    enMode _Mode;

    string _country;
    string _currencyCode;
    string _currencyName;
    float _rate;

    static string _convertCurrencyObjectToLine(clsCurrency currency,string separator = "#//#")
    {
        string dataLine = "";
        dataLine += currency.country()+separator;
        dataLine += currency.currencyCode()+separator;
        dataLine += currency.currencyname()+separator;
        dataLine += to_string(currency.rate());
        return dataLine;
    }
    static clsCurrency _convrtLinetToCurrencyObject(string line, string separator = "#//#")
    {
        vector<string> vCurrencyData = clsString::Split(line, separator);

        return clsCurrency(enMode::updateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
    }

    static vector<clsCurrency> _loadCurrencyDataFromFile()
    {
        vector<clsCurrency> Vcurrency;

        fstream file;
        file.open("Currencies.txt", ios::in);
        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {

                if (line == "")
                {
                    continue;
                }
                clsCurrency currency = _convrtLinetToCurrencyObject(line);
                Vcurrency.push_back(currency);
            }
            file.close();
        }
        else
        {
            cout << "File could not open ---> Func.Name : _loadCurrencyDataFromFile \n";
            system("pause>0");
        }
        return Vcurrency;
    }

    static void _SaveCurrencyDataToFile(vector<clsCurrency> vClient)
    {
        fstream file;
        file.open("Currencies.txt", ios::out);
        if (file.is_open())
        {
            string line = "";
            for (clsCurrency C : vClient)
            {

                line = _convertCurrencyObjectToLine(C);
              
                file << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "File could not open  _SaveCurrencyDataToFile \n";
            system("pause>0");
        }
    }

    void _update()
    {
        vector<clsCurrency> vCurrency = _loadCurrencyDataFromFile();
        for (clsCurrency &C : vCurrency)
        {
            if (C.currencyCode() == currencyCode())
            {
                C = *this;
                break;
            }
            
        }
        _SaveCurrencyDataToFile(vCurrency);
    }
    static clsCurrency _getEmptyCurrencyObject()
    {
        return clsCurrency(enMode::emptyMode, "", "", "", 0);
    }

public:
    clsCurrency(enMode mode, string country, string currencycode, string currencyName, float rate)
    {
        _Mode = mode;
        _country = country;
        _currencyCode = currencycode;
        _currencyName = currencyName;
        _rate = rate;
    }

    string country()
    {
        return _country;
    }
    string currencyCode()
    {
        return _currencyCode;
    }
    string currencyname()
    {
        return _currencyName;
    }
    float rate()
    {
        return _rate;
    }
    void updateRate(float rate)
    {
        _rate = rate;
        _update();
    }

    bool isEmpty()
    {
        return (_Mode == enMode::emptyMode);
    }

    static clsCurrency findByCode(string currencyCode)
    {
        // Bu vector neden var bir en sona bir bak
        vector<clsCurrency> Vcurrency;

        fstream file;
        file.open("Currencies.txt", ios::in); // read mode
        if (file.is_open())
        {

            string line = "";
            while (getline(file, line))
            {
                clsCurrency currency = _convrtLinetToCurrencyObject(line);
                if (clsString::UpperAllString(currency.currencyCode()) == clsString::UpperAllString(currencyCode))
                {
                    file.close();
                    return currency;
                }

               
            }

            file.close();
        }
        return _getEmptyCurrencyObject();
    }

    static clsCurrency findByCountry(string country)
    {
        // Bu vector neden var bir en sona bir bak
        country=clsString::UpperAllString(country);

      
        fstream file;
        file.open("Currencies.txt", ios::in); // read mode
        if (file.is_open())
        {

            string line = "";
            while (getline(file, line))
            {
                clsCurrency currency = _convrtLinetToCurrencyObject(line);
                if (clsString::UpperAllString(currency.country())==country)
                {
                    file.close();
                    return currency;
                }

                
            }

            file.close();
        }
        return _getEmptyCurrencyObject();
    }

static bool isCurrencyExist(string currencyCode)
{
clsCurrency C1=clsCurrency::findByCode(currencyCode);
return (!C1.isEmpty());
}

static vector<clsCurrency> getCurrencyList()
{
    return _loadCurrencyDataFromFile();
}

float convertCurrencyToUSD(float amount)
{
    
return (float)(amount/_rate);
}

 float convertToOtherCurrency(float amount,clsCurrency currency)
{
    float amountInUsd=convertCurrencyToUSD(amount);
    if (currency.currencyCode()=="USD")
    {
       return amountInUsd;
    }
    
return (float)(amount*currency.rate());

}

};

#endif