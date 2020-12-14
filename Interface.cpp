#include "Interface.h"

void Interface::mainMenu() {
	char ans;
	List <User> users;
	List <eBook> ebooks;
	List <Science> science;
	List <Fiction> fiction;
	User::readUsers(users);
	eBook::read(ebooks);
	Science::read(science);
	Fiction::read(fiction);
	while (true) {
		cout << "\t----------������� ����---------\n";
		cout << " 1 - ����\n 2 - ����������� \n 0 - �����\n";
		cout << "\t -> ";
		cin >> ans;
		switch (ans) {
		case '1': switch (User::signIn(users)) {
		case 0: userModule(ebooks, science, fiction); break;
		case 1: adminModule(users, ebooks, science, fiction); break;
		case 2: continue;
		}
				break;
		case '2': User::signUp(users); break;
		case '0': Exit(users, ebooks, science, fiction); break;
		default: cout << "������. ������ ���� �� ����������. \n";
		}
	}
}

void Interface::adminModule(List <User>& users, List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction) {
	char ans;
	while (true) {
		int flag = 0;
		cout << "\t----------���� ��������������------------\n";
		cout << " 1 - ������ � �������� ��������\n 2 - ������ � �������\n 0 - ����� �� ��������\n";
		cout << "\t -> ";
		cin >> ans;
		switch (ans) {
		case '1': User::workWithUsersData(users); break;
		case '2': 
			while (flag == 0) {
				cout << "\t-------------����������-----------------\n";
				cout << " 1 - ����������� �����";
				cout << "\n 2 - ������� �����";
				cout << "\n 3 - �������������� �����";
				cout << "\n 0 - �����";
				cout << "\n\t -> ";
				cin >> ans;
				switch (ans)
				{
				case '1': { Interface2<eBook>::work(ebooks); break; }
				case '2': { Interface2<Science>::work(science); break; }
				case '3': { Interface2<Fiction>::work(fiction); break; }
				case '0': flag = 1; break;
				default: cout << "������. ������ ���� �� ����������. \n";
				}
			}
			break;
		case '0': return;
		default: cout << "������. ������ ���� �� ����������. \n";
		}
	}
}

void Interface::userModule(List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction) {
	char ans;
	while (true) {
		cout << "\t-------------����������----------\n";
		cout << " 1 - ����������� �����";
		cout << "\n 2 - ������� �����";
		cout << "\n 3 - �������������� �����";
		cout << "\n 0 - �����";
		cout << "\n\t -> ";
		cin >> ans;
		switch (ans)
		{
		case '1': { Interface2<eBook>::work(ebooks); break; }
		case '2': { Interface2<Science>::work(science); break; }
		case '3': { Interface2<Fiction>::work(fiction); break; }
		case '0': return;
		default: cout << "������. ������ ���� �� ����������. \n";
		}
	}
}

void Interface::Exit(List <User>& users, List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction) {
	cout << "\t----------���������� ������--------------\n";
	Fiction::rewrite(fiction);
	eBook::rewrite(ebooks);
	Science::rewrite(science);
	User::rewriteUsers(users);
	exit(0);
}

