#pragma once
#define _AFXDLL
<<<<<<< HEAD
#include <afxwin.h> // for windows header ( ï¿½ï¿½ï¿½ï¿½ ï¿½ÈµÇ¸ï¿½ afx.h )
=======
#define _CRT_SECURE_NO_WARNINGS
#include "boardPost.h"
#include "upSign.h"
#include "LogIn.h"
#include <afxwin.h> // for windows header ( ½ÇÇà ¾ÈµÇ¸é afx.h )
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
	void selectCategory(string user_id); // Ä«ï¿½×°ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½                   
	void mainPost(string _userid, string _category); // ï¿½ï¿½ ï¿½ï¿½ï¿½
	void createPost(string _userid, string _category, int _postnum); // ï¿½ï¿½ ï¿½Û¼ï¿½
	void selectCategory(string user_id); // Ä«ï¿½×°ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	void mainPost(string _userid, string _category, int _getFile); // ï¿½ï¿½ ï¿½ï¿½ï¿½
    void setColor(unsigned short text); // windows.hï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½Ï´ï¿½ ï¿½Ô¼ï¿½ Macï¿½ï¿½ï¿½ï¿½ ï¿½Ò°ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½.
=======
	void selectCategory(string user_id); // Ä«Å×°í¸® ¼±ÅÃ
	void createPost(string _userid, string _category, int _postnum); // ±Û ÀÛ¼º
	void mainPost(string _userid, string _category, int _getFile); // ±Û ¸ñ·Ï
    void setColor(unsigned short text); // windows.h¸¦ »ç¿ëÇÏ´Â ÇÔ¼ö Mac¿¡¼­ ºÒ°¡´ÉÇÒ °æ¿ì »èÁ¦.
>>>>>>> 44207a1c629cab69e37bebb3459f0749e48b34f5

	int numFile(string _category); // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	bool checkWords(string _words); // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Æ¶ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½,ï¿½Ñ±Û°ï¿½ ï¿½ï¿½ï¿½ï¿½Î¸ï¿½ ï¿½Ì·ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ú¿ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Î¸ï¿½ ï¿½Ë»ï¿½
};