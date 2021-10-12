#include "boardPost.h"
#include <curses.h>

using namespace std;

 // string _title;
    // string _contents;
    // string _date;
    // int _report;
    // int _recommand;
    // string comment;
    // int _datanum;
    // string _userid;

boardPost::boardPost(){

}

boardPost::~boardPost(){

}


int boardPost::Report(int data){
    data +=1;
    return data;
}



void boardPost::Post(){
  
    fstream postinfo;
    postinfo.open("./data/post_1.txt", ios::in|ios::out);
    string line;
    getline(postinfo, line);
    stringstream ss(line);
    vector<string> data;

    while (getline(ss, line, '/')) {
		data.push_back(line);
	}
    while(1){
    system("clear"); // Mac용 system("cls")
    
    cout << "============================" << endl;
    cout << data[2] << endl;
    cout << "제목" << " : " << data[3] << endl;
    cout << "본문" << " : " << data[4] << endl;
    cout << "신고" << ": "<< data[5] << " 추천" << ": " << data[6] << endl;
    cout << "============================" << endl;
    cout << "댓글" << endl;
    for(int i = 7; i<data.size(); i++){
        cout << "익명"<< " : " << data[i] << endl;
    }
    cout << "============================" << endl;
    cout << "1.댓글 작성" << "/" << " 2.신고"<< "/" << " 3.추천" <<"/"<<" 4.수정"<<"/"<< " 뒤로가기(B/b)"<< endl;
    char command;
	cin >> command;

    if (command == '1') {
		//댓글 작성창
	}
    else if (command == '2') {
        cout << "신고를 하시겠습니까?" << endl;
        char command_report;
        cin >> command_report;
        if(command_report == 'Y' ||command_report == 'y' ){
            //신고수 += 1
            int num_report = stoi(data[5]);
            num_report+=1;
            data[5] = to_string(num_report);
        }
        else if(command_report == 'N' ||command_report == 'n' ){
            //신고 취소
        }
        else{
            //입력오류
            cout << "잘못된 입력입니다." << endl;
        }
	}
    else if (command == '3') {
        cout << "추천을 하시겠습니까?" << endl;
        char command_recommand;
        cin >> command_recommand;
        if(command_recommand == 'Y' ||command_recommand == 'y' ){
            //추천수 += 1
            int num_recommand = stoi(data[6]);
            num_recommand+=1;
            data[6] = to_string(num_recommand);
        }
        else if(command_recommand == 'N' ||command_recommand == 'n' ){
            //추천취소
        }
        else{
            //입력오류
            cout << "잘못된 입력입니다." << endl;
        }
	}
    else if (command == '4') {
		//수정창으로 
	}
	else if (command == 'B' || command == 'b') {
		//게시글목록으로 가야함
	}
    else{
        cout << "잘못된 입력입니다." << endl;
    }

    }
   

}


int main(void){
    boardPost b;
    b.Post();
}