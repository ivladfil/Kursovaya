#pragma once
#include "pBook.h"
class Fiction :
    public pBook
{
protected:
    string genre;
    string publishingHouse;
public:
	Fiction() : pBook() { genre = ""; publishingHouse = ""; }
	~Fiction(){}
	void setGenre(string genre);
	string getGenre();
	void setHouse(string house);
	string getHouse();
	friend ostream& operator <<(ostream&, Fiction&);
	friend istream& operator >> (istream&, Fiction&);
	static void read(List <Fiction>& books);
	static void rewrite(List <Fiction>& books);
	void edit();
	void header();
};

