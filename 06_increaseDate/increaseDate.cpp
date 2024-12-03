#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

struct stDate
{
	int year;
	int months;
	int days;

};
int readYear()
{
	int num;
	cout << "enter a Year\n";
	cin >> num;
	return   num;
}
int ReadDay()
{
	short Day;
	cout << "enter a Day\n";
	cin >> Day;
	return Day;
}
int readMounth()
{
	int num;
	cout << "enter a Mounth\n";
	cin >> num;
	return num;
}
int readDaysToAdd()
{

	int num;
	cout << "How many days to add\n";
	cin >> num;
	return num;
}
stDate readFullDate()
{
	stDate date;
	date.days = ReadDay();
	date.months = readMounth();
	date.year = readYear();
	return date;
}
bool isLeapYear(int year)
{
	/*if (year % 400 == 0)
	{
		return true;
	}
	if (year % 100 == 0)
	{
		return false;
	}

	if (year % 4 == 0)
	{
		return true;
	}*/
	/*return false;*/
	return ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)));

}
int numberDaysInMounth(int Month, int year)
{
	if (Month < 1 || Month>12)
		return 0;
	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ((Month == 2) ? ((isLeapYear(year) ? 29 : 28)) : (arrDays[Month - 1]));

}
bool isLastDayInMonth(stDate date)
{
	return (date.days == numberDaysInMounth(date.months, date.year));
}
bool isLastMonthInyear(short month)
{
	return (month == 12);
}
stDate increaseDateByOneDay(stDate Date)
{
	if (isLastDayInMonth(Date))
	{
		if (isLastMonthInyear(Date.months))
		{
			Date.months = 1;
			Date.days = 1;
			Date.year++;
		}
		else
		{
			Date.days = 1;
			Date.months++;
		}
	}
	else
	{
		Date.days++;
	}
	return Date;
}

stDate increaseDateByXDay(stDate date,short days)
{
	for (short i = 0; i < days; i++)
	{
		date = increaseDateByOneDay(date);
	}
	return date;
}

stDate increaseDateByOneWeek(stDate date)
{
	date = increaseDateByXDay(date, 7);
	return date;
}
stDate increaseDateByXWeek(stDate date,short numberOfWeeks)
{

	for (int i = 0; i < numberOfWeeks; i++)
	{
		date = increaseDateByOneWeek(date);
		
	}
	return date;

}
stDate increaseDateByOneMonth(stDate date)
{
	if (date.months == 12)
	{
		date.months = 1;
		date.year++;
	}
	else
	{
		date.months++;
	}

	short NumberOfDaysInCurrentMonth =	numberDaysInMounth(date.months, date.year);

	if (date.days > NumberOfDaysInCurrentMonth)
	{
		date.days = NumberOfDaysInCurrentMonth;
	}
	
	return date;

}
stDate increaseDateByXMonth(stDate date,short numberOfmonths)
{

	
	for (short i = 0; i < numberOfmonths; i++)
	{

		date = increaseDateByOneMonth(date);
	}
	return date;
}
stDate increaseDateByOneyear(stDate date)
{

	date.year++;

	return date;
}
stDate increaseDateByXYears(stDate date, short numberOfYears)
{
	for (short i = 0; i < numberOfYears; i++)
	{

		date = increaseDateByOneyear(date);
	}
	return date;
}
stDate increaseDateByXYearsFaster(stDate date, short numberOfYears)
{
	date.year += numberOfYears;
	return date;
}
stDate increaseDateByOneDacede(stDate date)
{
	date.year += 10;
	return date;
}
stDate increaseDateByXDacede(stDate date,short numberOfdacede)
{
	for (short i = 0; i < numberOfdacede; i++)
	{

		date = increaseDateByOneDacede(date);
	}
	return date;
}
stDate increaseDateByXDacedeFaster(stDate date, short numberOfdacede)
{
	date.year = date.year + 10* numberOfdacede;

	return date;
}
stDate increaseDateByOneCentury(stDate date)
{
	date.year += 100;
	return date;
}
stDate increaseDateByOneMillinoum(stDate date)
{
	date.year += 1000;
	return date;
}
int main()
{

	stDate date = readFullDate();

	


	date = increaseDateByOneDay(date);
	cout << "01-Adding one day is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByXDay(date, 10);
	cout << "02-Adding 10 day is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByOneWeek(date);
	cout << "03-Adding one week is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByXWeek(date, 10);
	cout << "04-Adding 10 weeks is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByOneMonth(date);
	cout << "05-Adding one month  is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByXMonth(date, 5);
	cout << "06-Adding 5 months  is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByOneyear(date);
	cout << "07-Adding one year is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByXYears(date, 10);
	cout << "08-Adding 10  year is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByXYearsFaster(date, 10);
	cout << "09-Adding 10  year is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByOneDacede(date);
	cout << "010-Adding one dacede  year is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByXDacede(date, 10);
	cout << "11-Adding 10  dacedes is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByXDacedeFaster(date, 10);
	cout << "12-Adding 10  dacedes faster is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByOneCentury(date);
	cout << "13-Adding centuy is :" << date.days << "/" << date.months << "/" << date.year << endl;
	date = increaseDateByOneMillinoum(date);
	cout << "13-Adding millinom is :" << date.days << "/" << date.months << "/" << date.year << endl;



	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}


