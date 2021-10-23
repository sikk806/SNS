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
	void selectCategory(string user_id); // 카테고리 선택
	void mainPost(string _userid, string _category, int _getFile); // 글 목록
    void setColor(unsigned short text); // windows.h를 사용하는 함수 Mac에서 불가능할 경우 삭제.

	int numFile(string _category); // 폴더내 파일 갯수
};