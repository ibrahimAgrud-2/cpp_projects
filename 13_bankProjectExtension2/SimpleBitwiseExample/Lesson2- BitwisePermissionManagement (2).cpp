#include <iostream>
using namespace std;

// Permission constants (bit masks)

const int READ = 1 << 0;  // Binary: 0001
const int WRITE = 1 << 1; // Binary: 0010
const int EXECUTE = 1 << 2; // Binary: 0100

// Function to check if a permission is granted

bool hasPermission(int permissions, int permission)
{
    return (permissions & permission) != 0;
}

// Function to add (set) a permission

void addPermission(int& permissions, int permission)
{
    permissions |= permission; // Use bitwise OR to set the bit
}

// Function to remove (clear) a permission

void removePermission(int& permissions, int permission)
{
    permissions &= ~permission; // Use bitwise AND with the complement to clear the bit
}

// Function to display current permissions

void displayPermissions(int permissions)
{
    cout << "Current permissions:" << endl;

    if (hasPermission(permissions, READ))
    {
        cout << "\nRead permission is granted." << endl;
    }

    if (hasPermission(permissions, WRITE))
    {
        cout << "\nWrite permission is granted." << endl;
    }

    if (hasPermission(permissions, EXECUTE))
    {
        cout << "\nExecute permission is granted." << endl;
    }

    if (permissions == 0)
    {
        cout << "\nNo permissions granted." << endl;
    }
}

int main() {
    int permissions = 0; // Start with no permissions

    // Set initial permissions

    addPermission(permissions, READ);
    addPermission(permissions, EXECUTE);



    displayPermissions(permissions);

    
    removePermission(permissions, READ); // Remove read permission

    cout << "\n\nAfter removing read permission:\n" << endl;
    displayPermissions(permissions);

    return 0;
}