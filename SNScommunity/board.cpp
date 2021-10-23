#include "board.h"
using namespace std;

Board::Board() {

}

Board::~Board() {

}

void Board::selectCategory(string _userid) {
	system("cls");
	cout << "========== =================" << endl;
	cout << endl;
	cout << "      ī�װ� ����" << endl;
	cout << endl;
	cout << "      1. ���� �Խ���" << endl;
	cout << endl;
	cout << "      2. IT �Խ���" << endl;
	cout << endl;
	cout << "      3. ������ �Խ���" << endl;
	cout << endl;
	cout << "      4. ������ �Խ���" << endl;
	cout << endl;
	cout << "===========================" << endl;

	char _select;
	cout << endl;
	cout << "�Խ����� �������ּ���. (1~4)" << endl;
	cout << "�α׾ƿ��� ���Ͻø� 0�� �Է����ּ���. : ";
	cin >> _select;

	// ascii '1' = 49 || '4' = 52
	if (_select >= 49 && _select <= 52 ) {
		string _category = "./data/post_";
		_category += _select;
		
		mainPost(_userid, _category);
	}


}

void Board::mainPost(string _userid, string _category) {
	//system("clear"); // Mac command
	system("cls"); // Windows.h

	int _cntFile = numFile(_category);
	cout << "���� ���� : " << _cntFile << endl;
	
	int _getFile = _cntFile;
	int _postnum = _cntFile;

	for (int i = 1; i <= 10; i++) {
		// ���ϸ��� �ڿ����� ���� (0���Ϸδ� ����)
		if (_getFile == 0) {
			break;
		}
		// ���ϸ��� ���� �ִ� ������ ���� �� ����.
		else if (_getFile > _cntFile) {
			break;
		}
		string _fname = to_string(_getFile);
		string _filename = _category + "/" + _fname + ".txt";

		ifstream openpost(_filename);

		string line;
		getline(openpost, line);
		stringstream ss(line);

		vector<string> data;

		while (getline(ss, line, '/')) {
			data.push_back(line);
		}
		
		// ���� ���
		cout << i << ". " << data[3] << endl;
		// ���� ���
		cout << "	- " << data[4] << endl;
		_getFile--;
	}

	
	cout << "Page. " << (_cntFile - _getFile)/10 << "/" << (_cntFile/10 + 1) << endl;
	cout << "W/w. �Խñ� �ۼ�" << endl;
	/*if ( != 2) {
		cout << "F/f. ���� ��������" << endl;
	}

	if (page == 1) {
		cout << "B/b. ī�װ� ����" << endl;
	}
	else {
		cout << "B/b. ���� ��������" << endl;
	}*/

	char select;
	cin >> select;
	/*
	if (select == 'B' || select == 'b') {
		page--;
		mainPost(page);
	}
	else if (select == 'F' || select == 'f') {
		page++;
		mainPost(page);
	}*/


	if (select == 'W' || select == 'w') {
		createPost(_userid, _category, _postnum);
	}
}

void Board::createPost(string _userid, string _category, int _postnum) {
	//system("clear"); // Mac command
	system("cls"); // Windows.h

	string _title, _content, _path;

	string _currentnum = to_string(++_postnum);

	string _total

	cout << "���� : ";
	cin >> _title;
	cout << endl;
	cout << "���� : ";
	cin >> _content;

	_path += _category + "/" + _currentnum + ".txt";

	ofstream savepost(_path);

	if (savepost.is_open()) {

	}

	

}

int Board::numFile(string _category) {
	int _cnt = 0;

	CFileFind finder;
	CString _foldername = _category.c_str();

	BOOL _existfolder = finder.FindFile(_foldername + "/*.*");

	while (_existfolder) {
		_existfolder = finder.FindNextFile();
		if (finder.IsDots()) {
			continue;
		}
		_cnt++;
		
	}

	finder.Close();

	return _cnt;
}

bool Board::checkWords(string _words)
{
	string words = _words;

	/* regex ����ó�� �κ��� ���߿� */

	return false;
}
