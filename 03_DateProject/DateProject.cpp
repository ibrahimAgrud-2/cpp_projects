#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include"MyDateLib.h"


using namespace std;

/***************************************************
//                 proceed one by one
/***************************************************/
struct stDate
{
	int year;
	int months;
	int days;

};
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

stDate readFullDate()
{
	stDate date;



	date.days = ReadDay();
	date.months = readMounth();
	date.year = readYear();
	return date;
}
string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = {
	"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}
short DayOfWeekOrder(short day, short month, short year)
{
	short a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}
short DayOfWeekOrder(stDate date)
{
	return (DayOfWeekOrder(date.days, date.months, date.year));
}

bool isEndOfWeek(stDate date)
{
	return  DayOfWeekOrder(date)==6;
	
}
bool  isWeekEnd(stDate date)
{
	short dayIndex = DayOfWeekOrder(date);
	//weekend is friday and saturday there is diffrent between countrys. 
	// are the Sundays and Saturdays is weekend in the country where you live 
	// so use --> return (dayIndex == 6 || dayIndex == 7);

	return (dayIndex == 5 || dayIndex == 6);
}
bool isBusinnesDay(stDate date)
{
	//short dayIndex = DayOfWeekOrder(date);

	//return !(dayIndex == 5 || dayIndex == 6);
	return !isWeekEnd(date);
}
short daysUntillEndOfWeek(stDate date)
{
	//first index of DayOfWeekOrder fonction is 0 so we used 6 for Number of day
	return (6 - DayOfWeekOrder(date));
}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.year < Date2.year) ? true : ((Date1.year ==
		Date2.year) ? (Date1.months < Date2.months ? true : (Date1.months ==
			Date2.months ? Date1.days < Date2.days : false)) : false);
}
void swapDates(stDate& date1, stDate& date2)
{
	stDate tempDate = date1;
	date1 = date2;
	date2 = tempDate;

}

bool isLastDayInMonth(stDate date)
{
	return (date.days == numberDaysInMounth(date.months, date.year));
}
bool isLastMonthInyear(short month)
{
	return (month == 12);
}
stDate IncreaseDateByOneDay(stDate Date)
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
int getDifferenceIndays(stDate date1, stDate date2, bool includeLastDay = false)
{
	int sum = 0;
	short swapFlagValue = 1;
	if (!IsDate1BeforeDate2(date1, date2))
	{
		swapDates(date1, date2);
		swapFlagValue = -1;
	}
	while (IsDate1BeforeDate2(date1, date2))
	{
		sum++;
		date1 = IncreaseDateByOneDay(date1);

	}


	return includeLastDay ? ++sum * swapFlagValue : sum * swapFlagValue;
}
short daysUntillEndOfMonth(stDate date)
{
	//short numOfDays = numberDaysInMounth(date.months, date.year);
	//return (numOfDays-date.days+1);
	stDate endOfMonthDate;
		endOfMonthDate.days= numberDaysInMounth(date.months, date.year);
		endOfMonthDate.months = date.months;
		endOfMonthDate.year = date.year;
		return (getDifferenceIndays(date, endOfMonthDate, true));

}
short daysUntillEndOfYear(stDate date)
{
	//short numOfDays = totalDaysFromTheBigrnYear(date);
	//short numberOfdaysInYear = isLeapYear(date.year) ? 366 : 365;
	//return (numberOfdaysInYear - numOfDays+1);
	stDate endOfYearDate;
	endOfYearDate.days = 12;
	endOfYearDate.months = 31;
	endOfYearDate.year = date.year;
	return (getDifferenceIndays(date, endOfYearDate, false));

}
int main()
{

	stDate date = readFullDate();
	short dayOrder = DayOfWeekOrder(date);
	cout << "Today is : " << DayShortName(dayOrder) << ", "<<date.days<<"/"<<date.months<<"/"<<date.year<<endl;
	cout << "\nis end of week ?\n ";
	if (isEndOfWeek(date))
	{
		cout << "Yes,it is end of week\n";
	}
	else
	{
		cout << "No, it is not end of week\n";
	}
	cout << endl;
	cout << "\nIt is weeknd ? \n";
	if (isWeekEnd(date))
	{
		cout << "Yes,it is weeknd\n";
	}
	else
	{
		cout << "No,today is "<< DayShortName(dayOrder) <<" it is not weeknd\n";
	}
	cout << endl;
	cout << "\nIt is business day ?\n ";
	if (isBusinnesDay(date))
	{
		cout << "Yes,it is business day\n";
	}
	else
	{
		cout << "No, it is not business day\n";
	}
	cout << endl;
	cout << "\nDay untill end of week : " <<daysUntillEndOfWeek(date) << " day(s)\n";
	cout << "Day untill end of month : " << daysUntillEndOfMonth(date) << " day(s)\n";
	cout << "Day untill end of year : " << daysUntillEndOfYear(date) << " day(s)\n";


	cout << endl;
	cout << endl;
	system("pause");
	
	return 0;
}


