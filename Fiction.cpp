#include "Fiction.h"

void Fiction::setGenre(string genre) {
	this->genre = genre;
}
string Fiction::getGenre() {
	return this->genre;
}
void Fiction::setHouse(string house) {
	this->publishingHouse = house;
}
string Fiction::getHouse() {
	return this->publishingHouse;
}
ostream& operator <<(ostream& out, Fiction& book) {
	out << dynamic_cast<pBook&>(book);
	out << setw(15) << book.genre;
	out << "||";
	out << setw(15) << book.publishingHouse;
	out << "||";
	cout << "\n-------------------------------------------------------------------------------------------------\n";
	return out;
}
istream& operator >> (istream& in, Fiction& book) {
	in >> dynamic_cast<pBook&>(book);
	cout << "Введите жанр: ";
	cin >> book.genre;
	cout << "Введите издательство: ";
	cin >> book.publishingHouse;
	return in;
}

void Fiction::header() {
	cout << "-------------------------------------------------------------------------------------------------\n";
	cout << "||" << setw(93) << "       Художественная литература                                  " << "||\n";
	cout << "-------------------------------------------------------------------------------------------------\n";
	cout << "||" << setw(5) << " №  " << "||" << setw(15) << " Название  " << "||" << setw(15) << " Автор ";
	cout << "||" << setw(7) << " Год " << "||" << setw(9) << "Страницы" << "||" << setw(15) << " Жанр ";
	cout << "||" << setw(15) << " Издательство " << "||\n";
	cout << "-------------------------------------------------------------------------------------------------\n";

}

void Fiction::edit() {
	string s;
	int n;
	char ans;
	while (true) {
		cout << "\t---------Меню редактирования-------\n";
		cout << " 1 - Изменить название\n";
		cout << " 2 - Изменить автора\n";
		cout << " 3 - Изменить год издания\n";
		cout << " 4 - Изменить количество страниц\n";
		cout << " 5 - Изменить жанр\n";
		cout << " 6 - Изменить издательство\n";
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
			cout << "Введите жанр:";
			cin >> s;
			this->setGenre(s);
			break;
		}
		case '6': {
			cout << "Введите издательство:";
			cin >> s;
			this->setHouse(s);
			break;
		}
		case '0': return;
		default: cout << "Ошибка. Пункта меню не существует.\n";
		}
	}
}

void Fiction::read(List <Fiction>& books) {
	int vecsize;
	Fiction temp;
	ifstream fin(FILE_OF_Fiction, ios::in);
	if (fin.is_open()) {
		fin >> vecsize;
		for (int i = 0; i < vecsize; i++) {
			fin >> temp.name >> temp.author >> temp.year >>temp.genre >> temp.numberOfPages >> temp.publishingHouse;
			books.push(temp);
		}
	}
	fin.close();
}

void Fiction::rewrite(List <Fiction>& books) {
	ofstream fout(FILE_OF_Fiction, ios::out);
	fout << books.getSize() << '\n';
	for (int i = 0; i < books.getSize(); i++)
		fout << books[i].name << ' ' << books[i].author << ' ' << books[i].year << ' ' << books[i].genre << ' ' << books[i].numberOfPages << ' ' << books[i].publishingHouse << '\n';
	fout.close();
}