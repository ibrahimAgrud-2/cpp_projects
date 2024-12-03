#include <iostream>

using namespace std;

// Function to read a year from the user and return it as a short
short readYear() {
    int num;
    cout << "Enter a Year: ";
    cin >> num;
    return num;
}

short readMounth() {
    int num;
    cout << "Enter a Month: ";
    cin >> num;
    return num;
}
// Function to read a day from the user and return it as a short
short ReadDay() {
    short Day;
    cout << "Enter a Day: ";
    cin >> Day;
    return Day;
}


// Structure to store date information: year, month, and day
struct stDate {
    short year;
    short months;
    short days;
};
stDate readFullDate()
{
    stDate date;
    date.days = ReadDay();

    date.months = readMounth();
    date.year = readYear();
    return date;

}
// Function to check if a given year is a leap year
// Returns true if leap year, otherwise false
bool isLeapYear(short year) {
    return ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)));
}

// Function to read a month from the user and return it as a short


// Function to return the number of days in a given month and year
// Adjusts for leap years in February
int numberDaysInMounth(short Month, short year) {
    if (Month < 1 || Month > 12)
        return 0;
    short arrDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDays[Month - 1]);
}

// Function to calculate the total number of days from the start of the year to a given date
short totalDaysFromTheBigrnYear(short Day, short Month, short Year) {
    short sumOfDays = 0;
    for (short i = 1; i < Month; i++) {
        sumOfDays += numberDaysInMounth(i, Year);
    }
    return (sumOfDays + Day);
}

// Function to convert a total number of days within a year into a specific month and day
// Returns a date struct with the corresponding month and day
stDate addDayToDate(short totalDays, stDate date) {

 
    while (totalDays>0)
    {
        date.days++;
        totalDays--;
        if (date.days>numberDaysInMounth(date.months,date.year))
        {
            date.days=1;
            date.months++;

        }
        if (date.months > 12)
        {
            date.months = 1;
            date.year++;
        }
    }
    return date;
}

int main() {
 
    stDate date = readFullDate();
    short totalDays = 0;
    cout << "Enter total days to add : \n";
    cin >> totalDays;


    date = addDayToDate(totalDays, date);
    cout << "Date for [" << totalDays << "] is: ";
    cout << "" << date.days << "/" << date.months << "/" << date.year;






    cout << endl;
    cout << endl;
    cout << endl;
    system("pause");
    return 0;
}
