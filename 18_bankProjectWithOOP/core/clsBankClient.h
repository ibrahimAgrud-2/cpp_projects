#ifndef CLSBANKCLIENT_H
#define CLSBANKCLIENT_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include"global.h"

string fileName = "vsClient.txt";

class clsBankClient : public clsPerson
{

public:
	struct stTransferRegisterRecord
	{
		// 2025/1/24 - 14:19:32#//#A102#//#A101#//#1000.000000#//#26807.000000#//#1000.000000#//#admin2

		string sDateAndTime;
		string accountNumberClient1;
		string accountNumberClinet2;
		float transferdAmount;
		float clinet1AccountBalance;
		float client2AccountBalance;
		string performedby;
	};

	enum enMode
	{
		emptyMode = 0,
		updateMode = 1,
		AddNewMode = 2,

	};

	enMode _mode;
	string _accountNumber;
	string _pinCode;
	float _accountBalance;
	bool _markForDelete = false;
	// create emptye object
	static clsBankClient _getEmtyClientObject()
	{
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0.0);
	}

	static clsBankClient _convertLineToClinetObject(string line, string sperator = "#//#")
	{
		// Mohammed#//#Abu-Hadhoud#//#Mo@gmail.com#//#0799997886#//#A101#//#1234#//#5000.000000

		vector<string> vString = clsString::Split(line, sperator);
	

		return clsBankClient(enMode::updateMode, vString[0], vString[1], vString[2], vString[3], vString[4], clsUtil::decryptStringWords(vString[5]), stoi(vString[6]));
	}
	static string _ConvertClinetObjecttoLine(clsBankClient client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord = client.firstName() + Seperator;
		stClientRecord += client.lastName() + Seperator;
		stClientRecord += client.email() + Seperator;
		stClientRecord += client.phone() + Seperator;
		stClientRecord += client.accountNumber() + Seperator;
		stClientRecord += clsUtil::encryptStringWords(client.pincCode()) + Seperator;
		stClientRecord += to_string(client.accountBalance());

		return stClientRecord;
	}

	static vector<clsBankClient> _loadDataFromFile(string fileName)
	{
		vector<clsBankClient> vClient;

		fstream file;
		file.open(fileName, ios::in);
		if (file.is_open())
		{
			string line = "";
			while (getline(file, line))
			{

				if (line == "")
				{
					continue;
				}
				clsBankClient client = _convertLineToClinetObject(line);
				vClient.push_back(client);
			}
			file.close();
		}
		else
		{
			cout << "File could not open ---> Func.Name : _loadDataFromFile \n";
			system("pause>0");
		}
		return vClient;
	}



	static void _SaveCleintsDataToFile(vector<clsBankClient> vClient)
	{
		fstream file;
		file.open(fileName, ios::out);
		if (file.is_open())
		{
			string line = "";
			for (clsBankClient C : vClient)
			{
				if (C.markForDeleted() == false)
				{
					line = _ConvertClinetObjecttoLine(C);
					file << line << endl;
				}
			}
			file.close();
		}
		else
		{
			cout << "File could not open \n";
			system("pause>0");
		}
	}
	void _upDate()
	{
		vector<clsBankClient> _vClient;
		_vClient = _loadDataFromFile(fileName);
		for (clsBankClient &C : _vClient)
		{
			if (C.accountNumber() == _accountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClient);
	}
	void _addDateLineToFile(string line)
	{
		fstream file;
		file.open(fileName, ios::out | ios::app);
		if (file.is_open())
		{
			file << line << endl;
			file.close();
		}
		else
		{
			cout << "File could not open ---> _addDateLineToFile() \n ";
			system("pause>0");
		}
	}
	void _addNew()
	{
		_addDateLineToFile(_ConvertClinetObjecttoLine(*this));
	}

	string _prepareTransferLogInRecord(clsBankClient destinationClient, double amount, string seperator = "#//#")
	{
		string line = clsDate::getSystemDateAsString() + " - ";
		line += clsDate::getSystemTimeAsString() + seperator;
		line += _accountNumber + seperator;
		line += destinationClient.accountNumber() + seperator;
		line += to_string(amount) + seperator;
		line += to_string(_accountBalance) + seperator;
		line += to_string(destinationClient.accountBalance()) + seperator;
		line += currentUser.userName();
		return line;
	}
	void LoginTransferReigster(clsBankClient destinationClient, double amount)
	{
		string line = _prepareTransferLogInRecord(destinationClient, amount);
		fstream file;

		file.open("vstransferRegister.txt", ios::out | ios::app);
		if (file.is_open())
		{
			file << line << endl;
			file.close();
		}
		else
		{
			cout << "File could not open in function LoginTransferReigster\n";
		}
	}
	static stTransferRegisterRecord _ConvertTransferRegisterLineToRecord(string line, string sperator = "#//#")
	{

		stTransferRegisterRecord transferRegister;
		vector<string> vString = clsString::Split(line, sperator);

		transferRegister.sDateAndTime = vString[0];
		transferRegister.accountNumberClient1 = vString[1];
		transferRegister.accountNumberClinet2 = vString[2];
		transferRegister.transferdAmount = stof(vString[3]);
		transferRegister.clinet1AccountBalance = stof(vString[4]);
		transferRegister.client2AccountBalance = stof(vString[5]);
		transferRegister.performedby = vString[6];
		return transferRegister;
	}

public:
	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountnumber,
	string pincode, float accountBalance) : clsPerson(firstName, lastName, email, phone)
	{
		_mode = mode;
		_accountBalance = accountBalance;
		_accountNumber = accountnumber;
		_pinCode = pincode;
	}

	bool isEmpty()
	{
		return (_mode == enMode::emptyMode);
	}

	// Read only
	string accountNumber()
	{
		return _accountNumber;
	}
	void setPinCode(string pinCode)
	{
		_pinCode = pinCode;
	}

	string pincCode()
	{
		return _pinCode;
	}

	void setAccountBalance(float amount)
	{
		_accountBalance = amount;
	}
	bool markForDeleted()
	{
		return _markForDelete;
	}
	float accountBalance()
	{
		return _accountBalance;
	}

	/*No UI Related code inside object

	void Print()
	{
		cout << "\n Client Card:\n";
		cout << "____________________\n";
		cout << "\nFirstName   : " << firstName();
		cout << "\nLastName    : " << lastName();
		cout << "\nFull Name   : " << fullName();
		cout << "\nEmail       : " << email();
		cout << "\nPhone       : " << phone();
		cout << "\nAcc. Number : " << _accountNumber;
		cout << "\nPassword    : " << _pinCode;
		cout << "\nBalance     : " << _accountBalance;
		cout << "\n___________________\n";
	}*/

	// static finde function we  can  calling  without creating an object from anywhere
	static clsBankClient find(string accountNumber)
	{
		// Bu vector neden var bir en sona bir bak
		vector<clsBankClient> vClients;

		fstream file;
		file.open(fileName, ios::in); // read mode
		if (file.is_open())
		{

			string line = "";
			while (getline(file, line))
			{
				clsBankClient client = _convertLineToClinetObject(line);
				if (client.accountNumber() == accountNumber)
				{
					file.close();
					return client;
				}

				vClients.push_back(client);
			}

			file.close();
		}
		return _getEmtyClientObject();
	}
	static clsBankClient find(string accountNumber, string password)
	{

		vector<clsBankClient> vClients;

		fstream file;
		file.open(fileName, ios::in); // read mode
		if (file.is_open())
		{

			string line = "";
			while (getline(file, line))
			{
				clsBankClient client = _convertLineToClinetObject(line);
				if ((client.accountNumber() == accountNumber) && (client.pincCode() == password))
				{
					file.close();
					return client;
				}

				vClients.push_back(client);
			}

			file.close();
		}
		return _getEmtyClientObject();
	}

	static bool isClietnExist(string accountNumber)
	{
		clsBankClient clietn1 = clsBankClient::find(accountNumber);
		return (!(clietn1.isEmpty()));
	}

	// lesson #01

	// enSaveResults -- for save process information
	enum enSaveResults
	{
		svFaildEmptyOBject = 0,
		svSucceeded = 1,
		svFaildAccountNumberExists = 2
	};
	static clsBankClient getAddNewClientObject(string accountnumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", accountnumber, "", 0);
	}
	enSaveResults save()
	{
		switch (_mode)
		{
		case enMode::emptyMode:
			return enSaveResults::svFaildEmptyOBject;
		case enMode::updateMode:

			_upDate();

			return enSaveResults::svSucceeded;
		case enMode::AddNewMode:
		{
			// This will add new record to file or database
			if (clsBankClient::isClietnExist(_accountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_addNew();

				// We need to set the mode to update after add new
				// the object still in the memory so we should update the mode
				_mode = enMode::updateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}

		default:
			cout << "We got error at save funciton \n ";
			system("puase>0");
			break;
		}
	}

	bool deleteClient()
	{
		vector<clsBankClient> vClient = _loadDataFromFile(fileName);
		for (clsBankClient &i : vClient)
		{
			if (i.accountNumber() == _accountNumber)
			{
				i._markForDelete = true;
				break;
			}
		}

		_SaveCleintsDataToFile(vClient);
		// we should delete object from memory too
		*this = _getEmtyClientObject();
		return true;
	}

	static vector<clsBankClient> getClientsList()
	{
		return _loadDataFromFile(fileName);
	}

	static double getTotalBalances()
	{
		vector<clsBankClient> vClietn = _loadDataFromFile(fileName);
		double totalBalance = 0.0;
		for (clsBankClient i : vClietn)
		{
			totalBalance += i.accountBalance();
		}
		return totalBalance;
	}

	void Deposit(double amount)
	{
		_accountBalance += amount;
		save();
	}

	bool Withdraw(double amount)
	{
		if (amount <= _accountBalance)
		{
			_accountBalance -= amount;
			save();
		}
		else
		{
			return false;
		}
	}

	bool transfer(clsBankClient &transferTo, double amount)
	{
		if (amount > _accountBalance)
		{
			return false;
		}
		this->Withdraw(amount);
		transferTo.Deposit(amount);
		LoginTransferReigster(transferTo, amount);
		return true;
	}

	static vector<stTransferRegisterRecord> getTransferRegisterlist()
	{
		vector<stTransferRegisterRecord> vTransferRegisterRecord;

		fstream file;
		file.open("vsTransferRegister.txt", ios::in);
		if (file.is_open())
		{
			string line = "";
			stTransferRegisterRecord transferRegisterRecord;
			while (getline(file, line))
			{

				if (line == "")
				{
					continue;
				}
				transferRegisterRecord = _ConvertTransferRegisterLineToRecord(line);
				vTransferRegisterRecord.push_back(transferRegisterRecord);
			}
			file.close();
		}
		else
		{
			cout << "File could not open ---> Func.Name : getTransferRegisterlist\n";
			system("pause>0");
		}
		return vTransferRegisterRecord;
	}
};

#endif