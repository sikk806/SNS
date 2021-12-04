#include "LogIn.h"

Login::Login() {

}

Login::~Login() {

}

Login::Login(const string& ID, const string& pw)
    :userID(ID), password(pw)
{

}

void Login::login()
{
    ifstream file("./data/member_information.txt", ios::in); //���� �ҷ�����
    vector<string> result;
    bool flag;
    if (file.is_open())
    {
        string user;
        while (getline(file, user)) //���� �б�
        {
            stringstream ss(user);
            flag = false;
            result.clear();
            while (ss.good())   //id�� pw��������
            {
                string substr;
                getline(ss, substr, '/');
                result.push_back(substr);
            }
            //���Ͽ��� ���� ���̵�/����� ��ġ�ϴ��� Ȯ��
            for (int i = 0; i < result.size(); i += 2)
            {
                if (result.at(i) == userID && result.at(i + 1) == password)
                {
                    // �α��� ����
                    cout << "Login successful: " << userID << ", " << password << endl;
                    Sleep(1000);
                    flag = true;
                    //���� ���� ����
                    Board b;
                    b.selectCategory(userID);
                }
            }
            if (flag) //�̹� ��ġ�ϴ� ���̵�/����� ã������ ���̻� ���� �ʴ´�
                break;
        }
        if (!flag) {
            cout << "Login failed: " << userID << ", " << password << endl;
            Sleep(1000);
        }
        file.close();
    }
    else //���� �ҷ����� ����
    {
        cout << "Failed to open file" << endl;
        Sleep(1000);
    }
}

