#pragma once
#define _AFXDLL
#include <afxwin.h> // for windows header ( 실행 안되면 afx.h )
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
	void selectCategory(string user_id); // 카테고리 선택
	void mainPost(string _userid, string _category); // 글 목록
	void createPost(string _userid, string _category); // 글 작성

	int numFile(string _category); // 폴더내 파일 갯수
};