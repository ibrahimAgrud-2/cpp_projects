#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct stUser
{
    string UserName;
    string Password;
    int Permissions;
    bool MarkForDelete = false;
};