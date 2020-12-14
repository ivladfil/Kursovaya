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
		cout << "\t----------Главное меню---------\n";
		cout << " 1 - Вход\n 2 - Регистрация \n 0 - Выход\n";
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
		default: cout << "Ошибка. Пункта меню не существует. \n";
		}
	}
}

void Interface::adminModule(List <User>& users, List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction) {
	char ans;
	while (true) {
		int flag = 0;
		cout << "\t----------Меню Администратора------------\n";
		cout << " 1 - Работа с учётными записями\n 2 - Работа с данными\n 0 - Выход из аккаунта\n";
		cout << "\t -> ";
		cin >> ans;
		switch (ans) {
		case '1': User::workWithUsersData(users); break;
		case '2': 
			while (flag == 0) {
				cout << "\t-------------Библиотека-----------------\n";
				cout << " 1 - Электронные книги";
				cout << "\n 2 - Научные книги";
				cout << "\n 3 - Художественные книги";
				cout << "\n 0 - Выход";
				cout << "\n\t -> ";
				cin >> ans;
				switch (ans)
				{
				case '1': { Interface2<eBook>::work(ebooks); break; }
				case '2': { Interface2<Science>::work(science); break; }
				case '3': { Interface2<Fiction>::work(fiction); break; }
				case '0': flag = 1; break;
				default: cout << "Ошибка. Пункта меню не существует. \n";
				}
			}
			break;
		case '0': return;
		default: cout << "Ошибка. Пункта меню не существует. \n";
		}
	}
}

void Interface::userModule(List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction) {
	char ans;
	while (true) {
		cout << "\t-------------Библиотека----------\n";
		cout << " 1 - Электронные книги";
		cout << "\n 2 - Научные книги";
		cout << "\n 3 - Художественные книги";
		cout << "\n 0 - Выход";
		cout << "\n\t -> ";
		cin >> ans;
		switch (ans)
		{
		case '1': { Interface2<eBook>::work(ebooks); break; }
		case '2': { Interface2<Science>::work(science); break; }
		case '3': { Interface2<Fiction>::work(fiction); break; }
		case '0': return;
		default: cout << "Ошибка. Пункта меню не существует. \n";
		}
	}
}

void Interface::Exit(List <User>& users, List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction) {
	cout << "\t----------Завершение работы--------------\n";
	Fiction::rewrite(fiction);
	eBook::rewrite(ebooks);
	Science::rewrite(science);
	User::rewriteUsers(users);
	exit(0);
}

