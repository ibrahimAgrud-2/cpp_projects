# Date Manipulation Program

**Warning**: This project does **not** include input validation. Please enter only numeric values where numbers are required. Entering non-numeric values in these fields will cause the program to crash or produce errors.

**Note**: To fully understand and modify this code, it's recommended to have knowledge of structures and basic C++ concepts.

## Overview

This program allows users to input a specific date and perform various date manipulations, such as adding days, weeks, months, years, decades, centuries, and even millennia to the given date. It also accounts for leap years and adjusts the day and month values accordingly.

## Features

1. **Add Days, Weeks, and Months**: Users can add a specific number of days, weeks, or months to the given date.
2. **Add Years and Decades**: The program provides options to add years or decades, with both iterative and "faster" implementations.
3. **Add Centuries and Millennia**: Users can move the date forward by a century or millennium for extended calculations.
4. **Leap Year Support**: The program identifies leap years and adjusts February's day count accordingly.

## Functions

- **Input Functions**: Functions like `readYear`,
 `ReadDay`, and `readMounth` are used to capture year,
 day, and month inputs from the user.

- **Date Increment Functions**: Functions such as `increaseDateByOneDay`, `increaseDateByOneWeek`, and `increaseDateByOneMonth` allow users to increment the date by various time periods.


- **Helper Functions**: Utility functions such as `isLeapYear` and 
`numberDaysInMounth` help in calculating the appropriate day and month values.

## Usage

1. **Run the Program**: Compile and run the program.
2. **Enter Date Information**: Provide day, month, and year values as requested.
3. **Choose Increment Options**: After entering the date, the program displays various date manipulations, showing the result after each operation.

## Example Output

