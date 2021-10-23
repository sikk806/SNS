#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>

using namespace std;

class Board {
private:


public:
	Board();
	~Board();
	void selectCategory(string user_id);
	void mainPost(string _userid, string _category);
};