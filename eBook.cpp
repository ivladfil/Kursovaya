#include "eBook.h"

string eBook::getFormat() {
	return this->format;
}
string eBook::getGenre() {
	return this->genre;
}
void eBook::setFormat(string format) {
	this->format = format;
}
void eBook::setGenre(string genre) {
	this->genre = genre;
}

ostream& operator <<(ostream& out, eBook& book) {
	out << dynamic_cast<Book&>(book);
	out << setw(9) << book.format;
	out << "||";
	out << setw(15) << book.genre;
	out << "||";
	cout << "\n--------------------------------------------------------------------------------\n";
	return out;
}
istream& operator >> (istream& in, eBook& book) {
	in >> dynamic_cast<Book&>(book);
	cout << "������� ������: ";
	in >> book.format;
	cout << "������� ����: ";
	in >> book.genre;
	return in;
}
void eBook::header() {
	cout << "--------------------------------------------------------------------------------\n";
	cout << "||" << setw(76) << "         ����������� �����                        " << "||\n";
	cout << "--------------------------------------------------------------------------------\n";
	cout << "||" << setw(5) << " �  " << "||" << setw(15) << " ��������  " << "||" << setw(15) << " ����� ";
	cout << "||" << setw(9) << " ��� "  "||" << setw(9) << " ������ " << "||" << setw(15) << " ���� " << "||\n";
	cout << "--------------------------------------------------------------------------------\n";
}
void eBook::edit() {
	string s;
	int n;
	char ans;
	while (true) {
		cout << "\t---------���� ��������������----------\n";
		cout << " 1 - �������� ��������\n";
		cout << " 2 - �������� ������\n";
		cout << " 3 - �������� ��� �������\n";
		cout << " 4 - �������� ������\n";
		cout << " 5 - �������� ����\n";
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
			cout << "������� ������:";
			cin >> s;
			this->setFormat(s);
			break;
		}
		case '5': {
			cout << "������� ����:";
			cin >> s;
			this->setGenre(s);
			break;
		}
		case '0': return;
		default: cout << "������. ������ ���� �� ����������.\n";
		}
	}
}

void eBook::read(List <eBook>& books) {
	int vecsize;
	eBook temp;
	ifstream fin(FILE_OF_EBOOK, ios::in);
	if (fin.is_open()) {
		fin >> vecsize;
		for (int i = 0; i < vecsize; i++) {
			fin >> temp.name >> temp.author >> temp.year >> temp.format >> temp.genre;
			books.push(temp);
		}
	}
	fin.close();
}

void eBook::rewrite(List <eBook>& books) {
	ofstream fout(FILE_OF_EBOOK, ios::out);
	fout << books.getSize() << '\n';
	for (int i = 0; i < books.getSize(); i++) {
		fout << books[i].name << ' ' << books[i].author << ' ' << books[i].year << ' ' << books[i].format << ' ' << books[i].genre << '\n';
	}
	fout.close();
}