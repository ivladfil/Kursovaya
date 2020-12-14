#include "Science.h"

void Science::setField(string field) {
	this->scienceField = field;
}
string Science::getField() {
	return this->scienceField;
}
ostream& operator <<(ostream& out, Science& book) {
	out << dynamic_cast<pBook&>(book);
	out << setw(16) << book.scienceField;
	out << "||";
	cout << "\n---------------------------------------------------------------------------------\n";
	return out;
}
istream& operator >> (istream& in, Science& book) {
	in >> dynamic_cast<pBook&>(book);
	cout << "Введите научную область: ";
	cin >> book.scienceField;
	return in;
}
void Science::header() {
	cout << "---------------------------------------------------------------------------------\n";
	cout << "||" << setw(77) << " Научные книги                                  " << "||\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "||" << setw(5) << " №  " << "||" << setw(15) << " Название  " << "||" << setw(15) << " Автор ";
	cout << "||" << setw(7) << " Год " << "||" << setw(9) << "Страницы" << "||" << setw(16) << "Научная область" << "||\n";
	cout << "---------------------------------------------------------------------------------\n";
}
void Science::edit() {
	string s;
	int n;
	char ans;
	while (true) {
		cout << "\t---------Меню редактирования---------\n";
		cout << " 1 - Изменить название\n";
		cout << " 2 - Изменить автора\n";
		cout << " 3 - Изменить год издания\n";
		cout << " 4 - Изменить количество страниц\n";
		cout << " 5 - Изменить научную область\n";
		cout << " 0 - Назад\n";
		cout << "\t -> ";
		cin >> ans;
		switch (ans) {
		case '1': {
			cout << "Введите название: ";
			cin >> s;
			this->setName(s);
			break;
		}
		case '2': {
			cout << "Введите автора: ";
			cin >> s;
			this->setAuthor(s);
			break;
		}
		case '3': {
			cout << "Введите год издания: ";
			cin >> n;
			this->setYear(n);
			break;
		}
		case '4': {
			cout << "Введите количество страниц: ";
			cin >> n;
			this->setPages(n);
			break;
		}
		case '5': {
			cout << "Введите научную область:";
			cin >> s;
			this->setField(s);
			break;
		}
		case '0': return;
		default: cout << "Ошибка. Пункта меню не существует.\n";
		}
	}
}

void Science::read(List <Science>& books) {
	int vecsize;
	Science temp;
	ifstream fin(FILE_OF_SCIENCE, ios::in);
	if (fin.is_open()) {
		fin >> vecsize;
		for (int i = 0; i < vecsize; i++) {
			fin >> temp.name >> temp.author >> temp.year >> temp.scienceField >> temp.numberOfPages;
			books.push(temp);
		}
	}
	fin.close();
}

void Science::rewrite(List <Science>& books) {
	ofstream fout(FILE_OF_SCIENCE, ios::out);
	fout << books.getSize() << '\n';
	for (int i = 0; i < books.getSize(); i++)
		fout << books[i].name << ' ' << books[i].author << ' ' << books[i].year << ' ' << books[i].scienceField << ' ' << books[i].numberOfPages << '\n';
	fout.close();
}
