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
	cout << "      카테고리 선택" << endl;
	cout << endl;
	cout << "      1. 자유 게시판" << endl;
	cout << endl;
	cout << "      2. IT 게시판" << endl;
	cout << endl;
	cout << "      3. 새내기 게시판" << endl;
	cout << endl;
	cout << "      4. 졸업생 게시판" << endl;
	cout << endl;
	cout << "===========================" << endl;

	char _select;
	cout << endl;
	cout << "게시판을 선택해주세요. (1~4)" << endl;
	cout << "로그아웃을 원하시면 0을 입력해주세요. : ";
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
	cout << "파일 갯수 : " << _cntFile << endl;
	
	int _getFile = _cntFile;
	int _postnum = _cntFile;

	for (int i = 1; i <= 10; i++) {
		// 파일명은 자연수만 가능 (0이하로는 금지)
		if (_getFile == 0) {
			break;
		}
		// 파일명은 파일 최대 갯수를 넘을 수 없음.
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
		
		// 제목 출력
		cout << i << ". " << data[3] << endl;
		// 본문 출력
		cout << "	- " << data[4] << endl;
		_getFile--;
	}

	
	cout << "Page. " << (_cntFile - _getFile)/10 << "/" << (_cntFile/10 + 1) << endl;
	cout << "W/w. 게시글 작성" << endl;
	/*if ( != 2) {
		cout << "F/f. 다음 페이지로" << endl;
	}

	if (page == 1) {
		cout << "B/b. 카테고리 선택" << endl;
	}
	else {
		cout << "B/b. 이전 페이지로" << endl;
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

	cout << "제목 : ";
	cin >> _title;
	cout << endl;
	cout << "본문 : ";
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

	/* regex 예외처리 부분은 나중에 */

	return false;
}
