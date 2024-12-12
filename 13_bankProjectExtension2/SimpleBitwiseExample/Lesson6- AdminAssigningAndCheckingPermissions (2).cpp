

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

short int GrantReadPermissionToUser(short int& UserPermission)
{
	short int Number = 0;
	short int GetPermission = 0;
	char answer = ' ';


	cout << "\n\nDo you want to Grant Read Permission to User? : ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		GetPermission = GrantPermission(UserPermission, enPermission::Read);
	}
	else
	{
		GetPermission = GrantPermission(UserPermission, enPermission::NoPermissions);
	}

	return GetPermission;
}

short int GrantWritePermissionToUser(short int& UserPermission)
{
	short int Number = 0;
	short int GetPermission = 0;
	char answer = ' ';


	cout << "\n\nDo you want to Grant Write Permission to User? : ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		GetPermission = GrantPermission(UserPermission, enPermission::write);
	}
	else
	{
		GetPermission = GrantPermission(UserPermission, enPermission::NoPermissions);
	}

	return GetPermission;
}

short int GrantExecutPermissionToUser(short int& UserPermission)
{
	short int Number = 0;
	short int GetPermission = 0;
	char answer = ' ';


	cout << "\n\nDo you want to Grant Execut Permission to User? : ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		GetPermission = GrantPermission(UserPermission, enPermission::Execut);
	}
	else
	{
		GetPermission = GrantPermission(UserPermission, enPermission::NoPermissions);
	}

	return GetPermission;
}

short int GrantEditPermissionToUser(short int& UserPermission)
{
	short int Number = 0;
	short int GetPermission = 0;
	char answer = ' ';


	cout << "\n\nDo you want to Grant Edit Permission to User? : ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		GetPermission = GrantPermission(UserPermission, enPermission::Edit);
	}
	else
	{
		GetPermission = GrantPermission(UserPermission, enPermission::NoPermissions);
	}

	return GetPermission;
}

short int GrantSharePermissionToUser(short int& UserPermission)
{
	short int Number = 0;
	short int GetPermission = 0;
	char answer = ' ';


	cout << "\n\nDo you want to Grant Share Permission to User? : ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		GetPermission = GrantPermission(UserPermission, enPermission::Share);
	}
	else
	{
		GetPermission = GrantPermission(UserPermission, enPermission::NoPermissions);
	}

	return GetPermission;
}

short int GrantDeletePermissionToUser(short int& UserPermission)
{
	short int Number = 0;
	short int GetPermission = 0;
	char answer = ' ';


	cout << "\n\nDo you want to Grant Delete Permission to User? : ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		GetPermission = GrantPermission(UserPermission, enPermission::Delete);
	}
	else
	{
		GetPermission = GrantPermission(UserPermission, enPermission::NoPermissions);
	}

	return GetPermission;
}
short int GiffingPermissionsToUser(short int& UserPermission)
{
	short int NumberPermissions = 0;
	cout << "\t\t\tEnter 'Y' to Yes, 'N' to No\n";

	NumberPermissions = GrantReadPermissionToUser(UserPermission);
	NumberPermissions = GrantWritePermissionToUser(UserPermission);
	NumberPermissions = GrantExecutPermissionToUser(UserPermission);
	NumberPermissions = GrantEditPermissionToUser(UserPermission);
	NumberPermissions = GrantSharePermissionToUser(UserPermission);
	NumberPermissions = GrantDeletePermissionToUser(UserPermission);

	return NumberPermissions;

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

	User1Permission = GiffingPermissionsToUser(User1Permission);

	cout << "\n\nUser's Permissions is:\n";
	cout << PrintTypeOfPermission(User1Permission) << "\n" << endl;


	return 0;
}
