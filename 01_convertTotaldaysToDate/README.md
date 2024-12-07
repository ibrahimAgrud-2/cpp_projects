Date Manipulation Program
Overview

This C++ program allows users to input a specific date and then add a certain number of days to it. The program handles leap years, months of varying lengths, and ensures that date calculations respect the proper calendar structure.
Features:

    Accepts input for the year, month, and day.
    Calculates the total number of days in a given month, considering leap years for February.
    Adds a specified number of days to a given date.
    Correctly adjusts the month, year, and day values based on the added days.

How It Works

    Date Input: The program first prompts the user to enter a date, which consists of a year, month, and day. This date is stored as a structure (stDate) containing three fields: year, months, and days.

    Leap Year Check: The program includes a function isLeapYear() to determine whether a given year is a leap year. This check is especially important for February, as leap years have 29 days instead of the usual 28.

    Month Days Calculation: Using the numberDaysInMounth() function, the program calculates the number of days in a given month, adjusting for leap years in February.

    Total Days Calculation: The program calculates the total number of days from the start of the year to the entered date using the totalDaysFromTheBigrnYear() function. This provides a baseline for adding days to the date.

    Adding Days: The program allows the user to add a specified number of days to the given date. The addDayToDate() function iterates through the days, adjusting the month and year as necessary.

    Output: The program displays the new date after the days are added.

Functions
readYear()

Prompts the user to input a year and returns the year as a short.
readMounth()

Prompts the user to input a month and returns it as a short.
ReadDay()

Prompts the user to input a day and returns it as a short.
readFullDate()

Reads the full date (year, month, day) from the user and returns it as a stDate structure.
isLeapYear(short year)

Checks if the given year is a leap year. Returns true if it is a leap year, otherwise returns false.
numberDaysInMounth(short Month, short year)

Returns the number of days in a given month and year, considering leap years for February.
totalDaysFromTheBigrnYear(short Day, short Month, short Year)

Calculates the total number of days from the start of the year to the specified date.
addDayToDate(short totalDays, stDate date)

Adds the given number of days to the specified date and returns the updated date in the form of a stDate structure.
