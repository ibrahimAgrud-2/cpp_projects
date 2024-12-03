#include <iostream>
#include <string>
using namespace std;

int readNumber() {
    int num;
    cout << "enter a number\n";
    cin >> num; // Takes user input for a number
    return num; // Returns the inputted number
}

string NumberToText(long Number) {
    if (Number > 0 && Number <= 19) {
        // Array of number names for 1-19
        string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                         "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                         "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        return arr[Number]; // Returns the corresponding text
    }
    else if (Number > 19 && Number < 100) {
        // Array of tens (20, 30, ..., 90)
        string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        return arr[Number / 10] + " " + NumberToText(Number % 10); // Combines tens and units
    }
    else if (Number >= 100 && Number <= 199) {
        return "One Hundred " + NumberToText(Number % 100); // Handles numbers from 100 to 199
    }
    else if (Number >= 200 && Number <= 999) {
        return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100); // Handles hundreds
    }
    else if (Number >= 1000 && Number <= 1999) {
        return "One Thousand " + NumberToText(Number % 1000); // Handles numbers from 1000 to 1999
    }
    else if (Number >= 2000 && Number <= 999999) {
        return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000); // Handles thousands up to 999,999
    }
    else if (Number >= 1000000 && Number <= 1999999) {
        return "One Million " + NumberToText(Number % 1000000); // Handles numbers from 1 million to 1,999,999
    }
    else if (Number >= 2000000 && Number <= 999999999) {
        return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000); // Handles millions
    }
    else if (Number >= 1000000000 && Number <= 1999999999) {
        return "One Billion " + NumberToText(Number % 1000000000); // Handles numbers from 1 billion to 1,999,999,999
    }
    else {
        return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000); // Handles billions
    }
}

int main() {
    while (true) {
        cout << NumberToText(readNumber()) << endl; // Outputs the text equivalent of the input
        system("pause"); // Pauses for user to read the output
    }
    return 0;
}
