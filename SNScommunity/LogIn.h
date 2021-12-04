#pragma once
#include <iostream>
#include <string>
#include <fstream>

using std::string;
class Login
{
private:
    string userID;
    string password;
public:
    ~Login();
    Login(const string& ID, const string& pw);
    void login();
};
