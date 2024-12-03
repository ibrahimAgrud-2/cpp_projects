DECREAS DATE Project

This project provides a program for manipulating date values by adding or subtracting days, weeks, months, years, decades, centuries, and millennia. It uses a custom struct, stDate, to store date information and multiple functions to modify date values.

⚠️ Important Note:

    Validation is not implemented in this project, so entering non-numeric values where numbers are expected will cause errors.
    Basic knowledge of structures and foundational C++ concepts is necessary to fully understand this code.

Project Overview

The program allows users to:

    Enter a date in the format of day, month, and year.
    Add or subtract various time periods to the entered date, including:
        Days
        Weeks
        Months
        Years
        Decades
        Centuries
        Millennia

Code Structure

The code is divided into multiple functions, each designed to handle a specific type of date manipulation. Below is a brief overview of each major component.
stDate Struct

struct stDate {
    int year;
    int months;
    int days;
};

The stDate structure stores day, month, and year as integer values. This struct is the main data structure that each function operates on.
Functions for Date Manipulation

    Date Input Functions
        readFullDate(): Prompts the user to enter a date and stores it in the stDate structure.

       Decrement Functions
    Functions like decreasDateByOneDay, decreasDayByXDays, decreasDayByOneWeek, etc., allow users to decrement the date by specific time intervals.

Main Program Flow

The program starts by asking the user to enter a date. Then, it performs various date manipulations as per user inputs and outputs the modified date for each manipulation step. For example:

stDate date = readFullDate();
date = decreasDateByOneDay(date);
cout << date.days << "/" << date.months << "/" << date.year << endl;

This block reads a date from the user, decrements it by one day, and then prints the new date.
How to Use

    Run the Program
    Compile and run the program in a C++ environment.

    Input Date
    Enter the date details when prompted. Please ensure to enter numeric values only.

    Date Manipulation
    The program will automatically perform and display the results of various date manipulations (addition and subtraction).

Error Handling

    No Validation
    This project does not implement validation. If non-numeric input is given where numbers are expected, it will result in an error.

Requirements

    Basic understanding of struct in C++
    Familiarity with date manipulation concepts