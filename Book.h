#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "List.h"
#include <fstream>

using namespace std;

const string FILE_OF_Fiction = "fiction.txt";
const string FILE_OF_SCIENCE = "science.txt"; 

class Book
{
protected:
	string name;
	string author;
	int year;
public:
	Book() { name = ""; author = ""; year = 0; }
	~Book(){}
	void setName(string name);
	string getName();
	void setAuthor(string author);
	string getAuthor();
	void setYear(int year);
	int getYear();
	friend ostream& operator <<(ostream&, Book&);
	friend istream& operator >>(istream&, Book&);
};

