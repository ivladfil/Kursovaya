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
	cout << "������� ����: ";
	cin >> book.genre;
	cout << "������� ������������: ";
	cin >> book.publishingHouse;
	return in;
}

void Fiction::header() {
	cout << "-------------------------------------------------------------------------------------------------\n";
	cout << "||" << setw(93) << "       �������������� ����������                                  " << "||\n";
	cout << "-------------------------------------------------------------------------------------------------\n";
	cout << "||" << setw(5) << " �  " << "||" << setw(15) << " ��������  " << "||" << setw(15) << " ����� ";
	cout << "||" << setw(7) << " ��� " << "||" << setw(9) << "��������" << "||" << setw(15) << " ���� ";
	cout << "||" << setw(15) << " ������������ " << "||\n";
	cout << "-------------------------------------------------------------------------------------------------\n";

}

void Fiction::edit() {
	string s;
	int n;
	char ans;
	while (true) {
		cout << "\t---------���� ��������������-------\n";
		cout << " 1 - �������� ��������\n";
		cout << " 2 - �������� ������\n";
		cout << " 3 - �������� ��� �������\n";
		cout << " 4 - �������� ���������� �������\n";
		cout << " 5 - �������� ����\n";
		cout << " 6 - �������� ������������\n";
		cout << " 0 - �����\n";
		cout << "\t -> ";
		cin >> ans;
		switch (ans) {
		case '1': {
			cout << "������� ��������: ";
			cin >> s;
			this->setName(s);
			break;
		}
		case '2': {
			cout << "������� ������: ";
			cin >> s;
			this->setAuthor(s);
			break;
		}
		case '3': {
			cout << "������� ��� �������: ";
			cin >> n;
			this->setYear(n);
			break;
		}
		case '4': {
			cout << "������� ���������� �������: ";
			cin >> n;
			this->setPages(n);
			break;
		}
		case '5': {
			cout << "������� ����:";
			cin >> s;
			this->setGenre(s);
			break;
		}
		case '6': {
			cout << "������� ������������:";
			cin >> s;
			this->setHouse(s);
			break;
		}
		case '0': return;
		default: cout << "������. ������ ���� �� ����������.\n";
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