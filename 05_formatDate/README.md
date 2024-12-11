

➡ Program Overview :

This program takes a date in dd/mm/yyyy format as input and converts it into 6 different date formats.
 It allows flexibility to modify or add custom formats as needed.
Functions Explained


    vector<string> splitString(string wordToSplit, string spreator)

    Splits a string into parts based on a specified separator.

    string readDate()

    Reads a date input from the user in dd/mm/yyyy format.

    stDate stringToDate(string dateAsString)

    Converts a date string into a stDate structure with day, month, and year values.

    string reverseSring(string word)

    Reverses a given string. (Unused in this project but included in case of future use.)

    string replaceWordInString(string s1, string toReplace, string replaceTo)

    Replaces all occurrences of a specific word in a string with a new value.

    string formatDate(stDate date, string formatType)

    Formats the date into the desired structure by replacing placeholders like dd, mm, and yyyy with the actual day, month, and year.

How It Works

    The user inputs a date in the dd/mm/yyyy format.

    The program converts the input into a date structure.

    The date is displayed in 6 different formats:
        dd/mm/yyyy
        yyyy/mm/dd
        mm/dd/yyyy
        dd-mm-yyyy
        mm-dd-yyyy
        Day:dd, Month: mm, Year: yyyy

    You can easily modify the code to include only the formats you need or define custom formats.