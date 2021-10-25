#include "boardPost.h"
// #include <curses.h> // cls
//#include <Windows.h>
//#include <cctype>
// #include <unistd.h> // sleep
//#include <cstdio>

using namespace std;

// string _title;
// string _contents;
// string _date;
// int _recommand;
// string comment;
// int _datanum;
// string _userid;
// int _report;

boardPost::boardPost()
{
}

boardPost::~boardPost()
{
}

int boardPost::check_fspace(string s)
{
    int front = s.front();
    int back = s.back();
    if (isspace(front) != 0 || isspace(back) != 0)
    {
        return 0;
    }
    else
        return 1;
}

int boardPost::check_(string s)
{
    bool check = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s.at(i)) || isalpha(s.at(i)) || ((s.at(i) & 0X80) == 0x80) || (s.at(i) == ' '))
            check = false;
        else
            check = true;
        break;
    }
    if (check)
    {
        return 1;
    }
    return 0;
}

//나중에 파라미터로 연동해서 받아야한다.
void boardPost::Post(string _filename, string _userid)
{
    while (1)
    {
        string _file = "./data/";
        string _postname = _file + _filename;

        fstream postinfo;
        postinfo.open(_postname, ios::in | ios::out);
        string line;
        getline(postinfo, line);
        stringstream ss(line);
        vector<string> data;

        while (getline(ss, line, '/'))
        {
            data.push_back(line);
        }
        postinfo.close();
        system("cls"); // Windows용
        // system("clear"); // Mac용 system("cls")

        cout << "============================" << endl;
        cout << data[2] << endl;
        cout << "제목 "
            << " : " << data[3] << endl;
        cout << "본문"
            << " : " << data[4] << endl;
        cout << "신고"
            << ": " << data[5] << " 추천"
            << ": " << data[6] << endl;
        cout << "============================" << endl;
        cout << "댓글" << endl;
        for (int i = 7; i < data.size(); i++)
        {
            cout << "익명"
                << " : " << data[i] << endl;
        }
        cout << "============================" << endl;
        cout << "1.댓글 작성"
            << "/"
            << " 2.신고"
            << "/"
            << " 3.추천"
            << "/"
            << " 4.수정 "
            << "/"
            << " 뒤로가기(B/b)" << endl;
        string command;
        cin >> command;
        if (command == "1")
        {
            //댓글 작성창
            while (1)
            {
                system("cls"); // Window
                //system("clear");
                cout << "댓글 : ";
                string s;
                cin.ignore();
                getline(cin, s);

                if (s.empty())
                {
                    cout << "잘못된 입력방식입니다." << endl;
                    Sleep(1000);
                    //  sleep(1);
                }
                else if (s.size() == 1 && (s.compare("b") == 0 || s.compare("B") == 0))
                {
                    break;
                    //back show
                }
                //(s.size() != s1.size()) ||
                else if (s.size() < 2 || s.size() > 101  )
                {
                    cout << "잘못된 입력방식입니다." << endl;
                    Sleep(1000);
                    //  sleep(1);
                }
                else
                {
                    string a;
                    cout << "작성을 완료하시겠습니까?(y or n)";
                    cin >> a;
                    if (a == "y" || a == "Y")
                    {
                        data.push_back(s);
                        postinfo.open(_postname, ios::app);
                        postinfo << s;
                        postinfo.put('/');
                        postinfo.close();
                        break;
                    }
                    else if (a == "n" || a == "N")
                    {
                        break;
                        //back show
                    }
                    else
                    {
                        cout << "잘못된 입력방식입니다." << endl;
                        Sleep(1000);
                        //  sleep(1);
                        //back show
                    }
                }
            }
        }
        else if (command == "2")
        {
            cout << "신고를 하시겠습니까?" << endl;
            string command_report;
            cin >> command_report;
            cin.ignore();
            if (command_report == "Y" || command_report == "y")
            {
                //신고수 += 1
                fstream post_content;
                post_content.open(_postname, ios::out);
                int num_report = stoi(data[5]);
                num_report += 1;
                data[5] = to_string(num_report);
                for (int j = 0; j < 7; j++)
                {
                    post_content << data[j];
                    post_content.put('/');
                }
                for (int i = 7; i < data.size(); i++)
                {
                    post_content << data[i];
                    post_content.put('/');
                }
                post_content.close();
            }
            else if (command_report == "N" || command_report == "n")
            {
                //신고 취소
            }
            else
            {
                //입력오류
                cout << "잘못된 입력입니다." << endl;
                Sleep(1000);
                //  sleep(1);
            }
        }
        else if (command == "3")
        {
            cout << "추천을 하시겠습니까?" << endl;
            string command_recommand;
            cin >> command_recommand;
            if (command_recommand == "Y" || command_recommand == "y")
            {
                //추천수 += 1
                int num_recommand = stoi(data[6]);
                num_recommand += 1;
                data[6] = to_string(num_recommand);
                fstream post_content;
                post_content.open(_postname, ios::out);
                for (int j = 0; j < 7; j++)
                {
                    post_content << data[j];
                    post_content.put('/');
                }
                for (int i = 7; i < data.size(); i++)
                {
                    post_content << data[i];
                    post_content.put('/');
                }
                post_content.close();
            }
            else if (command_recommand == "N" || command_recommand == "n")
            {
                //추천취소
            }
            else
            {
                //입력오류
                cout << "잘못된 입력입니다." << endl;
                Sleep(1000);
                //  sleep(1);
            }
        }

        else if (command == "4")
        {
            //********user_id 와 data[1] 비교 알고리즘 필요!*********
            if (_userid == data[1])
            {
                system("cls");
                //  system("clear"); // Mac용 system("cls")
                string change;
                //게시글 작성자와 수정하려는 사용자의 아이디가 같다면
                cout << "게시글을 수정하시겠습니까? (Y/y or N/n)" << endl;
                cin >> change;
                if (change == "Y" || change == "y")
                {
                    while (1)
                    {
                        system("cls");
                        //  system("clear");
                        cout << "제목 : ";
                        string title;
                        cin.ignore(); // 개행문자(Enter) 입력을 막기위해서 넣어준 메쏘드
                        getline(cin, title);

                        if (title.empty())
                        {
                            cout << "잘못된 입력방식입니다\n";
                            Sleep(1000);
                            //  sleep(1);
                        }
                        else if (title.size() == 1 && (title.compare("b") == 0 || title.compare("B") == 0))
                        {
                            break;
                        }
                        //(s.size() != s1.size()) ||
                        else if (title.size() < 2 || title.size() > 36 )
                        {
                            cout << "잘못된 입력방식입니다\n";
                            Sleep(1000);
                            //  sleep(1);
                        }
                        //입력 검사요소를 모두 통과하였을때
                        else
                        {
                            system("cls");
                            //  system("clear");
                            cout << "본문 : ";
                            string contents;
                            // cin.ignore(); // 개행문자(Enter) 입력을 막기위해서 넣어준 메쏘드
                            getline(cin, contents);

                            if (contents.empty())
                            {
                                cout << "잘못된 입력방식입니다\n";
                                Sleep(1000);
                                //  sleep(1);
                            }
                            else if (contents.size() == 1 && (contents.compare("b") == 0 || contents.compare("B") == 0))
                            {
                                break;
                            }
                            else if (contents.size() < 2 || contents.size() > 301 )
                            {
                                cout << "잘못된 입력방식입니다\n";
                                Sleep(1000);
                                //  sleep(1);
                            }
                            else
                            {
                                //파일열어서 수정해야댐
                                string modify;
                                cout << "게시글 수정을 완료하시겠습니까?" << endl;
                                cin >> modify;
                                if (modify == "Y" || modify == "y")
                                {
                                    fstream post_content;
                                    post_content.open(_postname, ios::out);
                                    data[3] = title;
                                    data[4] = contents;
                                    for (int j = 0; j < 7; j++)
                                    {
                                        post_content << data[j];
                                        post_content.put('/');
                                    }
                                    for (int i = 7; i < data.size(); i++)
                                    {
                                        post_content << data[i];
                                        post_content.put('/');
                                    }
                                    post_content.close();
                                    break;
                                }
                                else if (modify == "N" || modify == "n")
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "잘못된 입력방식입니다\n";
                                    Sleep(1000);
                                    //  sleep(1);
                                }
                            }
                        }
                    }
                }
                else if (change == "N" || change == "n")
                {
                }
                else
                {
                    cout << "잘못된 입력방식입니다\n";
                    Sleep(1000);
                    //  sleep(1);
                }
            }
            else
            {
                cout << "사용자가 일치하지 않습니다" << endl;
                Sleep(1000);
                //  sleep(1);
            }
        }

        else if (command == "B" || command == "b")
        {
            //게시글목록으로 가야함
            string _goMain = "./data/";
            _goMain += _filename;
            string sub_goMain = _goMain.substr(0, 13);
            Board b;
            b.mainPost(_userid, sub_goMain, 0);
            break;
        }
        else
        {
            cout << "잘못된 입력입니다." << endl;
            Sleep(1000);
            //  sleep(1);
        }
    }
}