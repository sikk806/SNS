#pragma once
#define _AFXDLL
<<<<<<< HEAD
#include <afxwin.h> // for windows header ( ���� �ȵǸ� afx.h )
=======
#define _CRT_SECURE_NO_WARNINGS
#include "boardPost.h"
#include "upSign.h"
#include "LogIn.h"
#include <afxwin.h> // for windows header ( ���� �ȵǸ� afx.h )
>>>>>>> 44207a1c629cab69e37bebb3459f0749e48b34f5
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> // for windows header
#include <vector>
#include <sstream>
#include <stdlib.h>
<<<<<<< HEAD
enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};
=======
#include <cstdio>
#include <ctime>

>>>>>>> 44207a1c629cab69e37bebb3459f0749e48b34f5

using namespace std;

class Board {
private:

public:
	Board();
	~Board();
<<<<<<< HEAD
	void selectCategory(string user_id); // ī�װ��� ����                   
	void mainPost(string _userid, string _category); // �� ���
	void createPost(string _userid, string _category, int _postnum); // �� �ۼ�
	void selectCategory(string user_id); // ī�װ��� ����
	void mainPost(string _userid, string _category, int _getFile); // �� ���
    void setColor(unsigned short text); // windows.h�� ����ϴ� �Լ� Mac���� �Ұ����� ��� ����.
=======
	void selectCategory(string user_id); // ī�װ� ����
	void createPost(string _userid, string _category, int _postnum); // �� �ۼ�
	void mainPost(string _userid, string _category, int _getFile); // �� ���
    void setColor(unsigned short text); // windows.h�� ����ϴ� �Լ� Mac���� �Ұ����� ��� ����.
>>>>>>> 44207a1c629cab69e37bebb3459f0749e48b34f5

	int numFile(string _category); // ������ ���� ����
	bool checkWords(string _words); // ������ ������ �ƶ��� ����,�ѱ۰� ����θ� �̷���� ���ڿ����� ���θ� �˻�
};