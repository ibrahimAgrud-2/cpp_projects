#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "AtmClients.txt";
void login();
void   showAtmMenuScreen();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
sClient currentClinetInfo;


enum enAtmoption
{
    eQuickWithDrow = 1,
    eNormalWithDrow = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eShowInfo = 5,
    eTransferMoney = 6,
    eChangePinCode = 7,
    eLogout = 8
};

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}
vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}
vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;

                currentClinetInfo = C;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is : " << C.AccountBalance << "  \n";

                return true;
            }

        }


        return false;
    }
    else
    {
        return false;
    }

}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}
vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}
string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}
string ReadUserName()
{
    string Username = "";

    cout << "\nPlease enter Username? ";
    cin >> Username;
    return Username;

}
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{

    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;

}
//******************
double readAmount()
{
    double amount = 0.0;
    cin >> amount;
    while (amount < 0)
    {
        cout << "Pleas enter pozitif Amount : ";
        cin >> amount;
    }
    return amount;
}
bool isBalanceOverAmount(sClient clinet, int amount)
{
    return ((clinet.AccountBalance - amount) >= 0);
}

void QuickWithdrowAmountScreen()
{
    cout << "[1] 20\t\t";
    cout << "[2] 50\n";

    cout << "[3] 100\t\t";
    cout << "[4] 200\n";
    cout << "[5] 400\t\t";
    cout << "[6] 600 \n";
    cout << "[7] 800\t\t";
    cout << "[8] 1000\n";

    cout << "\t[9] exit\n";
    cout << "\n---------------------------------\n";
}
void changePassword()
{
    string currentPassword = "";
    vector<sClient>vClient = LoadCleintsDataFromFile(ClientsFileName);
    cout << "Enter you current Pin code : ";
    cin >> currentPassword;
    while (currentPassword != currentClinetInfo.PinCode)
    {
        cout << "Pin code invalid\nEnter Pin code : ";
        cin >> currentPassword;
    }
    cout<<"Enter New pin code : ";
    cin>>currentPassword;
    for (sClient& i : vClient)
    {
        if (i.PinCode == currentClinetInfo.PinCode)
        {
            i.PinCode = currentPassword;
            currentClinetInfo=i;
            SaveCleintsDataToFile(ClientsFileName, vClient);
            cout << "\n\nDone Successfully.";
            break;
        }

    }



}
void changePasswordScreen()
{
    cout << "\n---------------------------------\n";
    cout << "\tChange Pin Code Screen ";
    cout << "\n---------------------------------\n";
    changePassword();
}
void transferMoneyOperation()
{
    cout << "\n---------------------------------\n";
    cout << "\tTransfer proces Screen ";
    cout << "\n---------------------------------\n";
    vector<sClient>vClient = LoadCleintsDataFromFile(ClientsFileName);
    sClient client;
    bool faild = false;
    do
    {

        if (faild)
        {

            cout << "Invaild Account Number \n";
        }

        faild = !FindClientByAccountNumber(ReadClientAccountNumber(), vClient, client);
    } while (faild);
    cout << "Enter the amount : ";
    DepositBalanceToClientByAccountNumber(client.AccountNumber, readAmount(), vClient);


}

void QuickWithdrowScreen()
{

    short arrAmounts[8] = { 20,50,100,200,400,600,800,1000 };

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    bool faild = false;
    short choose = 0;

    do
    {
        faild = false;
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tQuick Withdrow Screen ";
        cout << "\n---------------------------------\n";
        QuickWithdrowAmountScreen();
        cout << "Your balance is : " << currentClinetInfo.AccountBalance << endl << endl;
        cout << "choose what to withdrow from [1-8] ? ";
        cin >> choose;
        if (choose == 9)
        {
            return;
        }
        if (!isBalanceOverAmount(currentClinetInfo, arrAmounts[choose - 1]))
        {
            cout << "\nAmount Exceeds the balance.Pleas make anohter choise\n\n\nPress any key to continue..\n";
            system("pause>0");
            faild = true;
        }
    } while (faild);

    DepositBalanceToClientByAccountNumber(currentClinetInfo.AccountNumber, -1 * arrAmounts[choose - 1], vClients);

}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

void normalWithdrowScreen()
{


    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    bool faild = false;
    int amount = 0;
    do
    {
        faild = false;
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tNormal Withdrow Screen ";
        cout << "\n---------------------------------\n";
        cout << "Enter amount multiple's 5 : ";
        amount = readAmount();
        while (amount % 5 != 0)
        {
            cout << "Enter amount multiple's 5 : ";
            amount = readAmount();
        }
        if (!isBalanceOverAmount(currentClinetInfo, amount))
        {
            cout << "\nAmount Exceeds the balance.Pleas make anohter choise\n\n\nPress any key to continue..\n";
            system("pause>0");
            faild = true;
        }


    } while (faild);


    DepositBalanceToClientByAccountNumber(currentClinetInfo.AccountNumber, -1 * amount, vClients);


}
void goBackToAtmMenu()
{
    cout << "Press any key to back atm menu...";
    system("pause>0");
    showAtmMenuScreen();
}

bool FindClientByAccountNumberAndpincode(string AccountNumber, string pinCode, sClient& Client)
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    for (sClient C : vClients)
    {

        if ((C.AccountNumber == AccountNumber) && C.PinCode == pinCode)
        {
            Client = C;
            return true;
        }

    }
    return false;

}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";


    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);




    double amount = 0;
    cout << "Enter the amount : ";
    amount = readAmount();

    DepositBalanceToClientByAccountNumber(currentClinetInfo.AccountNumber, amount, vClients);

}
void checkBalanceScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\t\t Check Screen";
    cout << "\n-----------------------------------\n";
    cout << "Your balance is : " << currentClinetInfo.AccountBalance << endl << endl;



}

void showInfoScreen()
{
    system("cls");
    cout << "\n---------------------------------\n";
    cout << "\tShow info  Screen";
    cout << "\n---------------------------------\n";
    PrintClientCard(currentClinetInfo);


}
void showEndScreen()
{
    cout << "\n---------------------------------\n";
    cout << "\t  5 Program end";
    cout << "\n---------------------------------\n";


}
bool PerfromAtmMenueOption(enAtmoption atmOPtions)
{
    switch (atmOPtions)
    {
    case enAtmoption::eQuickWithDrow:
        system("cls");
        QuickWithdrowScreen();
        goBackToAtmMenu();
        break;
    case enAtmoption::eNormalWithDrow:
        system("cls");
        normalWithdrowScreen();
        goBackToAtmMenu();
        break;
    case enAtmoption::eDeposit:
        system("cls");
        ShowDepositScreen();
        goBackToAtmMenu();
        break;
    case enAtmoption::eCheckBalance:
        system("cls");
        checkBalanceScreen();
        goBackToAtmMenu();
        break;
    case enAtmoption::eShowInfo:
        system("cls");
        showInfoScreen();
        goBackToAtmMenu();
        break;
    case enAtmoption::eTransferMoney:
        system("cls");
        transferMoneyOperation();
        goBackToAtmMenu();
        break;
    case enAtmoption::eChangePinCode:
        system("cls");
        changePasswordScreen();
        goBackToAtmMenu();
        break;
    case enAtmoption::eLogout:
        showEndScreen();
        return 0;
    default:
        cout << "\n\nError in PerfromAtmMenueOption ****\n\n";

    }

}
short ReadAtmMenueOption()
{
    cout << "Choose what do you want to do? [1 to 7]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}
void showAtmMenuScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Main  Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick withdrow.\n";
    cout << "\t[2] Nomal  withdrow.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check balance .\n";
    cout << "\t[5] Show my info .\n";
    cout << "\t[6] Transfer process  .\n";
    cout << "\t[7] change pin code  .\n";
    cout << "\t[8] Exit .\n";
    cout << "===========================================\n";
    PerfromAtmMenueOption((enAtmoption)ReadAtmMenueOption());
}




void login()
{


    bool faild = false;
    do
    {
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (faild)
        {

            cout << "Invaild password/Account Number \n";
        }
        cout << "Enter clinet Account Number : ";
        cin >> currentClinetInfo.AccountNumber;
        cout << "Enter pin code :  ";
        cin >> currentClinetInfo.PinCode;

        faild = !FindClientByAccountNumberAndpincode(currentClinetInfo.AccountNumber, currentClinetInfo.PinCode, currentClinetInfo);
    } while (faild);

    showAtmMenuScreen();
}


int main()
{
    login();

    return 0;
}