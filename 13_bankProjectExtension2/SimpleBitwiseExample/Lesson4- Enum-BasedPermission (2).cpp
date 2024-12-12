#include <iostream>

enum Permissions { READ = 1 << 0, WRITE = 1 << 1, EXECUTE = 1 << 2, DELETE = 1 << 3 };

bool hasPermission(int userPermissions, Permissions requiredPermission)
{
    return (userPermissions & int(requiredPermission));
}

int main()
{
    int user1Permissions = int(READ | WRITE);
    int user2Permissions = int(EXECUTE);

    if (hasPermission(user1Permissions, READ))
    {
        std::cout << "User 1 has write permission.\n";
    }

    if (!hasPermission(user2Permissions, WRITE))
    {
        std::cout << "User 2 does not have write permission.\n";
    }

    return 0;
}