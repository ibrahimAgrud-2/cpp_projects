clear(): Clears the console screen using ANSI escape codes.

isLeapYear(int year): Determines if a given year is a leap year.

numberDaysInMounth(int Month, int year): Returns the number of days in a given month and year.

readYear(), readDay(), readMounth(): Functions to read the year, day, and month from user input.

readFullDate(): Reads a full date (day, month, year) from the user and returns it as an stDate object.

IsDate1BeforeDate2(stDate Date1, stDate Date2): Compares two dates and checks if the first date is before the second.

IsDate1EqualsDate2(stDate date1, stDate date2): Compares two dates and checks if they are equal.

swapDates(stDate& date1, stDate& date2): Swaps the values of two dates.

isLastDayInMonth(stDate date): Checks if a given date is the last day of its month.

isLastMonthInyear(short month): Checks if the given month is December.


IncreaseDateByOneDay(stDate Date): Increases the given date by one day.

getDifferenceIndays(stDate date1, stDate date2, bool includeLastDay): Calculates the difference in days between two dates.

CompereDates(stDate date1, stDate date2): Compares two dates and returns an enCompereDate value (before, equals, after).

readDatePeriod(): Reads a start and end date period from the user and returns it as an stDatePeriod object.

isPeriodsOverlap(stDatePeriod period1, stDatePeriod period2): Checks if two date periods overlap.

calculatePeriodLength(stDatePeriod period, bool includeTheLastDay): Calculates the length of a date period in days.

IsPeriodIncludeDate(stDatePeriod period, stDate date): Checks if a specific date falls within a given date period.

countOverlapDays(stDatePeriod period1, stDatePeriod period2): Counts the number of overlapping days between two date periods.
