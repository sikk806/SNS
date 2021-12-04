#pragma once
#include "board.h"
#include <iostream>
#include <string>
#include <fstream>
<<<<<<< HEAD
=======
#include <sstream>
#include <vector>

using namespace std;
>>>>>>> 44207a1c629cab69e37bebb3459f0749e48b34f5

using std::string;
class Login
{
private:
    string userID;
    string password;
public:
    Login();
    ~Login();
    Login(const string& ID, const string& pw);
    void login();
    int show_main_promp_();
    void main_promp();
};
