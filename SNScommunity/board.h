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

using namespace std;

class Board {
private:


public:
	Board();
	~Board();
	void selectCategory(string user_id); // ī�װ� ����
	void mainPost(string _userid, string _category); // �� ���
	void createPost(string _userid, string _category); // �� �ۼ�

	int numFile(string _category); // ������ ���� ����
};