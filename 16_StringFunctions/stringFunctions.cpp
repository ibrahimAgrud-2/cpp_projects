// Function to get the length of the 'selam' string object.
short Length()
{
    return selam.length();
};

// Function to count the number of words in the given string `S1`.
short CountWords(string S1)
{
    string delim = " "; // delimiter  
    short Counter = 0;
    short pos = 0;
    string sWord; // define a string variable  

    // Split string by space and count non-empty words.
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            Counter++;
        }

        // Remove the word found.
        S1.erase(0, pos + delim.length());
    }

    // Count the last word if any.
    if (S1 != "")
    {
        Counter++;
    }

    return Counter;
}

// Function to capitalize the first letter of each word in the string `S1`.
string UpperFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    // Traverse the string and change the first letter of each word to uppercase.
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }

        isFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

// Function to convert the first letter of each word to lowercase.
string LowerFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    // Traverse the string and change the first letter of each word to lowercase.
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }

        isFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

// Function to convert all letters in the string `S1` to uppercase.
string UpperAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

// Function to convert all letters in the string `S1` to lowercase.
string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

// Function to invert the case of a given character.
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

// Enum to specify what kind of letters to count (small, capital, or all).
enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

// Function to count specific types of letters (small, capital, or all) in the string `S1`.
short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }

    short Counter = 0;

    // Count capital letters if the option is set.
    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            Counter++;

        // Count small letters if the option is set.
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            Counter++;
    }

    return Counter;
}

// Function to count capital (uppercase) letters in the string `S1`.
short CountCapitalLetters(string S1)
{
    short Counter = 0;

    // Count all capital letters.
    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }

    return Counter;
}

// Function to count small (lowercase) letters in the string `S1`.
short CountSmallLetters(string S1)
{
    short Counter = 0;

    // Count all small letters.
    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Counter++;
    }

    return Counter;
}

// Function to count the occurrences of a specific letter (case-sensitive or insensitive) in the string `S1`.
short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            // Match case exactly.
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            // Match letter case-insensitively.
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }

    return Counter;
}

// Function to check if the character `Ch1` is a vowel (a, e, i, o, u).
bool IsVowel(char Ch1)
{
    Ch1 = tolower(Ch1);

    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

// Function to count the number of vowels in the string `S1`.
short CountVowels(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            Counter++;
    }

    return Counter;
}

// Function to split the string `S1` by the delimiter `Delim` and return a vector of words.
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable  

    // Use find() function to get positions of delimiters and split the string.
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  // Remove the word found.
    }

    // Add last word if any.
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

// Function to remove leading spaces from the string `S1`.
string TrimLeft(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
    return "";
}

// Function to remove trailing spaces from the string `S1`.
string TrimRight(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}

// Function to remove both leading and trailing spaces from the string `S1`.
string Trim(string S1)
{
    return (TrimLeft(TrimRight(S1)));
}

// Function to join a vector of strings `vString` into a single string separated by `Delim`.
string JoinString(vector<string> vString, string Delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length()); // Remove the last delimiter.
}

// Function to join an array of strings `arrString` into a single string separated by `Delim`.
string JoinString(string arrString[], short Length, string Delim)
{
    string S1 = "";

    for (short i = 0; i < Length; i++)
    {
        S1 = S1 + arrString[i] + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length()); // Remove the last delimiter.
}

// Function to reverse the order of words in the string `S1`.
string ReverseWordsInString(string S1)
{
    vector<string> vString;
    string S2 = "";

    vString = SplitString(S1, " ");

    // Reverse the order of words.
    vector<string>::iterator iter = vString.end();
    while (iter != vString.begin())
    {
        --iter;
        S2 += *iter + " ";
    }

    S2 = S2.substr(0, S2.length() - 1); // Remove last space.
    return S2;
}

// Function to replace all occurrences of `StringToReplace` with `sRepalceTo` in the string `S1`.
string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
    vector<string> vString = SplitString(S1, " ");

    for (
