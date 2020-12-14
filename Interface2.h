#pragma once
#include "List.h"
#include <iomanip>
#include <iostream>
#include "Book.h"

template <typename T>
class Interface2
{
public:
	static void work(List <T>& l);
};


template <class T>
void Interface2<T>::work(List <T>& l)
{
	T n;
	T result;
	List <T> searchResult;
	int ans;
	while (true) {
		int pos;
		cout << "\t-------------Меню---------------\n";
		cout << " 1 - Просмотр списка";
		cout << "\n 2 - Добавление в список";
		cout << "\n 3 - Редактирование";
		cout << "\n 4 - Удаление по номеру";
		cout << "\n 5 - Очистка списка";
		cout << "\n 0 - Назад";
		cout << "\n\t -> ";
		cin >> ans;
		switch (ans) {
		case 1:
			if (l.empty())
				cout << "Лист пуст!" << endl;
			else l.show();
			break;
		case 2:
			cin >> n;
			l.push(n);
			cout << "Данные добавлены." << endl;
			break;
		case 3:
			cout << "Введите индекс элемента для редактирования: ";
			cin >> pos;
			pos--;
			result = l[pos];
			result.edit();
			l.replace(result, pos);
			break;
		case 4:
			if (l.empty())
				cout << "Лист пуст!" << endl;
			else {
				cout << "Введите индекс элемента для удаления: ";
				cin >> pos;
				pos--;
				l.clear(pos);
				cout << "Данные удалены." << endl;
			}
			break;
		case 5:
			l.clear();
			cout << "Лист очищен.\n";
			break;
		case 0: return;
		}
	}
}

