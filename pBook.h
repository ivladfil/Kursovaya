#pragma once
#include "Book.h"

class pBook :
    public Book
{
protected:
    int numberOfPages;
public:
	pBook() : Book() { numberOfPages = 0;}
	~pBook(){}
	void setPages(int cnt);
	int getPages();
	friend ostream& operator <<(ostream&, pBook&);
	friend istream& operator >> (istream&, pBook&);
};

