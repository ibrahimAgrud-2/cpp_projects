Date Format Conversion Program
Overview

This C++ program allows users to input a date in dd/mm/yyyy format, then displays the date in various formats such as yyyy/mm/dd, mm/dd/yyyy, and others.
Features:

    Accepts a date in dd/mm/yyyy format.
    Converts and displays the date in multiple formats (yyyy/mm/dd, dd-mm-yyyy, mm-dd-yyyy, etc.).
    Allows custom formatting by replacing placeholders (dd, mm, yyyy).

Functions
splitString(string wordToSplit, string separator)

Splits a string by a specified separator and returns a vector of substrings.
readDate()

Prompts the user to input a date in dd/mm/yyyy format.
stringToDate(string dateAsString)

Converts a date string to a stDate structure.
reverseString(string word)

Reverses a given string.
replaceWordInString(string s1, string toReplace, string replaceTo)

Replaces all occurrences of a word in a string.
formatDate(stDate date, string formatType)

Formats the date into a string based on a specified format type.
