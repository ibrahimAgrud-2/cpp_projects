#include <iostream>

using namespace std;
#include "clsLoginScreen.cpp"
#include "clsCurrency.cpp"
#include "clsInputValidate.cpp"
#include "clsCurrencyCalculatorScreen.cpp"





int main()
{
	
	while (sayac>0)
	{
		system("pause");
		clsLoginScreen::showLoginScreen();
	}
	
	return 0;
}