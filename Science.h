#pragma once
#include "pBook.h"

class Science :
    public pBook
{
protected:
    string scienceField;
public:
	Science() : pBook() { scienceField = "";}
	~Science(){}
	void setField(string field);
	string getField();
	friend ostream& operator <<(ostream&, Science&);
	friend istream& operator >> (istream&, Science&);
	static void header();
	void edit();
	static void read(List <Science>& books);
	static void rewrite(List <Science>& books);
};

