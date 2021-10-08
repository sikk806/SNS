#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User{         //  유저 클래스 정의 id, pw 만 정의 해 뒀습니다. 일단은 생성자, 소멸자, getter, setter 만 했습니다. 수정할 것 있으면 하시고 주석 부탁드려요!!
private:
    string id;
    string pw;

public:
    User();
    User(string id, string pw){
        this->id = id;
        this->pw = pw;
    }
    ~User();
    
    string getId() {return this->id;}
    string getPw() {return this->pw;}
    void setId(string id) {
        this->id = id;
    }
    void setPw(string pw) {
        this->pw = pw;
    }
};