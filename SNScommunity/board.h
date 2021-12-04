#pragma once
#define _AFXDLL
#define _CRT_SECURE_NO_WARNINGS
#include "boardPost.h"
#include "upSign.h"
#include "LogIn.h"
#include <afxwin.h> // for windows header ( ���� �ȵǸ� afx.h )
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> // for windows header
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cstdio>
#include <ctime>


using namespace std;

class Board {
private:

public:
	Board();
	~Board();
	void selectCategory(string user_id); // ī�װ� ����
	void createPost(string _userid, string _category, int _postnum); // �� �ۼ�
	void mainPost(string _userid, string _category, int _getFile); // �� ���
    void setColor(unsigned short text); // windows.h�� ����ϴ� �Լ� Mac���� �Ұ����� ��� ����.
	void managerCategory(string user_id); // ī�װ� �Ŵ���
	void changeCategoryName(string user_id);
	void addCategory(string user_id); // ī�װ� �߰�
	void mergeCategory(string user_id); // ī�װ� ����
	void deleteCategory(string user_id); // ī�װ� ����
	void changeName(string user_id, int selectCategory, vector<string> &name);

	int lineFile(string _category);
	int numFile(string _category); // ������ ���� ����
	bool checkWords(string _words); // ������ ������ �ƶ��� ����,�ѱ۰� ����θ� �̷���� ���ڿ����� ���θ� �˻�
};