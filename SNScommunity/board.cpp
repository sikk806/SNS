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

	//cout << "Page. " << page << "/2" << endl; // �� ������ �� �� �ִ� �Լ� ��������.
	//cout << "W/w. �Խñ� �ۼ�" << endl;
	//if (page != 2) {
	//	cout << "F/f. ���� ��������" << endl;
	//}

	//if (page == 1) {
	//	cout << "B/b. ī�װ� ����" << endl;
	//}
	//else {
	//	cout << "B/b. ���� ��������" << endl;
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
