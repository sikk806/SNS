#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

class SignUp{
private:
    std::string id;
    std::string pw;

public:
    // SignUp();
    SignUp(std::string id, std::string pw);
    ~SignUp();
    
    std::string get_id_() {return this->id;}
    std::string get_pw_() {return this->pw;}

    void sign_up_user_();
    bool is_exist_user_(std::string _id);
    bool is_correct_id_(std::string _id);
    bool is_correct_pw_(std::string _pw);

    bool sign_up_main_();
};