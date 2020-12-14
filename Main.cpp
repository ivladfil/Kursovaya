#include <iostream>
#include "Interface.h"
#include <Windows.h>
#include "eBook.h"
#include "Science.h"
#include "Fiction.h"
#include "Book.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\t----------Добро Пожаловать!----------------\n";
	Interface::mainMenu();
	return 0;
}