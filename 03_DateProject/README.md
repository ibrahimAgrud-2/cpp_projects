Date Calculation Program

This project reads date information from the user, such as day, month, and year, to calculate details like the day of the week, business day status, weekend status, and remaining days until the end of the month and year. To understand this project, you need a basic understanding of programming concepts, particularly structures (struct).
Features

This program includes the following features:

    Date Reading: Reads day, month, and year information from the user.
    Leap Year Check: Determines if the given year is a leap year.
    Day of the Week: Calculates which day of the week the given date falls on.
    Weekend Check: Determines if the date is a business day or falls on the weekend.
    Remaining Days in Month/Year: Calculates how many days are left until the end of the month and the end of the year from the given date.

Usage

    Date Input:
        The program takes day, month, and year inputs from the user and stores them in a stDate structure.

    Day of the Week Calculation:
        The DayOfWeekOrder function returns the weekday order of the date, and DayShortName provides the short day name (e.g., "Mon", "Tue").

    Business Day and Weekend Determination:
        The functions isEndOfWeek, isWeekEnd, and isBusinnesDay check whether the date falls on a weekend or a business day.

    Days Until End of Month/Year:
        The functions daysUntillEndOfMonth and daysUntillEndOfYear calculate how many days remain until the end of the month and year from the given date.

Important Notes

    Validation Not Included:
        No input validation is implemented in this project. Therefore, if you enter data other than a number where a number is expected, you may encounter errors.

    Required Knowledge:
        To understand this code, it's recommended to have a basic understanding of struct and fundamental programming concepts.