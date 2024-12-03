#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include"MyDateLib.h"

using namespace myDateFonc;
using namespace std;

/***************************************************
//                 proceed one by one
/***************************************************/


stDate decreasDateByOneDay(stDate date)
{
	if (date.days==1)
	{
		
		if (date.months==1)
		{
			date.months = 12;
			date.year--;
		
		}
		else
		{
			date.months--;
			
		}

		date.days = numberDaysInMounth(date.months, date.year);

	}
	else
	{
		date.days--;
	}
	return date;
}
stDate decreasDateByXDays(short numberOfDays,stDate date)
{
	for (short i = 0; i < numberOfDays; i++)
	{

		date = decreasDateByOneDay(date);


	}
	return date;

}
stDate decreasDayByOneWeek(stDate date)
{
	
		date = decreasDateByXDays(7, date);
	
	return date;

}
stDate decreasDayByXWeek
(short numberOfDays, stDate date)
{
	for (short i = 0; i < numberOfDays; i++)
	{
		date = decreasDayByOneWeek(date);
	}
	return date;
}


stDate decreasdayByOneMonth(stDate date)
{
	if (date.months==1)
	{
		date.year--;
		date.months = 12;

	}
	else
	{
		date.months--;
	}
	
	
	
	short nunmberOfdaysInCurrentMonth = numberDaysInMounth(date.months, date.year);

	if (date.days> nunmberOfdaysInCurrentMonth)
	{
		date.days = nunmberOfdaysInCurrentMonth;
	}
	return date;                                                                                                                                                   
}

stDate decreasDayXMonth
(short numberOfMonths,stDate date)
{
	for (short i = 0; i < numberOfMonths; i++)
	{
		date = decreasdayByOneMonth(date);
	} 
	return date;
}
stDate decreasDayByOneYear(stDate date)
{
	date.year--;
	return date;

}

stDate decreasDayByXYear(short numberOfYears, stDate date)
{
	for (short i = 0; i < numberOfYears; i++)
	{
		date = decreasDayByOneYear(date);
	}
	return date;
}
stDate decreasDayByXYearFaster(short numberOfYears, stDate date)
{
	date.year-= numberOfYears;
	return   date;

}
stDate decreasDayByOneDaecade(stDate date)
{
	date.year -= 10;
	return date;
}
stDate decreasDayByXDecade(short numberOfYears, stDate date)
{
	for (short i = 0; i < numberOfYears; i++)
	{
		date = decreasDayByOneDaecade(date);
	}
	return date;
}
stDate decreasDayByXDecadeFaster(short numberOfYears, stDate date)
{
	date.year -= numberOfYears * 10;
	return date;
}
stDate decreasDayByOneCentury(stDate date)
{
	date.year -=  100;
	return date;
}
stDate decreasDayByOneMillennium(stDate date)
{
	date.year -= 1000;
	return date;
}

int main()
{

	stDate date = readFullDate();

	cout << "Decreas date by one day is : ";
	date = decreasDateByOneDay(date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date by 10 days is : ";
	date = decreasDateByXDays(10,date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date by one week is : ";
	date = decreasDayByOneWeek(date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date by 10  weeks is : ";
	date = decreasDayByXWeek(10,date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date one   month is : ";
	date = decreasdayByOneMonth( date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date 5   months is : ";
	date = decreasDayXMonth(5,date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date one year is : ";
	date = decreasDayByOneYear(date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date 10 years is : ";
	date = decreasDayByXYear(10,date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date 10 years (faster) is : ";
	date = decreasDayByXYearFaster(10, date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date one decade is : ";
	date = decreasDayByOneDaecade(date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date 10 decades is : ";
	date = decreasDayByXDecade(10,date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date 10 decades(faster) is : ";
	date = decreasDayByXDecadeFaster(10, date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date one century is : ";
	date = decreasDayByOneCentury(date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;
	cout << "Decreas date one Millennium is : ";
	date = decreasDayByOneMillennium(date);
	cout << date.days << "/" << date.months << "/" << date.year << endl;






	
	//cout << date.days << "/" << date.months << "/" << date.year << endl;
	
	cout << endl;
	cout << endl;
	system("pause");
	
	return 0;
}


