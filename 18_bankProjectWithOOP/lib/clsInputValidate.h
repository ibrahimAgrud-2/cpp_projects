#ifndef CLSINPUTVALIDATE_H
#define CLSINPUTVALIDATE_H

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

using namespace std;


class clsInputValidate
{

public:
	static bool isDateBetween(clsDate dateTocheck, clsDate from, clsDate to)
	{
		if (clsDate::IsDate1AfterDate2(from, to))
		{
			clsDate::swapDates(from, to);
		}
		if ((clsDate::IsDate1BeforeDate2(from, dateTocheck) && clsDate::IsDate1BeforeDate2(dateTocheck, to)))
		{
			return true;
		}
		return (clsDate::IsDate1EqualDate2(from, dateTocheck) || clsDate::IsDate1EqualDate2(from, to));
	}
	static bool isValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}



	template <typename t>t 
	static readNumber(string errorMesag="Enter a number")
	{
		t number ;
		cin >> number;
		while (cin.fail())
		{

			cin.clear();
			cin.ignore(100, '\n');
			cout << errorMesag << " : ";
			cin >> number;
		}

		return number;
	}

	template <typename t>
	t static isNumberBetween(t numberToCheck, t number1, t number2)
	{
		return (numberToCheck >= number1 && numberToCheck <= number2);
	}

	template <typename t>
	t static readNumberBetween(t from, t to, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		t Number = readNumber<t>();

		while (!(isNumberBetween(Number, from, to)))
		{
			cout << ErrorMessage;
			Number = readNumber<t>();
		}
		return Number;
	}


	static string readString()
	{
		string toRead = "";
		getline(cin >> ws, toRead);
		return toRead;
	}
};

#endif
