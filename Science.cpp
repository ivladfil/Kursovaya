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
	cout << "������� ������� �������: ";
	cin >> book.scienceField;
	return in;
}
void Science::header() {
	cout << "---------------------------------------------------------------------------------\n";
	cout << "||" << setw(77) << " ������� �����                                  " << "||\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "||" << setw(5) << " �  " << "||" << setw(15) << " ��������  " << "||" << setw(15) << " ����� ";
	cout << "||" << setw(7) << " ��� " << "||" << setw(9) << "��������" << "||" << setw(16) << "������� �������" << "||\n";
	cout << "---------------------------------------------------------------------------------\n";
}
void Science::edit() {
	string s;
	int n;
	char ans;
	while (true) {
		cout << "\t---------���� ��������������---------\n";
		cout << " 1 - �������� ��������\n";
		cout << " 2 - �������� ������\n";
		cout << " 3 - �������� ��� �������\n";
		cout << " 4 - �������� ���������� �������\n";
		cout << " 5 - �������� ������� �������\n";
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
			cout << "������� ������� �������:";
			cin >> s;
			this->setField(s);
			break;
		}
		case '0': return;
		default: cout << "������. ������ ���� �� ����������.\n";
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
