#include "boardPost.h"
// #include <curses.h>
#include <Windows.h>
#include <cctype>
#include <unistd.h>
#include <cstdio>

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

//���߿� �Ķ���ͷ� �����ؼ� �޾ƾ��Ѵ�.
void boardPost::Post(string _filename, string _userid)
{
    while (1)
    {
        int com_num = 0;
        string _file = "./data/";
        string _postname = _file + _filename;
        fstream postinfo;
        postinfo.open(_postname, ios::in | ios::out);
        string line;
        string s;
        char cstr[1000];
        getline(postinfo, line);
        stringstream ss(line);
        vector<string> data;
        stringstream aa;
        postinfo.seekg(0, ios::end);
        int size = postinfo.tellg();
        s.resize(size);
        postinfo.seekg(0, ios::beg);
        postinfo.read(&s[0], size);
        // s.erase(remove(s.begin(), s.end(), '\n'), s.end());
        strcpy(cstr, s.c_str());
        char *ptr = strtok(cstr, "\t");
        while (ptr != NULL)
        {
            string st;
            st = ptr;
            data.push_back(st);
            ptr = strtok(NULL, "\t");
        }
        postinfo.close();
        if (data.size() == 6)
        {
            com_num = 0;
        }
        else
        {
            int count = data.size();
            com_num = (count - 7) / 2;
        }

          system("cls");
        // system("clear"); // Mac용 system("cls")

        cout << "============================" << endl;
        cout << data[2] << endl;
        cout << "���� "
            << " : " << data[3] << endl;
        cout << "����"
            << " : " << data[4] << endl;
        cout << "�Ű�"
            << ": " << data[5] << " ��õ"
            << ": " << data[6] << endl;
        cout << "============================" << endl;
        cout << "댓글" << endl;
        int j = 1;
        for (int i = 7; i < data.size(); i++)
        {

            if (i % 2 != 0)
            {
                cout << j++ << ". " << _userid << " : ";
            }
            else
            {
                cout << data[i] << endl;
            }
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
             << " 5.댓글 삭제 "
             << "/"
             << " 6.게시글 삭제 "
             << "/"
             << " 뒤로가기(B/b)" << endl;
        string command;
        cin >> command;
        cin.ignore();
        if (command == "1")
        {
            //��� �ۼ�â
            while (1)
            {
                system("cls");
                // system("clear");
                cout << "댓글 : ";
                string s;
                // cin.ignore();
                // getline(cin, s);
                string s1;
                while (1)
                {
                    // cin.ignore();
                    getline(cin, s1);
                    if (s1.find('\t') == string::npos)
                    {
                        s = s + s1 + '\n';
                    }
                    else
                    {
                        int index = s1.find('\t');
                        for (int i = 0; i < index; i++)
                        {
                            s = s + s1.at(i);
                        }
                        break;
                    }
                }
                if (s.empty())
                {
                    cout << "잘못된 입력방식입니다1" << endl;
                       Sleep(1000);
                    // sleep(1);
                }
                else if (s.size() == 1 && (s.compare("b") == 0 || s.compare("B") == 0))
                {
                    break;
                    //back show
                }
                //(s.size() != s1.size()) ||
                else if (s.size() < 2 || s.size() > 100)
                {
                    cout << "잘못된 입력방식입니다3" << endl;
                       Sleep(1000);
                    // sleep(1);
                }
                else
                {
                    string a;
                    cout << "�ۼ��� �Ϸ��Ͻðڽ��ϱ�?(y or n)";
                    cin >> a;
                    if (a == "y" || a == "Y")
                    {
                        data.push_back(_userid);
                        data.push_back(s);
                        postinfo.open(_postname, ios::app);
                        postinfo << _userid;
                        postinfo.put('\t');
                        postinfo << s;
                        postinfo.put('\t');
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
                        cout << "잘못된 입력방식입니다3" << endl;
                          Sleep(1000);
                        // sleep(1);
                        //back show
                    }
                }
            }
        }
        else if (command == "2")
        {
            cout << "�Ű��� �Ͻðڽ��ϱ�?" << endl;
            string command_report;
            cin >> command_report;
            cin.ignore();
            if (command_report == "Y" || command_report == "y")
            {
                //�Ű��� += 1
                fstream post_content;
                post_content.open(_postname, ios::out);
                int num_report = stoi(data[5]);
                num_report += 1;
                data[5] = to_string(num_report);
                for (int j = 0; j < 7; j++)
                {
                    post_content << data[j];
                    post_content.put('\t');
                }
                for (int i = 7; i < data.size(); i++)
                {
                    post_content << data[i];
                    post_content.put('\t');
                }
                post_content.close();
            }
            else if (command_report == "N" || command_report == "n")
            {
                //�Ű� ���
            }
            else
            {
                //입력오류
                cout << "잘못된 입력입니다." << endl;
                Sleep(1000);
                // sleep(1);
            }
        }
        else if (command == "3")
        {
            cout << "��õ�� �Ͻðڽ��ϱ�?" << endl;
            string command_recommand;
            cin >> command_recommand;
            if (command_recommand == "Y" || command_recommand == "y")
            {
                //��õ�� += 1
                int num_recommand = stoi(data[6]);
                num_recommand += 1;
                data[6] = to_string(num_recommand);
                fstream post_content;
                post_content.open(_postname, ios::out);
                for (int j = 0; j < 7; j++)
                {
                    post_content << data[j];
                    post_content.put('\t');
                }
                for (int i = 7; i < data.size(); i++)
                {
                    post_content << data[i];
                    post_content.put('\t');
                }
                post_content.close();
            }
            else if (command_recommand == "N" || command_recommand == "n")
            {
                //��õ���
            }
            else
            {
                //입력오류
                cout << "잘못된 입력입니다." << endl;
                Sleep(1000);
                // sleep(1);
            }
        }

        else if (command == "4")
        {
            //********user_id 와 data[1] 비교 알고리즘 필요!*********
            if (_userid == data[1] || _userid == "manager")
            {
                system("cls");
                // system("clear"); // Mac용 system("cls")
                string change;
                //�Խñ� �ۼ��ڿ� �����Ϸ��� ������� ���̵� ���ٸ�
                cout << "�Խñ��� �����Ͻðڽ��ϱ�? (Y/y or N/n)" << endl;
                cin >> change;
                cin.ignore();

                // else
                // {                                                              //게시글 삭제 가능
                //     postinfo.open(_postname, ios::in | ios::out | ios::trunc); //게시글 데이터파일 내용 전부 삭제
                //     postinfo.close();
                //     cout << "게시글 삭제" << endl;
                        Sleep(1000);
                    // sleep(1);
                //     break; //게시글목록으로 이동
                // }
                if (change == "Y" || change == "y")
                {
                    if (com_num != 0)
                    {
                        cout << "댓글이 한 개 이상 존재합니다" << endl;
                        // sleep(1);
                    }
                    else
                    {
                        while (1)
                        {
                              system("cls");
                            // system("clear");
                            cout << "제목 : ";
                            string title;
                            // cin.ignore(); // 개행문자(Enter) 입력을 막기위해서 넣어준 메쏘드
                            // getline(cin, title);
                            string s1;
                            while (1)
                            {
                                //cin.ignore();
                                getline(cin, s1);
                                if (s1.find('\t') == string::npos)
                                {
                                    title = title + s1 + '\n';
                                }
                                else
                                {
                                    int index = s1.find('\t');
                                    for (int i = 0; i < index; i++)
                                    {
                                        title = title + s1.at(i);
                                    }
                                    break;
                                }
                            }
                            if (title.empty())
                            {
                                cout << "잘못된 입력방식입니다" << endl;
                                 Sleep(1000);
                                // sleep(1);
                            }
                            else if (title.size() == 1 && (title.compare("b") == 0 || title.compare("B") == 0))
                            {
                                break;
                            }
                            //(s.size() != s1.size()) ||
                            else if (title.size() < 2 || title.size() > 35)
                            {
                                cout << "잘못된 입력방식입니다" << endl;
                                 Sleep(1000);
                                // sleep(1);
                            }
                            //입력 검사요소를 모두 통과하였을때
                            else
                            {
                                 system("cls");
                                // system("clear");
                                cout << "본문 : ";
                                // cin.ignore();
                                string contents;
                                // getline(cin, contents);
                                string s2;
                                while (1)
                                {
                                    //cin.ignore();
                                    getline(cin, s2);
                                    if (s2.find('\t') == string::npos)
                                    {
                                        contents = contents + s2 + '\n';
                                    }
                                    else
                                    {
                                        int index = s2.find('\t');
                                        for (int i = 0; i < index; i++)
                                        {
                                            contents = contents + s2.at(i);
                                        }
                                        break;
                                    }
                                }
                                if (contents.empty())
                                {
                                    cout << "잘못된 입력방식입니다" << endl;
                                    Sleep(1000);
                                    // sleep(1);
                                }
                                else if (contents.size() == 1 && (contents.compare("b") == 0 || contents.compare("B") == 0))
                                {
                                    break;
                                }
                                else if (contents.size() < 2 || contents.size() > 300)
                                {
                                    cout << "잘못된 입력방식입니다" << endl;
                                    Sleep(1000);
                                    // sleep(1);
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
                                            post_content.put('\t');
                                        }
                                        for (int i = 7; i < data.size(); i++)
                                        {
                                            post_content << data[i];
                                            post_content.put('\t');
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
                                        cout << "잘못된 입력방식입니다" << endl;
                                           Sleep(1000);
                                        // sleep(1);
                                    }
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
                    cout << "잘못된 입력방식입니다" << endl;
                       Sleep(1000);
                    // sleep(1);
                }
            }
            else
            {
                cout << "사용자가 일치하지 않습니다" << endl;
                Sleep(1000);
                // sleep(1);
            }
        }
        else if (command == "5")
        { //댓글 삭제 - user_id 부분 일치
            cout << "댓글 번호를 입력해주세요." << endl;
            string com;
            cin >> com;
            int num = stoi(com);
            if (_userid == data[7 + 2 * (num - 1)] || _userid == "manager")
            {
                fstream post_content;
                data.erase(data.begin() + (7 + 2 * (num - 1)));
                data.erase(data.begin() + (7 + 2 * (num - 1)));

                post_content.open(_postname, ios::out);
                for (int j = 0; j < 7; j++)
                {
                    post_content << data[j];
                    post_content.put('\t');
                }
                for (int i = 7; i < data.size(); i++)
                {
                    post_content << data[i];
                    post_content.put('\t');
                }
                post_content.close();
            }
            else
            {
                cout << "잘못된 입력입니다." << endl;
                Sleep(1000);
                // sleep(1);
            }
        }
        else if (command == "6")
        { //게시글 삭제 - user_id 부분 일치 , 댓글 하나 이상 존재할 경우 삭제 x
            if (_userid == "manager")
            {
                postinfo.open(_postname, ios::in | ios::out | ios::trunc); //게시글 데이터파일 내용 전부 삭제
                postinfo.close();
                cout << "게시글 삭제" << endl;
                Sleep(1000);
                // sleep(1);
                break; //게시글목록으로 이동
            }
            if (_userid == data[1])
            {
                if (com_num != 0)
                {
                    cout << "댓글이 한 개 이상 존재합니다" << endl;
                    Sleep(1000);
                    // sleep(1);
                }
                else
                {                                                              //게시글 삭제 가능
                    postinfo.open(_postname, ios::in | ios::out | ios::trunc); //게시글 데이터파일 내용 전부 삭제
                    postinfo.close();
                    cout << "게시글 삭제" << endl;
                    Sleep(1000);
                    // sleep(1);
                    break; //게시글목록으로 이동
                }
            }
            else
            {
                cout << "작성자가 아닙니다." << endl;
                Sleep(1000);
                // sleep(1);
            }
        }

        else if (command == "B" || command == "b")
        {
            //�Խñ۸������ ������
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
            // sleep(1);
        }
    }
}

// int main(void)
// {
//     boardPost b;
//     //    string _postname = "post_1/1.txt";
//     string _postname = "post_1/1.txt";
//     string _userid = "aaaa";
//     b.Post(_postname, _userid);
// }
