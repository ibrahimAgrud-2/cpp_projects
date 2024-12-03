#pragma warning(disable : 4996)
#include <iostream>
#include <math.h>


using namespace std;

/***
//                 proceed one by one
/*/
void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}
enum enCompereDate { before = -1, equals = 0, after = 1 };
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
    //return false; /
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



bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year ==
        Date2.year) ? (Date1.months < Date2.months ? true : (Date1.months ==
            Date2.months ? Date1.days < Date2.days : false)) : false);
}
bool IsDate1EqualsDate2(stDate date1, stDate date2)
{
    return(date1.year == date2.year) ? (date1.months == date2.months) ? (date1.days == date2.days) ? true : false : false : false;

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




 
enCompereDate CompereDates(stDate date1, stDate date2)
{
    return (IsDate1BeforeDate2(date1, date2) ? enCompereDate::before : (IsDate1EqualsDate2(date1, date2) ? enCompereDate::equals : enCompereDate::after));
}

struct stDatePeriod
{
    stDate startDate;
    stDate endDate;
};

stDatePeriod readDatePeriod()
{
    stDatePeriod periods;
    cout << "Enter start date :\n";
    periods.startDate = readFullDate();
    cout << "Enter end date :\n";
    periods.endDate = readFullDate();

    return periods;
}

bool isPeriodsOverlap(stDatePeriod period1, stDatePeriod period2)
{
    if (CompereDates(period2.endDate, period1.startDate) == enCompereDate::before ||
        CompereDates(period1.startDate, period2.endDate) == enCompereDate::after
        )
    {
        return false;
    }
    else
    {
        return true;
    }

}
short calculatePeriodLength(stDatePeriod period, bool includeTheLastDay = false)
{
    return getDifferenceIndays(period.startDate, period.endDate, includeTheLastDay);

}

bool IsPeriodIncludeDate(stDatePeriod period, stDate date)
{
    // return(IsDate1AfterDate2(date,period.startDate)&&IsDate1AfterDate2(period.endDate,date));
    return !(CompereDates(date, period.startDate) ==
        enCompereDate::before
        ||
        CompereDates(date, period.endDate) ==
        enCompereDate::after);

}

short countOverlapDays(stDatePeriod period1, stDatePeriod period2)
{

     short Period1Length=getDifferenceIndays(period1.startDate,period1.endDate,true);
     short Period2Length=getDifferenceIndays(period2.startDate, period2.endDate,true);
    short countOverlapDay = 0;
      if (!isPeriodsOverlap(period1, period2))
              return 0;
    if (Period1Length< Period2Length)
     {
         while (IsDate1BeforeDate2(period1.startDate,period1.endDate))
     {
             if (IsPeriodIncludeDate(period2,period1.startDate))
             {
                 countOverlapDay++;
         }
             period1.startDate = IncreaseDateByOneDay(period1.startDate);
      }

    }
      else
     {
         while (IsDate1BeforeDate2(period2.startDate, period2.endDate))
         {
             if (IsPeriodIncludeDate(period1, period2.startDate))
             {
                 countOverlapDay++;
             }
          period2.startDate = IncreaseDateByOneDay(period2.startDate);
         }

     }
     return countOverlapDay;



   

}
int main()
{
    clear();

    cout << "--> period 1 :\n";
    stDatePeriod period1 = readDatePeriod();
    cout << "--> period 2 :\n";
    stDatePeriod period2 = readDatePeriod();
    cout << countOverlapDays(period1, period2)<<endl;

    return 0;
}
