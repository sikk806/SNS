#pragma once
#define _AFXDLL
#include <afxwin.h> // for windows header ( ���� �ȵǸ� afx.h )
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> // for windows header
#include <vector>
#include <sstream>
#include <stdlib.h>
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

using namespace std;

class Board {
private:

public:
	Board();
	~Board();
	void selectCategory(string user_id); // ī�װ��� ����                   
	void mainPost(string _userid, string _category); // �� ���
	void createPost(string _userid, string _category, int _postnum); // �� �ۼ�
	void selectCategory(string user_id); // ī�װ��� ����
	void mainPost(string _userid, string _category, int _getFile); // �� ���
    void setColor(unsigned short text); // windows.h�� ����ϴ� �Լ� Mac���� �Ұ����� ��� ����.

	int numFile(string _category); // ������ ���� ����
	bool checkWords(string _words); // ������ ������ �ƶ��� ����,�ѱ۰� ����θ� �̷���� ���ڿ����� ���θ� �˻�
};