Program Overview

This program takes a date input (day, month, year) from the user and allows them to add a specific number of days to it. The program then calculates the resulting date, accounting for leap years and month lengths.
Functions Explained

    short readYear()
    Reads the year input from the user and returns it.

    short readMounth()
    Reads the month input from the user and returns it.

    short ReadDay()
    Reads the day input from the user and returns it.

    stDate readFullDate()
    Reads the full date (day, month, year) by calling the above functions and stores it in a stDate structure.

    bool isLeapYear(short year)
    Checks if the given year is a leap year.

    int numberDaysInMounth(short Month, short year)
    Returns the number of days in a given month, accounting for February’s leap year adjustment.

    short totalDaysFromTheBigrnYear(short Day, short Month, short Year)
    Calculates the total days passed since the start of the year up to the given date.

    stDate addDayToDate(short totalDays, stDate date)
    Adds a specific number of days to a given date. Adjusts the day, month, and year as needed.

How It Works

    The user inputs a date (dd/mm/yyyy).
    The user specifies the number of days to add.
    The program calculates the resulting date by iterating through days and adjusting for month/year transitions.
    It outputs the final date in the format dd/mm/yyyy.