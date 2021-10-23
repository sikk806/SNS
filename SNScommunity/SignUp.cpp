#include "SignUp.h"

bool main_sign_up(){
    string _id, _pw;
    system("clear");  //    for mac command
    // system("cls"); //    for windows command
    cout << "==================================\n";
    cout << "아이디 : \n";
    cin >> _id;
    if(_id == "b" || _id == "B")
        return false;   //  만약 b/B 가 입력되면 false 로 return
    while(!is_correct_id_(_id)){
        cout << "잘못된 입력방십입니다\n";
        cin >> _id;
        if(_id == "b" || _id == "B")
            return false;   //  만약 b/B 가 입력되면 false 로 return
    }
    while(!is_exist_user_(_id)){
        cout << "이미 존재하는 아이디입니다\n";
        cin >> _id;
        if(_id == "b" || _id == "B")
            return false;   //  만약 b/B 가 입력되면 false 로 return
        while(!is_correct_id_(_id)){
            cout << "잘못된 입력방십입니다\n";
            cin >> _id;
            if(_id == "b" || _id == "B")
                return false;   //  만약 b/B 가 입력되면 false 로 return
        }
    }
    system("clear");
    // system("cls");
    cout << "==================================\n";
    cout << "비밀번호 : \n";
    cin >> _pw;
    if(_pw == "b" || _pw == "B")
        return false;   //  만약 b/B 가 입력되면 false 로 return
    while(!is_correct_pw_(_pw)){
        cout << "잘못된 입력방십입니다\n";
        cin >> _pw;
        if(_pw == "b" || _pw == "B")
            return false;   //  만약 b/B 가 입력되면 false 로 return
    }
    system("clear");
    // system("cls");
    User _user(_id, _pw);
    sign_up_user_(_user);
    return true;        //  올바른 return
}