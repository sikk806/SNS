#include "board.h"

using namespace std;

Board::Board() {

}

Board::~Board() {

}

void Board::mainPost(int page) {
	system("cls"); // Windows.h
	ifstream openpost("./data/post_1.txt");

	int num_data = 0;
	string cnt_line;
	while (getline(openpost, cnt_line)) {
		num_data++;
	}

	for (int i = 1; i <= 10; i++) {
		string line;
		getline(openpost, line);
		stringstream ss(line);

		vector<string> data;

		while (getline(ss, line, '/')) {
			data.push_back(line);
		}

		cout << i << ". " << data[3] << endl;
		cout << "	- " << data[4] << endl;
	}

	cout << "Page. " << page << "/2" << endl; // �� ������ �� �� �ִ� �Լ� ��������.
	cout << "W/w. �Խñ� �ۼ�" << endl;
	if (page != 2) {
		cout << "F/f. ���� ��������" << endl;
	}

	if (page == 1) {
		cout << "B/b. ī�װ� ����" << endl;
	}
	else {
		cout << "B/b. ���� ��������" << endl;
	}

	char select;
	cin >> select;

		if (select == 'B' || select == 'b') {
			page--;
			mainPost(page);
		}
		else if (select == 'F' || select == 'f') {
			page++;
			mainPost(page);
		}
}
