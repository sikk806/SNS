#include "board.h"
using namespace std;

Board::Board() {

}

Board::~Board() {

}

void Board::setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void Board::selectCategory(string _userid) {
	system("cls");
	cout << "============================" << endl;
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
	cout << endl;
	cout << "      0. �α׾ƿ�" << endl;
	cout << endl;
	cout << "===========================" << endl;

	string _select;
	cout << endl;
	cout << "�Խ����� �������ּ���. (0~4) : " << endl;
	cin >> _select;

	if (_select == "1" || _select == "2" || _select == "3" || _select == "4") {
		string _category = "./data/post_";
		_category += _select;
		
		mainPost(_userid, _category, 0);
	}
	else if (_select == "0") {
		return;
	}
	else {
		cout << "�Է� ������ ���� �ʽ��ϴ�. �ٽ� �Է����ּ���... ";
		Sleep(1000);
		selectCategory(_userid);
	}

}

void Board::mainPost(string _userid, string _category, int _getFile) {
	//system("clear"); // Mac command
	system("cls"); // Windows.h

	int _cntFile = numFile(_category);
	if (_getFile == 0) {
		_getFile = _cntFile;
	}
	
	if (_cntFile == 0) {
		cout << "���� �ۼ��Ͽ� ù ����Ʈ�� �����ּ���!" << endl;
	}
	else {
		for (int i = 0; i < 10; i++) {
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
			if (stoi(data[5]) >= 10 && (stoi(data[5]) / stoi(data[6])) >= 1) {
				cout << i << ". " << "�Ű� ���� ���Դϴ�." << endl;
				cout << "	- ���� ���÷��� " << i << "���� �Է����ּ���." << endl;
			}
			else {
				cout << i << ". " << data[3] << endl;
				
				if (data[4].length() > 20) {
					string _substring = data[4].substr(0, 20);
					cout << "	- " << _substring << "..." << endl;
				}
				else {
					cout << "	- " << data[4] << endl;
				}
			}
			_getFile--;

			openpost.close();
		}
	}

	cout << "Page. " << (_cntFile - (_getFile+1))/10+1 << "/" << (_cntFile/10 + 1) << endl;
	cout << "W/w. �Խñ� �ۼ�" << endl;
	if ((_cntFile - (_getFile + 1)) / 10 + 1 < (_cntFile / 10 + 1)) {
		cout << "F/f. ���� ��������" << endl;
	}

	if ((_cntFile - (_getFile + 1)) / 10 + 1 <= 1) {
		cout << "B/b. ī�װ� ����" << endl;
	}
	else {
		cout << "B/b. ���� ��������" << endl;
	}
	string select;
	cout << "�Է� : ";
	cin >> select;
	if (select == "B" || select == "b") {
		if ((_cntFile - _getFile-1) / 10 < 1) {
			selectCategory(_userid);
		}
		else {
			if ((_cntFile - (_getFile + 1)) / 10 + 1 == (_cntFile / 10 + 1)) {
				_getFile += _cntFile % 10;
			}
			_getFile += 10;
			mainPost(_userid, _category, _getFile);
		}
		
	}
	else if (select == "F" || select == "f") {
		mainPost(_userid, _category, _getFile);
	}
	else if (select == "W" || select == "w") {
		createPost(_userid, _category, _cntFile);
	}

	else if (select == "0" || select == "1" || select == "2" || select == "3" || select == "4" || select == "5" || select == "6" || select == "7" || select == "8" || select == "9") {
		int _select = stoi(select);
		if ((_cntFile - (_getFile + 1)) / 10 + 1 == (_cntFile / 10 + 1) && _select  >= _cntFile%10) {
			cout << "�Է� ������ ���� �ʽ��ϴ�. �ٽ� �Է����ּ���... ";
			Sleep(1000);
			_getFile = _cntFile % 10;
			mainPost(_userid, _category, _getFile);
		}
		else {
			int _postnum = _cntFile - ((_cntFile - (_getFile + 1)) / 10) * 10 - _select; // �Ѱ��� ���� ��ȣ
			string _pn = to_string(_postnum);
			string subCategory = _category.substr(7, _category.size()-1);
			string dir = subCategory + "/" + _pn + ".txt";

			boardPost bP;
			bP.Post(dir, _userid);
		}
	}
	else {
		cout << "�Է� ������ ���� �ʽ��ϴ�. �ٽ� �Է����ּ���... ";
		Sleep(1000);
		if ((_cntFile - (_getFile + 1)) / 10 + 1 == (_cntFile / 10 + 1)) {
			_getFile = _cntFile % 10;
		}
		else {
			_getFile += 10;
		}
		mainPost(_userid, _category, _getFile);
	}
}

void Board::createPost(string _userid, string _category, int _postnum) {
	//system("clear"); // Mac command
	system("cls"); // Windows.h

	string _title = " ";
	string _content = "";
	string _path;
	int _befPostnum = _postnum;
	string _currentnum = to_string(++_postnum);

	vector<string> total;

	cout << "���� : ";
	cin.ignore();
	getline(cin, _title);
	if (_title == "B" || _title == "b") {
		mainPost(_userid, _category, 0);
		return;
	}
	if (_title.size() < 2 || _title.size() > 35) {
		cout << "������ ���̴� 2�� �̻� 35�� ���� �Դϴ�.";
		Sleep(1000);
		createPost(_userid, _category, _befPostnum);
	}
	else {
		cout << "=========================================";
		cout << endl;
		cout << "���� : ";
		getline(cin, _content);
		if (_content == "B" || _content == "b") {
			mainPost(_userid, _category, 0);
			return;
		}
		else if (_content.size() < 2 || _content.size() > 300) {
			cout << "������ ���̴� 2�� �̻� 300�� ���� �Դϴ�.";
			Sleep(1000);
			createPost(_userid, _category, _befPostnum);
		}
		else {


			_path += _category + "/" + _currentnum + ".txt";

			ofstream savepost(_path);

			if (savepost.is_open()) {
				time_t rawtime;
				tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);

				strftime(buffer, 80, "%Y-%m-%d-%H-%M", timeinfo);
				puts(buffer);

				string _datetime(buffer);

				// ���� ���� �ۼ� (���Ϲ�ȣ/�������̵�/�����õȳ�¥/����/����)
				// ��õ���� �Ű���� ���Ŀ� �ٸ� �Լ����� �߰����ֱ�
				total.push_back(_currentnum);
				total.push_back("/");
				total.push_back(_userid);
				total.push_back("/");
				total.push_back(_datetime);
				total.push_back("/");
				total.push_back(_title);
				total.push_back("/");
				total.push_back(_content);
				total.push_back("/0/0/");
			}
			else {
				cerr << "������ �ҷ����µ��� �����Ͽ����ϴ�." << endl;
			}

			string _post = "";


			for (int i = 0; i < total.size(); i++) {
				_post += total[i];
			}

			savepost << _post;
			savepost.close();


			// ���� �ۼ��� ������ ���ŵ� �Ķ���ͷ� �ٽ� mainPost �Լ� ȣ��
			mainPost(_userid, _category, _postnum);
		}
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
