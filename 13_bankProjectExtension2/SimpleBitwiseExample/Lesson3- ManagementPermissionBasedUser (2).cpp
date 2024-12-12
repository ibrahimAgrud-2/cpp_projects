#include <iostream>
#include <vector>
using namespace std;

// Permission constants (bit masks)
const int READ = 1 << 0;   // Binary: 0001
const int WRITE = 1 << 1;  // Binary: 0010
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

// Function to display current permissions

void displayPermissions(int userID, int permissions)
{
    cout << "User " << userID << " permissions:" << endl;

    if (hasPermission(permissions, READ))
    {
        cout << "Read permission is granted." << endl;
    }

    if (hasPermission(permissions, WRITE))
    {
        cout << "Write permission is granted." << endl;
    }

    if (hasPermission(permissions, EXECUTE))
    {
        cout << "Execute permission is granted." << endl;
    }

    if (permissions == 0)
    {
        cout << "No permissions granted." << endl;
    }

}

int main()
{
    const int numUsers = 5;

    vector<int> userPermissions(numUsers, 0);       // Initialize permissions for all users to 0
                                                    // Assign permissions:
                                                    // User 0 gets full permissions (read, write, execute)

    userPermissions[0] = READ | WRITE | EXECUTE;

    // Users 1 and 2 get read and write permissions

    userPermissions[1] = READ | WRITE;

    userPermissions[2] = READ | WRITE;

    // Users 3 and 4 get only read permission

    userPermissions[3] = READ;

    userPermissions[4] = READ;

    // Display each user's permissions

    for (int i = 0; i < numUsers; ++i)
    {
        displayPermissions(i, userPermissions[i]);
        cout << endl;
    }

    return 0;
}
