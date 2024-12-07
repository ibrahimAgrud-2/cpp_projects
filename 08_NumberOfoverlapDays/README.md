Key Components of the Code:

    Structures:
        stDate: Represents a specific date with year, months, and days.
        stDatePeriod: Represents a period, with a start and an end date.

    Enums:
        enCompereDate: Defines three possible results of date comparison: before, equals, and after.

    Functions:
        clear(): Clears the console screen using ANSI escape codes.
        isLeapYear(int year): Determines if a given year is a leap year.
        numberDaysInMounth(int Month, int year): Returns the number of days in a given month and year.
        readYear(), readDay(), readMounth(): Functions to read the year, day, and month from the user input.
        readFullDate(): Reads a complete date (day, month, year) from user input and returns it as an stDate object.
        IsDate1BeforeDate2(stDate Date1, stDate Date2): Compares two dates to check if the first is before the second.
        IsDate1EqualsDate2(stDate date1, stDate date2): Compares two dates to check if they are equal.
        swapDates(stDate& date1, stDate& date2): Swaps two dates.
        isLastDayInMonth(stDate date): Checks if a given date is the last day of the month.
        isLastMonthInyear(short month): Checks if a given month is December.
        IncreaseDateByOneDay(stDate Date): Increases a given date by one day.
        getDifferenceIndays(stDate date1, stDate date2, bool includeLastDay): Calculates the difference in days between two dates.
        CompereDates(stDate date1, stDate date2): Compares two dates and returns an enum indicating if the first is before, equal to, or after the second date.
        readDatePeriod(): Reads a start and end date period from the user input.
        isPeriodsOverlap(stDatePeriod period1, stDatePeriod period2): Checks if two date periods overlap.
        calculatePeriodLength(stDatePeriod period, bool includeTheLastDay): Calculates the length of a date period in days.
        IsPeriodIncludeDate(stDatePeriod period, stDate date): Checks if a specific date falls within a given date period.
        countOverlapDays(stDatePeriod period1, stDatePeriod period2): Counts the number of overlapping days between two date periods.

    Main Program:
        The main() function clears the screen, reads two date periods from the user, and calculates the number of overlapping days between them using the function countOverlapDays(). The result is then printed to the console.
Detailed Breakdown of the Core Functions:

    isLeapYear(int year):
        Determines whether a given year is a leap year using the standard leap year rules.

    numberDaysInMounth(int Month, int year):
        Returns the number of days in a specific month of a given year. It handles February differently based on whether the year is a leap year.

    getDifferenceIndays(stDate date1, stDate date2, bool includeLastDay):
        Calculates the number of days between two dates. If includeLastDay is true, the last day is included in the count.
        It uses a loop to increment date1 by one day until it reaches date2 and counts the number of iterations.

    isPeriodsOverlap(stDatePeriod period1, stDatePeriod period2):
        Checks if two date periods overlap by comparing their start and end dates.

    countOverlapDays(stDatePeriod period1, stDatePeriod period2):
        This function calculates how many days overlap between two date periods. It first checks if the periods overlap using isPeriodsOverlap(), and if so, it counts the overlapping days by iterating through each period and checking if the start date of one period is within the other.
