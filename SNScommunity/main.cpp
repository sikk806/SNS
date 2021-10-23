#include "board.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>

using namespace std;

int main(void) {
	string user_id = "aaaa";
	string test_post = "./data/post_1.txt";

	ifstream fin("./data/test.txt");

	ofstream fout("./data/test1.txt");

	//ifstream openpost("./data/post_1.txt");

	Board b;



	b.selectCategory("aaaa");

}