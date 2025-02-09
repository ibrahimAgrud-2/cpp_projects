#ifndef CLSUTIL_H
#define CLSUTIL_H

#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
#include "clsString.h"

using namespace std;

class clsUtil
{

public:
	enum enCharType
	{
		samallLetter = 1,
		capitalLetter = 2,
		digit = 3,
		mixChars = 4,
		specialCharacter = 5
	};

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static char getRandomCharacter(enCharType charType)
	{
		if (charType == mixChars)
		{
			charType = (enCharType)randomNumber(1, 3);
		}
		switch (charType)
		{
		case samallLetter:
			return (char)randomNumber(97, 122);
		case capitalLetter:
			return (char)randomNumber(65, 90);
		case specialCharacter:
			return (char)randomNumber(33, 47);
		case digit:
			return (char)randomNumber(48, 57);
		default:
			return (char)randomNumber(65, 90);
		}
	}
	static int randomNumber(int to, int from)
	{
		int randNumber = rand() % (to - from + 1) + from;
		return randNumber;
	}
static string generateWord(enCharType charType,short wordLength)
{
	string word="";
	for (short i = 0; i < wordLength; i++)
	{
		word+=word+getRandomCharacter(charType);
	}
return word;

}

	static string NumberToText(long Number)
	{
		if (Number > 0 && Number <= 19)
		{
			// Array of number names for 1-19
			string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
							"Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
							"Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
			return arr[Number]; // Returns the corresponding text
		}
		else if (Number > 19 && Number < 100)
		{
			// Array of tens (20, 30, ..., 90)
			string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
			return arr[Number / 10] + " " + NumberToText(Number % 10); // Combines tens and units
		}
		else if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100); // Handles numbers from 100 to 199
		}
		else if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100); // Handles hundreds
		}
		else if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000); // Handles numbers from 1000 to 1999
		}
		else if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000); // Handles thousands up to 999,999
		}
		else if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000); // Handles numbers from 1 million to 1,999,999
		}
		else if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000); // Handles millions
		}
		else if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000); // Handles numbers from 1 billion to 1,999,999,999
		}
		else
		{
			return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000); // Handles billions
		}
	}

	static string encryptStringWords(string word, short key = 3)
	{

		for (short i = 0; i < word.size(); i++)
		{

			word[i] = char(word[i] + key);
		}

		return word;
	}
	static string decryptStringWords(string word, short key = 3)
	{
		string encryptedWord = "";
		char a;
		for (short i = 0; i < word.size(); i++)
		{

			a = word[i] - key;
			encryptedWord += a;
		}

		return encryptedWord;
	}

	static int encryptNumber(int sayi, short key = 2)
	{
		string encriptedNubmer = "";
		vector<int> vInt;
		while (sayi > 0)
		{
			vInt.push_back((sayi % 10) + key);
			sayi = sayi / 10;
		}

		for (short i = vInt.size() - 1; i >= 0; i--)
		{
			encriptedNubmer += to_string(vInt[i]);
		}
		return stoi(encriptedNubmer);
	}

	static int decryptNumber(int sayi, short key = 2)
	{
		string encriptedNubmer = "";
		vector<int> vInt;
		while (sayi > 0)
		{
			vInt.push_back((sayi % 10) - key);
			sayi = sayi / 10;
		}

		for (short i = vInt.size() - 1; i >= 0; i--)
		{
			encriptedNubmer += to_string(vInt[i]);
		}
		return stoi(encriptedNubmer);
	}
};

#endif