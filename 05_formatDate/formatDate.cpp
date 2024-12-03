#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include<vector>

using namespace std;

struct stDate
{
    int year;
    int months;
    int days;

};
vector<string> splitString(string wordToSplit, string spreator)
{
    vector<string>vStirng;

    short post = 0;
    post = wordToSplit.find(spreator);
    while (post != string::npos)
    {

        vStirng.push_back(wordToSplit.substr(0, post));
        wordToSplit = wordToSplit.erase(0, post + spreator.length());
        post = wordToSplit.find(spreator);

    }

    if (wordToSplit != "")
    {
        vStirng.push_back(wordToSplit);
    }
    return vStirng;

}

string readDate()
{
    string date;
    cout << "Pleas enter a date dd/mm/yyyy : ";
    getline(cin >> ws, date);
    return date;
}
stDate stringToDate(string dateAsString)
{
    stDate date;
    vector<string>vString = splitString(dateAsString, "/");

    date.days = stoi(vString[0]);
    date.months = stoi(vString[1]);
    date.year = stoi(vString[2]);
    return date;

}

string reverseSring(string word)
{
    string temp = "";
    for (short i = word.length() - 1; i >= 0; i--)
    {
        temp += word[i];
    }
    return temp;
}
string replaceWordInString(string s1, string toReplace, string replaceTo)
{
    short pos = s1.find(toReplace);
    while (pos != string::npos)
    {
        s1 = s1.replace(pos, toReplace.length(), replaceTo);

    
        pos = s1.find(toReplace);
       
    }

    return s1;

}
string formatDate(stDate date,string formatType)
{
    
    string Stringformat = replaceWordInString(formatType, "dd", to_string(date.days));
           Stringformat = replaceWordInString(Stringformat, "mm", to_string(date.months));
           Stringformat = replaceWordInString(Stringformat, "yyyy", to_string(date.year));


    return Stringformat;
}

int main()
{
   
 
    string  sDate = readDate();
    stDate date = stringToDate(sDate);
    cout << formatDate(date, "dd/mm/yyyy") << endl;
    cout << formatDate(date, "yyyy/mm/dd") << endl;
    cout << formatDate(date, "mm/dd/yyyy") << endl;
    cout << formatDate(date, "dd-mm-yyyy") << endl;
    cout << formatDate(date, "mm-dd-yyyy") << endl;
    cout << formatDate(date, "Day:dd, Month: mm, Year: yyyy") << endl;


    return 0;
}