#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class User{
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

void sign_up_user_(User _user){     //  회원가입에 쓰이는 함수, User 객체를 받아와서 파일에 맨 뒤에다가 입력
    string _id = _user.getId();
    string _pw = _user.getPw();
    fstream member_list;
    member_list.open("member_information.txt", ios::app);
    member_list << _id;
    member_list.put('/');
    member_list << _pw;
    member_list.put('\n');
}

bool is_exist_user_(User _user){        //  회원가입 전에 이미 등록된 아이디가 있는지 확인하는 함수 -> 객체로 확인
    string _id = _user.getId();
    // string pw = user.getPw();
    fstream _member_list;
    _member_list.open("member_infromation.txt", ios::in);
    string _member_info;     //  member_info -> buffer
    bool _flag = false;
    while(getline(_member_list, _member_info)){
        int _id_idx = _member_info.find_first_of('/');
        string _compare_id = _member_info.substr(0, _id_idx);
        if(_id == _compare_id){
            _flag = true;
            break;
        }
    }
    return _flag;
}

bool is_exist_user_(string _user){        //  회원가입 전에 이미 등록된 아이디가 있는지 확인하는 함수 -> 아이디로 확인
    string _id = _user;
    fstream _member_list;
    _member_list.open("member_infromation.txt", ios::in);
    string _member_info;     //  member_info -> buffer
    bool _flag = false;
    while(getline(_member_list, _member_info)){
        int _id_idx = _member_info.find_first_of('/');
        string _compare_id = _member_info.substr(0, _id_idx);
        if(_id == _compare_id){
            _flag = true;
            break;
        }
    }
    return _flag;
}

bool is_correct_id_(string _id){        //  사용자가 입력한 id 가 적절한 id인지를 검사하는 함수
    bool _flag = true;
    int _len = _id.length();
    if(_len >= 7 && _len <= 14){      //  길이가 만족한 애들만 올바른 문자인지 검사
        for (int i = 0; i < _len; i++){
            if((_id[i] >= 'A' && _id[i] <= 'Z') || (_id[i] >= 'a' && _id[i] <= 'z') || (_id[i] >= '0' && _id[i] <= '9'))
                continue;
            else{
                _flag = false;
                break;
            }
        }
        
    }
    else
        _flag = false;
    return _flag;
}

bool is_correct_pw_(string _pw){
    bool _flag = true;
    int _len = _pw.length();
    if(_len >= 7 && _len <= 14){      //  길이가 만족한 애들만 올바른 문자인지 검사
        for (int i = 0; i < _len; i++){
            if(_pw[i] >= 33 && _pw[i] <= 126)       //  특수문자, 숫자, 소문자, 대문자
                continue;
            else{
                _flag = false;
                break;
            }
        }
        
    }
    else
        _flag = false;
    return _flag;
}