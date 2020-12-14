#include "Book.h"

void Book::setName(string name) {
	this->name = name;
}
string Book::getName() {
	return this->name;
}
void Book::setAuthor(string author) {
	this->author = author;
}
string Book::getAuthor() {
	return this->author;
}
void Book::setYear(int year) {
	this->year = year;
}
int Book::getYear() {
	return this->year;
}
ostream& operator <<(ostream& out, Book& book) {
	out << "||";
	out << setw(15) << book.name;
	out << "||";
	out << setw(15) << book.author;
	out << "||";
	out << setw(7) << book.year;
	out << "||";
	return out;
}
istream& operator >> (istream& in, Book& book) {
	cout << "¬ведите название: ";
	in >> book.name;
	cout << "¬ведите автора: ";
	in >> book.author;
	cout << "¬ведите год публикации: ";
	in >> book.year;
	return in;
}
