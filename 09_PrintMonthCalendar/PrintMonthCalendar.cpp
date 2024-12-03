#include <iostream>
#include<string>
#include <math.h>
#include <iomanip>
using namespace std;

int readYear()
{
	int num;
	cout << "enter a Year\n";
	cin >> num;
	return   num;
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
int readMounth()
{
	int num;
	cout << "enter a Mounth\n";
	cin >> num;
	return num;
}
string getMonth(short numOfMonth)
{
	string arr[13] = { "","january","february","march" ,"april",
		"may","june","july", "August","September","october","november" ,"december" };
	return arr[numOfMonth];

}
short DayOfWeekOrder(short Day,short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}
int numberDaysInMounth(int Month, int year)
{
	if (Month < 1 || Month>12)
		return 0;
	short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return ((Month == 2) ? ((isLeapYear(year) ? 29 : 28)) : (arrDays[Month - 1]));

}

void PrintMonthCalendar(short Month, short Year)
{
	int NumberOfDays;
	// Index of the day from 0 to 6
	int current = DayOfWeekOrder(1, Month, Year);
	NumberOfDays = numberDaysInMounth(Month, Year);
	// Print the current month name
	printf("\n _______________%s_______________\n\n",
		getMonth(Month).c_str());
	// Print the columns
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
	// Print appropriate spaces
	int i;
	for (i = 0; i < current; i++)
		printf(" ");
	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);
		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n _________________________________\n");
}
int main()
{

	short Year = readYear();
	short Month = readMounth();
	PrintMonthCalendar(Month, Year);


	cout << endl;
	system("pause");
	return 0;
}



/*#include <iostream>
#include<string>
#include <math.h>

using namespace std;

int readYear()
{
	int num;
	cout << "enter a Year\n";
	cin >> num;
	return   num;
}
int readMounth()
{
	int num;
	cout << "enter a Mounth\n";
	cin >> num;
	return num;
}
short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
string getMonth(short numOfMonth)
{
	string arr[13] = { "","january","february","march" ,"april",
		"may","june","july", "August","September","october","november" ,"december" };
	return arr[numOfMonth];

}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = {
	"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}
int main()
{
	short Year = readYear();
	short Month = readMounth();
	short Day = ReadDay();
	cout << "\nDate :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
	cout << "\nDay Name : " << DayShortName(DayOfWeekOrder(Day,Month, Year));
	
	
	cout << endl;
	system("pause");
	return 0;
}*/     