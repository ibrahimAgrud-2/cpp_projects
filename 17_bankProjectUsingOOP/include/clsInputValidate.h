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
		return  (clsDate::IsDate1EqualDate2(from, dateTocheck) || clsDate::IsDate1EqualDate2(from, to));

	}
	static bool isValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}



	static bool isNumberBetween(int numberToCheck, int number1, int number2)
	{
		return (numberToCheck >= number1 && numberToCheck <= number2);
	}
	static bool isNumberBetween(short numberToCheck, short number1, short number2)
	{
		return (numberToCheck >= number1 && numberToCheck <= number2);
	}
	static bool isNumberBetween(double numberToCheck, double number1, double number2)
	{
		return (numberToCheck >= number1 && numberToCheck <= number2);
	}


	static int readIntNumber(string errorMesag = "Invalide enter an  intager number : ")
	{
		int intNumber = 0;
		cin >> intNumber;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << errorMesag;
			cin >> intNumber;
		}
		return (int)intNumber;
	}
	static int readIntNumberBetween(int from, int to, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int intNumber = readIntNumber();

		while (!(isNumberBetween(intNumber, from, to)))
		{
			cout << ErrorMessage;
			intNumber = readIntNumber();

		}
		return (int)intNumber;
	}
	



	static double readDblNumber(string errorMesag = "Error, enter a double number ")
	{
		double doubleNumber = 0;
		cin >> doubleNumber;
		while (cin.fail())
		{


			cin.clear();
			cin.ignore(100, '\n');
			cout << errorMesag << " : ";
			cin >> doubleNumber;
		}

		return doubleNumber;
	}
	static double readDblNumberBetween(double from, double to, string mesag = "Number is not within range, Enter again : ")
	{
		double intNumber = 0;

		do
		{

			cout << mesag;
			intNumber = readDblNumber("");

		} while (!isNumberBetween(intNumber, from, to));
		return intNumber;
	}

	static string readString()
	{
		string mesag = "";
		getline(cin >> ws, mesag);
		return mesag;
	}

};
