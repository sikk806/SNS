#include "board.h"

using namespace std;

Board::Board() {

}

Board::~Board() {

}

void Board::selectCategory(string _userid) {
	system("cls");
	cout << "===========================" << endl;
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
		_category += ".txt";
		
		mainPost(_userid, _category);
	}


}

void Board::mainPost(string _userid, string _category) {
	system("cls"); // Windows.h
	ifstream cnt_lines("./data/post_1.txt");

	cout << _userid << _category << endl;

	int num_data = 0;
	string cnt_line;
	while (getline(cnt_lines, cnt_line)) {
		num_data++;
	}
	cnt_lines.close();

	//ifstream openpost("./data/post_1.txt");
	//for (int i = 1; i <= 10; i++) {
	//	string line;
	//	getline(openpost, line);
	//	stringstream ss(line);

	//	vector<string> data;

	//	while (getline(ss, line, '/')) {
	//		data.push_back(line);
	//	}
	//	
	//	if (num_data != 0) {
	//		cout << i << ". " << data[3] << endl;
	//		cout << "	- " << data[4] << endl;
	//	}
	//}

	//cout << "Page. " << page << "/2" << endl; // 총 페이지 알 수 있는 함수 만들어야함.
	//cout << "W/w. 게시글 작성" << endl;
	//if (page != 2) {
	//	cout << "F/f. 다음 페이지로" << endl;
	//}

	//if (page == 1) {
	//	cout << "B/b. 카테고리 선택" << endl;
	//}
	//else {
	//	cout << "B/b. 이전 페이지로" << endl;
	//}

	//char select;
	//cin >> select;

	//	if (select == 'B' || select == 'b') {
	//		page--;
	//		mainPost(page);
	//	}
	//	else if (select == 'F' || select == 'f') {
	//		page++;
	//		mainPost(page);
	//	}
}
