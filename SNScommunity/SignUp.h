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

void signUpUser(User user){     //  회원가입에 쓰이는 함수, User 객체를 받아와서 파일에 맨 뒤에다가 입력
    string id = user.getId();
    string pw = user.getPw();
    fstream member_list;
    member_list.open("member_information.txt", ios::app);
    member_list << id;
    member_list.put('/');
    member_list << pw;
    member_list.put('\n');
}

bool isExistUser(User user){        //  회원가입 전에 이미 등록된 아이디가 있는지 확인하는 함수
    string id = user.getId();
    // string pw = user.getPw();
    fstream member_list;
    member_list.open("member_infromation.txt", ios::in);
    string member_info;     //  member_info -> buffer
    bool flag = false;
    while(getline(member_list, member_info)){
        int id_idx = member_info.find_first_of('/');
        string compare_id = member_info.substr(0, id_idx);
        if(id == compare_id){
            flag = true;
            break;
        }
    }
    return flag;
}