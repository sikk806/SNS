#pragma once
#include "board.h"
#include "boardPost.h"
#include "upSign.h"
#include "LogIn.h"

#include <io.h>
#include <direct.h>
using namespace std;

void setting_data_directory();

int main()
{
	setting_data_directory();

	/*ifstream openpost("./data/manager_category.txt");

	for (int i = 0; i < 4; i++) {
		string line;
		getline(openpost, line);
		stringstream ss(line);

		vector<string> data;

		while (getline(ss, line, '	')) {
			data.push_back(line);
		}

		cout << data[1] << endl;
	}*/

	Board bd;
	bd.selectCategory("manager");

	//Login lg_;
	//lg_.main_promp();
}

void setting_data_directory()
{
	int data_directory_exists = _access("./data", 00);
	if (data_directory_exists == -1)
	{
		int nResult = _mkdir("./data");

		if (nResult == 0)
			cout << "데이터 디렉토리 생성" << endl;
		else
			cout << "데이터 디렉토리 생성 실패" << endl;
	}

	int data_post_1_directory_exists = _access("./data/post_1", 00);
	if (data_post_1_directory_exists == -1)
	{
		int nResult = _mkdir("./data/post_1");

		if (nResult == 0)
			cout << "post_1 데이터 디렉토리 생성" << endl;
		else
			cout << "post_1 데이터 디렉토리 생성 실패" << endl;
	}

	int data_post_2_directory_exists = _access("./data/post_2", 00);
	if (data_post_2_directory_exists == -1)
	{
		int nResult = _mkdir("./data/post_2");

		if (nResult == 0)
			cout << "post_2 데이터 디렉토리 생성" << endl;
		else
			cout << "post_2 데이터 디렉토리 생성 실패" << endl;
	}

	int data_post_3_directory_exists = _access("./data/post_3", 00);
	if (data_post_3_directory_exists == -1)
	{
		int nResult = _mkdir("./data/post_3");

		if (nResult == 0)
			cout << "post_3 데이터 디렉토리 생성" << endl;
		else
			cout << "post_3 데이터 디렉토리 생성 실패" << endl;
	}

	int data_post_4_directory_exists = _access("./data/post_4", 00);
	if (data_post_4_directory_exists == -1)
	{
		int nResult = _mkdir("./data/post_4");

		if (nResult == 0)
			cout << "post_4 데이터 디렉토리 생성" << endl;
		else
			cout << "post_4 데이터 디렉토리 생성 실패" << endl;
	}
}