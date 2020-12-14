#pragma once
#include "Book.h"

const string FILE_OF_EBOOK = "ebook.txt";

class eBook :
	public Book
{
protected:
	string format;
	string genre;
public:
	eBook() :Book() { format = ""; genre = ""; }
	~eBook() {}
	string getFormat();
	string getGenre();
	void setFormat(string format);
	void setGenre(string genre);
	friend ostream& operator <<(ostream&, eBook&);
	friend istream& operator >> (istream&, eBook&);
	static void header();
	void edit();
	static void read(List <eBook>& books);
	static void rewrite(List <eBook>& books);
};

