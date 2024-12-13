#                 📅  Number of Overlap Days

This project calculates the number of overlapping days between two time periods provided by the user. The user inputs two date ranges in the format `dd/mm/yyyy`, and the program determines if the periods overlap and how many days are common between the two ranges.

For example:
- **Period 1**: 10/01/2022 --- 20/01/2022
- **Period 2**: 05/01/2022 --- 25/01/2022

These two periods overlap 15 days  , and the program calculates the exact number of overlapping days.

---

## 💻  Example Output

Given the input:

```
Period 1: 10/01/2022 to 20/01/2022
Period 2: 05/01/2022 to 25/01/2022
```

The program output will be:

```
The two periods overlap for 10 days.

```

Output : 

```
--> period 1 :

**Enter start date :

Please enter a Day? 10
Please enter a Month? 01
Please enter a Year? 2022

***Enter end date :

Please enter a Day? 20
Please enter a Month? 01
Please enter a Year? 2022


--> period 2 :

**Enter start date :

Please enter a Day? 05
Please enter a Month? 01
Please enter a Year? 2022

***Enter end date :

Please enter a Day? 25
Please enter a Month? 01
Please enter a Year? 2022


The number of overlap days is : 10
```

---



## 🚀  Features

The program includes several functions to handle date manipulations and overlap checks:

### 1. **clear()**
- Clears the terminal screen.
- If your IDE does not support this function or gives an error, you can safely **remove** it.

### 2. **IsDate1EqualsDate2(stDate date1, stDate date2)**
- Compares two dates to check if the first date occurs before the second date.

### 3. **swapDates()**
- Swaps two dates to ensure that the earlier date comes first.

### 4. **isLastDayInMonth()**
- Checks if the given day is the last day of the respective month.

### 5. **IncreaseDateByOneDay()**
- Adds one day to the given date.

### 6. **getDifferenceInDays()**
- Calculates the difference in days between two dates.

### 7. **isPeriodsOverlap()**
- Determines whether two date periods overlap.
- Uses other helper functions to verify the overlap.

### 8. **countOverlapDays()**
- If the periods overlap, this function calculates and returns the number of overlapping days.

---

## ⚙️ How It Works
1. The user inputs two time periods in the format `dd/mm/yyyy`.
2. The program checks if the two periods overlap.
3. If they overlap, it calculates the number of common days and prints the result.



---

## ⚠️ Notes
- Dates should be entered in the format `dd/mm/yyyy`.
- If the periods do not overlap, the program will inform the user.

---

## 🛠️ Requirements
- Basic understanding of date structures and programming concepts.
- Compatible IDE/terminal that supports the `clear()` function (optional).

---

## Future Improvements
- Adding input validation for incorrect date formats.
- Extending support for other date formats (e.g., `mm-dd-yyyy`).

---

## Author
This project was created as part of a practice to understand date manipulations and overlapping period calculations.