
#include <iostream>
using namespace std;

// Define permissions using bitwise flags (powers of 2)

const int READ = 1 << 0;    // 1 in binary (0001)
const int WRITE = 1 << 1;   // 2 in binary (0010)
const int EXECUTE = 1 << 2; // 4 in binary (0100)

int main() {
    int userPermissions = 0; // Start with no permissions

    // Grant READ and WRITE permissions

    userPermissions |= READ;
    userPermissions |= WRITE;

    // Check if user has READ permission

    if (userPermissions & READ)
    {
        cout << "User has READ permission" << endl;
    }
    else
    {
        cout << "User does not have READ permission" << endl;
    }

    // Check if user has EXECUTE permission

    if (userPermissions & EXECUTE)
    {
        cout << "User has EXECUTE permission" << endl;
    }
    else
    {
        cout << "User does not have EXECUTE permission" << endl;
    }

    return 0;
}
