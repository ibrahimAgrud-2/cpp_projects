#ifndef CLSDATE_H
#define CLSDATE_H

#pragma once

#pragma once 
#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
#include <string>
#include"clsString.h"




using namespace std;

class clsDate
{

private :
	 
	short  Day=1;
	short  Month=1;
	short  Year=1900;
	
public : 

	static clsDate getSystemDate()
	{
		// system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
        
		return clsDate(Day, Month, Year);
	}
static string getSystemDateAsString()
	{
		// system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return to_string(Year)+"/"+to_string(Month)+"/"+to_string(Day);
        
		
	}
	static string getSystemTimeAsString()
{
   
time_t t = time(0);
tm* now = localtime(&t);
return to_string(now->tm_hour)+":"+to_string(now->tm_min)+":"+to_string(now->tm_sec);

}

	clsDate()
	{
		*this = getSystemDate();

	}

	clsDate(string date)
	{
		vector<string>vDate = clsString::Split(date, "/");

		Day =stoi(vDate[0]);
		Month = stoi(vDate[1]);
		Year = stoi(vDate[2]);

	}
	clsDate(short day,short month,short year)
	{
		Day = day;
		Month = month;
		Year = year;

	}

	
static clsDate getDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{

		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}

		}

		return Date;
	}

	clsDate(short dayOreder, short year)
	{
		clsDate date = getDateFromDayOrderInYear(dayOreder, year);
		Day = date.Day;
		Month = date.Month;
		Year = date.year();

	}

	void setDay(short day)
	{
		this->Day = day;

	}
	void setMonth(short Month)
	{
		this->Month = Month;

	}
	void setYear(short Year)
	{
		this->Year = Year;

	}
	

	short day()
	{
		return Day;
	}
	short month()
	{
		return Month;
	}
	short year()
	{
		return Year;
	}




	static bool isLeapYear(short Year)
	{

	// 	if year is divisible by 4 AND not divisible by 100
	//   OR if year is divisible by 400
	//   then it is a leap year
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	 bool isLeapYear()
	{

	// 	if year is divisible by 4 AND not divisible by 100
	//   OR if year is divisible by 400
	//   then it is a leap year
		return (isLeapYear(Year));
	}


	static short NumberOfDaysInAMonth(short Month, short Year)
	{

		if (Month < 1 || Month>12)
			return  0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];

	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(Month, Year);
	}




	static short DaysFromTheBeginingOfTheYear(short day,short Month, short Year)
	{


		short TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}

		TotalDays += day;

		return TotalDays;
	}
	short DaysFromTheBeginingOfTheYear()
	{
		return (DaysFromTheBeginingOfTheYear(Day, Month, Year));
	}





	// verdiğim yıla yine verdiğim günü ekliyor 
	




	static	bool IsValidDate(clsDate Date)
	{

		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2)
		{
			if (isLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;

	}
	
	bool IsValid()
	{
		return IsValidDate(*this);
	}
	
	  void print()
	  {
		  cout << "Date : ";
		  cout << Day<< "/" << Month << "/" << Year<<endl;
	  }

	  static string DateToString(clsDate Date)
	  {
		  return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	  }
	
	  string DateToString()
	  {
		  return  DateToString(*this);
	  }


	  static short NumberOfDaysInAYear(short Year)
	  {
		  return  isLeapYear(Year) ? 365 : 364;
	  }
	 short NumberOfDaysInAYear()
	  {
			return NumberOfDaysInAYear(Year);
	  }
	

	 
	 static short NumberOfHoursInAYear(short Year)
		{
			return  NumberOfDaysInAYear(Year) * 24;
		}
		short NumberOfHoursInAYear()
		{
			return NumberOfHoursInAYear(Year);
		}


		static int NumberOfMinutesInAYear(short Year)
		{
			return  NumberOfHoursInAYear(Year) * 60;
		}
		int NumberOfMinutesInAYear()
		{
			return  NumberOfMinutesInAYear(Year);
		}


		static int NumberOfSecondsInAYear(short Year)
		{
			return  NumberOfMinutesInAYear(Year) * 60;
		}
		int NumberOfSecondsInAYear()
		{
			return  NumberOfSecondsInAYear();
		}
		
		

		//verilen bilgilere göre haftanın kaçııncı gününde olduğunuzuı söyler
		static short DayOfWeekOrder(short Day, short Month, short Year)
		{
			short a, y, m;
			a = (14 - Month) / 12;
			y = Year - a;
			m = Month + (12 * a) - 2;
			// Gregorian:
			// 0:sun, 1:Mon, 2:Tue...etc
			return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		}
		 short DayOfWeekOrder()
		{
			
			 return DayOfWeekOrder(Day,Month,Year);
		 }

		 static string DayShortName(short DayOfWeekOrder)
		 {
			 string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

			 return arrDayNames[DayOfWeekOrder];

		 }
		 static string DayShortName(short Day, short Month, short Year)
		 {

			 string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

			 return arrDayNames[DayOfWeekOrder(Day, Month, Year)];

		 }
		 string DayShortName()
		 {
			 DayShortName(DayOfWeekOrder());
		 }
		 static string MonthShortName(short MonthNumber)
		 {
			 string Months[12] = { "Jan", "Feb", "Mar",
								"Apr", "May", "Jun",
								"Jul", "Aug", "Sep",
								"Oct", "Nov", "Dec"
			 };

			 return (Months[MonthNumber - 1]);
		 }
		 string MonthShortName()
		 {
			 return (MonthShortName(Month));
		 }


		 static void PrintMonthCalendar(short Month, short Year)
		 {
			 int NumberOfDays;

			 //Index of the day from 0 to 6
			 int current = DayOfWeekOrder(1, Month, Year);

			 NumberOfDays = NumberOfDaysInAMonth(Month, Year);

			// Print the current month name
			 printf("\n  _______________%s_______________\n\n",
				 MonthShortName(Month).c_str());

			 //Print the columns
			 printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

			 //Print appropriate spaces

			 int i;
			 for (i = 0; i < current; i++)
				 printf("     ");

			 for (int j = 1; j <= NumberOfDays; j++)
			 {
				 printf("%5d", j);


				 if (++i == 7)
				 {
					 i = 0;
					 printf("\n");
				 }
			 }

			 printf("\n  _________________________________\n");

		 }
		 void PrintMonthCalendar()
		 {
			 PrintMonthCalendar(Month, Month);
		 }

		 static void PrintYearCalendar(int Year)
		 {
			 printf("\n  _________________________________\n\n");
			 printf("           Calendar - %d\n", Year);
			 printf("  _________________________________\n");


			 for (int i = 1; i <= 12; i++)
			 {
				 PrintMonthCalendar(i, Year);
			 }

			 return;
		 }
		 void PrintYearCalendar()
		 {
			 PrintYearCalendar(Year);
		 }

		 void AddDays(short Days)
		 {


			 short RemainingDays = Days + DaysFromTheBeginingOfTheYear(Day, Month, Year);
			 short MonthDays = 0;

			 Month = 1;

			 while (true)
			 {
				 MonthDays = NumberOfDaysInAMonth(Month, Year);

				 if (RemainingDays > MonthDays)
				 {
					 RemainingDays -= MonthDays;
					 Month++;

					 if (Month > 12)
					 {
						 Month = 1;
						 Year++;

					 }
				 }
				 else
				 {
					 Day = RemainingDays;
					 break;
				 }

			 }


		 }


		 static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
		 {
			 return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
		 }
		 bool IsDateBeforeDate2(clsDate Date2)
		 {
			// note: *this sends the current object :-) 

			 return  IsDate1BeforeDate2(*this, Date2);

		 }

		 static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
		 {
			 return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
		 }	 
		 bool IsDate1EqualDate2(clsDate Date2)
		 {
			 return IsDate1EqualDate2(*this, Date2);
		 }


		 static bool IsLastDayInMonth(clsDate Date)
		 {

			 return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));

		 }
		 bool IsLastDayInMonth()
		 {
			 return IsLastDayInMonth(*this);

		 }

		 static bool IsLastMonthInYear(short Month)
		 {
			 return (Month == 12);
		 }
		 bool IsLastMonthInYear()
		 {
			 return IsLastMonthInYear(Month);
		 }

		 //increas date by one day
		 static clsDate AddOneDay(clsDate Date)
		 {
			 if (IsLastDayInMonth(Date))
			 {
				 if (IsLastMonthInYear(Date.Month))
				 {
					 Date.Month = 1;
					 Date.Day = 1;
					 Date.Year++;
				 }
				 else
				 {
					 Date.Day = 1;
					 Date.Month++;
				 }
			 }
			 else
			 {
				 Date.Day++;
			 }

			 return Date;
		 }
		 void AddOneDay()
		 {
			 *this= AddOneDay(*this);
		 }

		 static void  swapDates(clsDate& Date1, clsDate& Date2)
		 {

			 clsDate TempDate;
			 TempDate = Date1;
			 Date1 = Date2;
			 Date2 = TempDate;

		 }

		 static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
		 {
			 //this will take care of negative diff
			 int Days = 0;
			 short SawpFlagValue = 1;

			 if (IsDate1AfterDate2(Date1, Date2))
			 {
				// Swap Dates 
				 swapDates(Date1, Date2);
				 SawpFlagValue = 1;

			 }

			 while (IsDate1BeforeDate2(Date1, Date2))
			 {
				 Days++;
				 Date1 = AddOneDay(Date1);
			 }

			 return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
		 }
		 int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
		 {
			 return GetDifferenceInDays(*this, Date2, IncludeEndDay);
		 }

		//  aşağdaki  fonksiyon için static olmayan tür tanımlamamıza gerek yok
		//  çünkü bu kendi başına ayrı bir fonksiyon belli bir  tarih veririm yaşımı hesaplar

		 static short CalculateMyAgeInDays(clsDate DateOfBirth)

		 {
			 return GetDifferenceInDays(DateOfBirth, clsDate::getSystemDate(), true);
		 }

		 static clsDate IncreaseDateByOneWeek(clsDate& Date)
		 {

			 for (int i = 1; i <= 7; i++)
			 {
				 Date = AddOneDay(Date);
			 }
			 return Date;
			
		 }
		 void IncreaseDateByOneWeek()
		 {
			 IncreaseDateByOneWeek(*this);
		 }


		 clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
		 {

			 for (short i = 1; i <= Weeks; i++)
			 {
				 Date = IncreaseDateByOneWeek(Date);
			 }
			 return Date;
		 }

		 void IncreaseDateByXWeeks(short Weeks)
		 {
			 IncreaseDateByXWeeks(Weeks, *this);
		 }

		 clsDate IncreaseDateByOneMonth(clsDate& Date)
		 {

			 if (Date.Month == 12)
			 {
				 Date.Month = 1;
				 Date.Year++;
			 }
			 else
			 {
				 Date.Month++;
			 }

			//  last check day in date should not exceed max days in the current month
			//  example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
			//  be 28/2/2022

			 short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
			 if (Date.Day > NumberOfDaysInCurrentMonth)
			 {
				 Date.Day = NumberOfDaysInCurrentMonth;
			 }

			 return Date;
		 }


	
		 void IncreaseDateByOneMonth()
		 {

			 IncreaseDateByOneMonth(*this);

		 }

		 //



		 clsDate IncreaseDateByXDays(short Days, clsDate& Date)
		 {

			 for (short i = 1; i <= Days; i++)
			 {
				 Date = AddOneDay(Date);
			 }
			 return Date;
		 }

		 void IncreaseDateByXDays(short Days)
		 {

			 IncreaseDateByXDays(Days, *this);
		 }

		 clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
		 {

			 for (short i = 1; i <= Months; i++)
			 {
				 Date = IncreaseDateByOneMonth(Date);
			 }
			 return Date;
		 }

		 void IncreaseDateByXMonths(short Months)
		 {
			 IncreaseDateByXMonths(Months, *this);
		 }

		 static clsDate IncreaseDateByOneYear(clsDate& Date)
		 {
			 Date.Year++;
			 return Date;
		 }

		 void IncreaseDateByOneYear()
		 {
			 IncreaseDateByOneYear(*this);
		 }

		 clsDate IncreaseDateByXYears(short Years, clsDate& Date)
		 {
			 Date.Year += Years;
			 return Date;

		 }

		 void IncreaseDateByXYears(short Years)
		 {
			 IncreaseDateByXYears(Years);
		 }

		 clsDate IncreaseDateByOneDecade(clsDate& Date)
		 {
			// Period of 10 years
			 Date.Year += 10;
			 return Date;
		 }

		 void IncreaseDateByOneDecade()
		 {
			 IncreaseDateByOneDecade(*this);
		 }

		 clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
		 {
			 Date.Year += Decade * 10;
			 return Date;
		 }

		 void IncreaseDateByXDecades(short Decade)
		 {
			 IncreaseDateByXDecades(Decade, *this);
		 }

		 clsDate IncreaseDateByOneCentury(clsDate& Date)
		 {
			 //Period of 100 years
			 Date.Year += 100;
			 return Date;
		 }

		 void IncreaseDateByOneCentury()
		 {
			 IncreaseDateByOneCentury(*this);
		 }

		 clsDate IncreaseDateByOneMillennium(clsDate& Date)
		 {
			// Period of 1000 years
			 Date.Year += 1000;
			 return Date;
		 }

		 clsDate IncreaseDateByOneMillennium()
		 {
			 IncreaseDateByOneMillennium(*this);
		 }

		 static clsDate DecreaseDateByOneDay(clsDate Date)
		 {
			 if (Date.Day == 1)
			 {
				 if (Date.Month == 1)
				 {
					 Date.Month = 12;
					 Date.Day = 31;
					 Date.Year--;
				 }
				 else
				 {

					 Date.Month--;
					 Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				 }
			 }
			 else
			 {
				 Date.Day--;
			 }

			 return Date;
		 }

		 void DecreaseDateByOneDay()
		 {
			 DecreaseDateByOneDay(*this);
		 }

		 static clsDate DecreaseDateByOneWeek(clsDate& Date)
		 {

			 for (int i = 1; i <= 7; i++)
			 {
				 Date = DecreaseDateByOneDay(Date);
			 }

			 return Date;
		 }

		 void DecreaseDateByOneWeek()
		 {
			 DecreaseDateByOneWeek(*this);
		 }

		 static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
		 {

			 for (short i = 1; i <= Weeks; i++)
			 {
				 Date = DecreaseDateByOneWeek(Date);
			 }
			 return Date;
		 }

		 void DecreaseDateByXWeeks(short Weeks)
		 {
			 DecreaseDateByXWeeks(Weeks, *this);
		 }

		 static clsDate DecreaseDateByOneMonth(clsDate& Date)
		 {

			 if (Date.Month == 1)
			 {
				 Date.Month = 12;
				 Date.Year--;
			 }
			 else
				 Date.Month--;


			//  last check day in date should not exceed max days in the current month
			// example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
			// be 28/2/2022

			 short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
			 if (Date.Day > NumberOfDaysInCurrentMonth)
			 {
				 Date.Day = NumberOfDaysInCurrentMonth;
			 }


			 return Date;
		 }

		 void DecreaseDateByOneMonth()
		 {
			 DecreaseDateByOneMonth(*this);
		 }

		 static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
		 {

			 for (short i = 1; i <= Days; i++)
			 {
				 Date = DecreaseDateByOneDay(Date);
			 }
			 return Date;
		 }

		 void DecreaseDateByXDays(short Days)
		 {
			 DecreaseDateByXDays(Days, *this);
		 }

		 static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
		 {

			 for (short i = 1; i <= Months; i++)
			 {
				 Date = DecreaseDateByOneMonth(Date);
			 }
			 return Date;
		 }

		 void DecreaseDateByXMonths(short Months)
		 {
			 DecreaseDateByXMonths(Months, *this);
		 }

		 static clsDate DecreaseDateByOneYear(clsDate& Date)
		 {

			 Date.Year--;
			 return Date;
		 }

		 void DecreaseDateByOneYear()
		 {
			 DecreaseDateByOneYear(*this);
		 }

		 static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
		 {

			 Date.Year -= Years;
			 return Date;
		 }

		 void DecreaseDateByXYears(short Years)
		 {
			 DecreaseDateByXYears(Years, *this);
		 }

		 static clsDate DecreaseDateByOneDecade(clsDate& Date)
		 {
			 //Period of 10 years
			 Date.Year -= 10;
			 return Date;
		 }

		 void DecreaseDateByOneDecade()
		 {
			 DecreaseDateByOneDecade(*this);
		 }

		 static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
		 {

			 Date.Year -= Decades * 10;
			 return Date;
		 }

		 void DecreaseDateByXDecades(short Decades)
		 {
			 DecreaseDateByXDecades(Decades, *this);
		 }

		 static clsDate DecreaseDateByOneCentury(clsDate& Date)
		 {
			// Period of 100 years
			 Date.Year -= 100;
			 return Date;
		 }

		 void DecreaseDateByOneCentury()
		 {
			 DecreaseDateByOneCentury(*this);
		 }

		 static clsDate DecreaseDateByOneMillennium(clsDate& Date)
		 {
			 //Period of 1000 years
			 Date.Year -= 1000;
			 return Date;
		 }

		 void DecreaseDateByOneMillennium()
		 {
			 DecreaseDateByOneMillennium(*this);
		 }


		 static short IsEndOfWeek(clsDate Date)
		 {
			 return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
		 }

		 short IsEndOfWeek()
		 {
			 return IsEndOfWeek(*this);
		 }

		 static bool IsWeekEnd(clsDate Date)
		 {
			 //Weekends are Fri and Sat

			 short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
			 return  (DayIndex == 5 || DayIndex == 6);
		 }

		 bool IsWeekEnd()
		 {
			 return  IsWeekEnd(*this);
		 }

		 static bool IsBusinessDay(clsDate Date)
		 {
			 //Weekends are Sun,Mon,Tue,Wed and Thur

			/*
			 short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
			 return  (DayIndex >= 5 && DayIndex <= 4);
			*/

			//shorter method is to invert the IsWeekEnd: this will save updating code.
			 return !IsWeekEnd(Date);

		 }

		 bool IsBusinessDay()
		 {
			 return  IsBusinessDay(*this);
		 }

		 static short DaysUntilTheEndOfWeek(clsDate Date)
		 {
			 return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		 }

		 short DaysUntilTheEndOfWeek()
		 {
			 return  DaysUntilTheEndOfWeek(*this);
		 }

		 static short DaysUntilTheEndOfMonth(clsDate Date1)
		 {

			 clsDate EndOfMontDate;
			 EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
			 EndOfMontDate.Month = Date1.Month;
			 EndOfMontDate.Year = Date1.Year;

			 return GetDifferenceInDays(Date1, EndOfMontDate, true);

		 }

		 short DaysUntilTheEndOfMonth()
		 {
			 return DaysUntilTheEndOfMonth(*this);
		 }

		 static short DaysUntilTheEndOfYear(clsDate Date1)
		 {

			 clsDate EndOfYearDate;
			 EndOfYearDate.Day = 31;
			 EndOfYearDate.Month = 12;
			 EndOfYearDate.Year = Date1.Year;

			 return GetDifferenceInDays(Date1, EndOfYearDate, true);

		 }

		 short DaysUntilTheEndOfYear()
		 {
			 return  DaysUntilTheEndOfYear(*this);
		 }

		 // added this method to calculate business days between 2 days

		 static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
		 {

			 short Days = 0;
			 while (IsDate1BeforeDate2(DateFrom, DateTo))
			 {
				 if (IsBusinessDay(DateFrom))
					 Days++;

				 DateFrom = AddOneDay(DateFrom);
			 }

			 return Days;

		 }

		 static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
		 {
			 /*short Days = 0;
			 while (IsDate1BeforeDate2(DateFrom, DateTo))
			 {
				 if (IsBusinessDay(DateFrom))
					 Days++;

				 DateFrom = AddOneDay(DateFrom);
			 }*/

			 return CalculateBusinessDays(DateFrom, DateTo);

		 }
		 //above method is eough , no need to have method for the object

		 static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
		 {

			 short WeekEndCounter = 0;

			 for (short i = 1; i <= VacationDays; i++)
			 {

				 if (IsWeekEnd(DateFrom))
					 WeekEndCounter++;

				 DateFrom = AddOneDay(DateFrom);
			 }
			 //to add weekends 
			 for (short i = 1; i <= WeekEndCounter; i++)
				 DateFrom = AddOneDay(DateFrom);

			 return DateFrom;
		 }

		 static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
		 {
			 return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

		 }

		 bool IsDateAfterDate2(clsDate Date2)
		 {
			 return IsDate1AfterDate2(*this, Date2);
		 }

		 enum enDateCompare { Before = -1, Equal = 0, After = 1 };

		 static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
		 {
			 if (IsDate1BeforeDate2(Date1, Date2))
				 return enDateCompare::Before;

			 if (IsDate1EqualDate2(Date1, Date2))
				 return enDateCompare::Equal;

			 /* if (IsDate1AfterDate2(Date1,Date2))
				  return enDateCompare::After;*/

				 // this is faster
			 return enDateCompare::After;

		 }

		 enDateCompare CompareDates(clsDate Date2)
		 {
			 return CompareDates(*this, Date2);
		 }



};






#endif