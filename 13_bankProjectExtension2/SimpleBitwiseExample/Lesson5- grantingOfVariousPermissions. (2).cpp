

#include <iostream>
#include<string>

using namespace std;

enum enPermission { NoPermissions = 0, Read = 1 << 0, write = 1 << 1, Execut = 1 << 2, Edit = 1 << 3, Share = 1 << 4, Delete = 1 << 5 };


short int GrantPermission(short int& UserPermission, enPermission TypePermission)
{
	return (UserPermission |= int(TypePermission));
}

bool CheckPermission(short int UserPermission, enPermission TypePermission)
{
	return (UserPermission & int(TypePermission));
}
short int GrantPermissionToUser(short int& UserPermission)
{
	short int Number = 0;
	short int GetPermission = 0;
	cout << "Please Choose Permission(s) : ";
	cin >> Number;
	while (Number != 0 && Number != 1 && Number != 2 && Number != 4 && Number != 8 && Number != 16 && Number != 32)
	{
		cout << "The Entered is Wrong, Most be One Of List above, try again: ";
		cin >> Number;
	}

	GetPermission = GrantPermission(UserPermission, enPermission(Number));
	return GetPermission;
}
short int GiffinPermissionsToUser(short int& UserPermission)
{
	short int Number = 0;
	char ans = ' ';
	cout << "You Can Get Grant Permission, 1 or All Off these:\n";
	cout << "\nRead=1\t\twrite=2\nExecut=4\tEdit=8\nShare=16\tDelete=32\n\nNo Permissions=0\n\n";
	do
	{
		Number = GrantPermissionToUser(UserPermission);
		cout << "\nDo You want Get more Permissions (y/n) ? ";
		cin >> ans;
	} while (tolower(ans) == 'y');

	return Number;
}

string PrintTypeOfPermission(short int UserPermission)
{
	string permissions = "";

	if (UserPermission == enPermission::NoPermissions)
		return "No Permissions";

	if (CheckPermission(UserPermission, enPermission::Read))
		permissions += "Read ";

	if (CheckPermission(UserPermission, enPermission::write))
		permissions += "Write ";

	if (CheckPermission(UserPermission, enPermission::Execut))
		permissions += "Execute ";

	if (CheckPermission(UserPermission, enPermission::Edit))
		permissions += "Edit ";

	if (CheckPermission(UserPermission, enPermission::Share))
		permissions += "Share ";

	if (CheckPermission(UserPermission, enPermission::Delete))
		permissions += "Delete ";

	return permissions.empty() ? "No Permissions" : permissions;
}
int main()
{

	short int User1Permission = 0, User2 = 0, User3 = 0;

	User1Permission = GiffinPermissionsToUser(User1Permission);

	cout << "\n\nUser's Permissions is:\n";
	cout << PrintTypeOfPermission(User1Permission) << "\n" << endl;


	return 0;
}
