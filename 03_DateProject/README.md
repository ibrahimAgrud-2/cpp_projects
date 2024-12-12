# **Date Calculation Program**

This project is designed to read date information such as day, month, and year from the user, and calculate various details, including:

    The day of the week
    Whether the date is a business day or falls on the weekend
    The remaining days until the end of the month and year

To fully understand this project, a basic understanding of programming concepts, especially structures (struct), is recommended.



## Features



#####  1.Date Input

The program takes the day, month, and year from the user and stores the information in a stDate structure.
##### 2.Leap Year Check

The program determines whether the given year is a leap year.

3.Day of the Week Calculation

The DayOfWeekOrder function calculates which day of the week the given date falls on, and the DayShortName function provides the short name of the day (e.g., "Mon", "Tue").

##### 4.Business Day and Weekend Check

The isEndOfWeek, isWeekEnd, and isBusinessDay functions check whether the date falls on a weekend or is a business day.
5. ##### Days Until End of Month/Year

The daysUntilEndOfMonth and daysUntilEndOfYear functions calculate how many days are left until the end of the month and the end of the year from the given date

.

## Important Notes

1. Input Validation Not Included

This program does not include input validation. If you enter data other than numbers where numbers are expected, errors may occur.
2. Required Knowledge

To fully understand the code, it is recommended to have a basic understanding of structs and fundamental programming concepts.