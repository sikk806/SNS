#include "LogIn.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using std::string;
Login::Login(const string& ID, const string& pw)
    :userID(ID), password(pw)
{

}

void Login::login()
{
    std::ifstream file("data/userInfo.txt", std::ios::in); //파일 불러오기
    std::vector<string> result;
    bool flag;
    if (file.is_open())
    {
        string user;
        while(getline(file,user)) //파일 읽기
        {
            std::stringstream ss(user);
            flag = false;
            result.clear();
            while(ss.good())   //id와 pw가져오기
            {
                string substr;
                getline(ss,substr,'/');
                result.push_back(substr);
            }
            //파일에서 읽은 아이디/비번과 일치하는지 확인
            for(int i=0;i<result.size();i+=2)
            {
                if(result.at(i) == userID && result.at(i+1) == password)
                {
                    // 로그인 성공
                    std::cout<<"Login successful: "<<userID<<", "<<password<<std::endl;
                    flag = true;
                    //다음 과정 진행

                }
            }
            if(flag) //이미 일치하는 아이디/비번을 찾았으면 더이상 읽지 않는다
                break;
        }
        if(!flag)
            std::cout<<"Login failed: "<<userID<<", "<<password<<std::endl;
        file.close();
    }
    else //파일 불러오기 실패
    {
        std::cout << "Failed to open file" << std::endl;
    }
}

