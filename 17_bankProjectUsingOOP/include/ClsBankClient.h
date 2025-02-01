
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
#include "clsPerson.h"
#include "clsString.h"

string fileName = "Client.txt";

class clsBankClient : public clsPerson
{
	enum enMode
	{
		emptyMode = 0,
		updateMode = 1,
		AddNewMode = 2
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
		return clsBankClient(enMode::updateMode, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5], stoi(vString[6]));
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
				if (line=="")
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
	
	static string _ConvertClinetObjecttoLine(clsBankClient client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord = client.firstName() + Seperator;
		stClientRecord += client.lastName() + Seperator;
		stClientRecord += client.email() + Seperator;
		stClientRecord += client.phone() + Seperator;
		stClientRecord += client.accountNumber() + Seperator;
		stClientRecord += client.pincCode() + Seperator;
		stClientRecord += to_string(client.accountBalance());

		return stClientRecord;
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
	bool markForDeleted()
	{
		return _markForDelete;
	}
	void _upDate()
	{
		vector<clsBankClient> _vClient;
		_vClient = _loadDataFromFile("Clients.txt");
		for (clsBankClient& C : _vClient)
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

public:

	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountnumber, string pincode, float accountBalance) : clsPerson(firstName, lastName, email, phone)
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

	float accountBalance()
	{
		return _accountBalance;
	}

	/*void Print()
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
	static vector <clsBankClient> getClientsList()
	{
		return _loadDataFromFile(fileName);
	}
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

//enSaveResults -- for save process information 
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
		vector<clsBankClient>vClient = _loadDataFromFile(fileName);
		
		for (clsBankClient &i : vClient)
		{
			if (i.accountNumber() == _accountNumber)
			{
				i._markForDelete = true;
				break;
			}

		}

		_SaveCleintsDataToFile(vClient);
		*this = _getEmtyClientObject();
		return true;

	}
};

