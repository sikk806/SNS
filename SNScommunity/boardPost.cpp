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

//���߿� �Ķ���ͷ� �����ؼ� �޾ƾ��Ѵ�.
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
        system("cls"); // Windows��
        // system("clear"); // Mac�� system("cls")

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
        cout << "���" << endl;
        for (int i = 7; i < data.size(); i++)
        {
            cout << "�͸�"
                << " : " << data[i] << endl;
        }
        cout << "============================" << endl;
        cout << "1.��� �ۼ�"
            << "/"
            << " 2.�Ű�"
            << "/"
            << " 3.��õ"
            << "/"
            << " 4.���� "
            << "/"
            << " �ڷΰ���(B/b)" << endl;
        string command;
        cin >> command;
        if (command == "1")
        {
            //��� �ۼ�â
            while (1)
            {
                system("cls"); // Window
                //system("clear");
                cout << "��� : ";
                string s;
                cin.ignore();
                getline(cin, s);

                if (s.empty())
                {
                    cout << "�߸��� �Է¹���Դϴ�." << endl;
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
                    cout << "�߸��� �Է¹���Դϴ�." << endl;
                    Sleep(1000);
                    //  sleep(1);
                }
                else
                {
                    string a;
                    cout << "�ۼ��� �Ϸ��Ͻðڽ��ϱ�?(y or n)";
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
                        cout << "�߸��� �Է¹���Դϴ�." << endl;
                        Sleep(1000);
                        //  sleep(1);
                        //back show
                    }
                }
            }
        }
        else if (command == "2")
        {
            cout << "�Ű� �Ͻðڽ��ϱ�?" << endl;
            string command_report;
            cin >> command_report;
            cin.ignore();
            if (command_report == "Y" || command_report == "y")
            {
                //�Ű�� += 1
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
                //�Ű� ���
            }
            else
            {
                //�Է¿���
                cout << "�߸��� �Է��Դϴ�." << endl;
                Sleep(1000);
                //  sleep(1);
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
                //��õ���
            }
            else
            {
                //�Է¿���
                cout << "�߸��� �Է��Դϴ�." << endl;
                Sleep(1000);
                //  sleep(1);
            }
        }

        else if (command == "4")
        {
            //********user_id �� data[1] �� �˰��� �ʿ�!*********
            if (_userid == data[1])
            {
                system("cls");
                //  system("clear"); // Mac�� system("cls")
                string change;
                //�Խñ� �ۼ��ڿ� �����Ϸ��� ������� ���̵� ���ٸ�
                cout << "�Խñ��� �����Ͻðڽ��ϱ�? (Y/y or N/n)" << endl;
                cin >> change;
                if (change == "Y" || change == "y")
                {
                    while (1)
                    {
                        system("cls");
                        //  system("clear");
                        cout << "���� : ";
                        string title;
                        cin.ignore(); // ���๮��(Enter) �Է��� �������ؼ� �־��� �޽��
                        getline(cin, title);

                        if (title.empty())
                        {
                            cout << "�߸��� �Է¹���Դϴ�\n";
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
                            cout << "�߸��� �Է¹���Դϴ�\n";
                            Sleep(1000);
                            //  sleep(1);
                        }
                        //�Է� �˻��Ҹ� ��� ����Ͽ�����
                        else
                        {
                            system("cls");
                            //  system("clear");
                            cout << "���� : ";
                            string contents;
                            // cin.ignore(); // ���๮��(Enter) �Է��� �������ؼ� �־��� �޽��
                            getline(cin, contents);

                            if (contents.empty())
                            {
                                cout << "�߸��� �Է¹���Դϴ�\n";
                                Sleep(1000);
                                //  sleep(1);
                            }
                            else if (contents.size() == 1 && (contents.compare("b") == 0 || contents.compare("B") == 0))
                            {
                                break;
                            }
                            else if (contents.size() < 2 || contents.size() > 301 )
                            {
                                cout << "�߸��� �Է¹���Դϴ�\n";
                                Sleep(1000);
                                //  sleep(1);
                            }
                            else
                            {
                                //���Ͽ�� �����ؾߴ�
                                string modify;
                                cout << "�Խñ� ������ �Ϸ��Ͻðڽ��ϱ�?" << endl;
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
                                    cout << "�߸��� �Է¹���Դϴ�\n";
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
                    cout << "�߸��� �Է¹���Դϴ�\n";
                    Sleep(1000);
                    //  sleep(1);
                }
            }
            else
            {
                cout << "����ڰ� ��ġ���� �ʽ��ϴ�" << endl;
                Sleep(1000);
                //  sleep(1);
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
            cout << "�߸��� �Է��Դϴ�." << endl;
            Sleep(1000);
            //  sleep(1);
        }
    }
}