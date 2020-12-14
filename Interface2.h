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
		cout << "\t-------------����---------------\n";
		cout << " 1 - �������� ������";
		cout << "\n 2 - ���������� � ������";
		cout << "\n 3 - ��������������";
		cout << "\n 4 - �������� �� ������";
		cout << "\n 5 - ������� ������";
		cout << "\n 0 - �����";
		cout << "\n\t -> ";
		cin >> ans;
		switch (ans) {
		case 1:
			if (l.empty())
				cout << "���� ����!" << endl;
			else l.show();
			break;
		case 2:
			cin >> n;
			l.push(n);
			cout << "������ ���������." << endl;
			break;
		case 3:
			cout << "������� ������ �������� ��� ��������������: ";
			cin >> pos;
			pos--;
			result = l[pos];
			result.edit();
			l.replace(result, pos);
			break;
		case 4:
			if (l.empty())
				cout << "���� ����!" << endl;
			else {
				cout << "������� ������ �������� ��� ��������: ";
				cin >> pos;
				pos--;
				l.clear(pos);
				cout << "������ �������." << endl;
			}
			break;
		case 5:
			l.clear();
			cout << "���� ������.\n";
			break;
		case 0: return;
		}
	}
}

