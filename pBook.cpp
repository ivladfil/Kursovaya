#include "pBook.h"

void pBook::setPages(int cnt) {
	this->numberOfPages = cnt;
}
int pBook::getPages() {
	return this->numberOfPages;
}
ostream& operator <<(ostream& out, pBook& book) {
	out << dynamic_cast<Book&>(book);
	out << setw(9) << book.numberOfPages;
	out << "||";
	return out;
}
istream& operator >> (istream& in, pBook& book) {
	in >> dynamic_cast<Book&>(book);
	cout << "Введите количество страниц: ";
	in >> book.numberOfPages;
	return in;
}
