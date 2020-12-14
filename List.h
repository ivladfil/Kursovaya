#pragma once
#include <iostream>
#include <iomanip>
#include <type_traits>

using namespace std;

template <typename T>
struct node {
	T data;
	node* next = NULL, * prev = NULL;
};

template <class T>
class List {
protected:
	node<T>* top;
	node<T>* end;
	int size = 1;
public:
	List();
	~List();
	void push(T info);
	void pop();
	void clear();
	void show();
	void clear(int pos);
	void replace(T new_info, int);
	int getSize();
	bool empty();
	int exist(string info);
	T& operator[] (int pos);
};

template <typename T>
List<T>::List()
{
	top = NULL;
	end = NULL;
	size = 0;
}

template <typename T>
List<T>::~List()
{
	if (top != 0)
		delete top;
	if (end != 0)
		delete end;
}

template <class T>
bool List<T>::empty() {
	if (this->top == 0 || this->end == 0)
		return true;
	else return false;
}

template <class T>
int List<T>::exist(string info) {
	node<T>* buf = top;
	int cnt = 0;
	while (buf != 0) {
		if (buf->data == info)
			return cnt;
		buf = buf->next;
		cnt++;
	}
	return -1;
}

template <typename T>
int List<T>::getSize() {
	return size;
}

template<typename T>
void List<T>::push(T info)
{
	node<T>* buf = new node<T>;
	buf->data = info;
	buf->next = NULL;
	buf->prev = NULL;
	if (top != 0 && end != 0) {
		top->prev = buf;
		buf->next = top;
		top = buf;
	}
	if (top == 0 && end != 0) {
		top = buf;
		top->next = end;
		end->prev = top;
	}
	if (end == 0) {
		end = buf;
		top = buf;
	}
	size++;
}

template<typename T>
void List<T>::pop() {
	node<T>* buf = top;
	if (top->next == 0) {
		top = 0;
		end = 0;
	}
	else {
		top->next->prev = NULL;
		top = top->next;
	}
	size--;
	delete buf;
}

template <typename T>
void List<T>::show() {
	node<T>* buf = top;
	int i = 1;
	buf->data.header();
	while (buf != 0) {
		cout << "||" << setw(5) << i;
		cout << buf->data;
		buf = buf->next;
		i++;
	}
}


template <typename T>
void List<T>::clear() {
	while (top != 0)
		pop();
}

template<typename T>
void List<T>::clear(int pos)
{
	node<T>* buf = top;
	for (int i = 0; i <= pos; i++)
	{
		if (buf == top && size == 1 && i == pos)
		{
			buf->next = NULL;
			buf->prev = NULL;
			top = NULL;
			end = NULL;
			size = 0;
			return;
		}
		if (buf == top && i == pos)
		{
			buf->next->prev = NULL;
			top = buf->next;
			size--;
			continue;
		}
		else
		{
			if (buf == end && i == pos)
			{
				end = buf->prev;
				buf->prev->next = NULL;
				size--;
				return;
			}
			else
				if (size == 3 && i == pos)
				{
					top->next = end;
					end->prev = top;
					size--;
					continue;
				}
				else if (i == pos)
				{
					buf->next->prev = buf->prev;
					buf->prev->next = buf->next;
					delete buf;
					size--;
					continue;
				}
		}
		buf = buf->next;
	}
}

template<typename T>
void List<T>::replace(T new_info, int pos) {
	node<T>* buf = top;
	for (int i = 0; i <= pos; i++) {
		if (i == pos) buf->data = new_info;
		buf = buf->next;
	}
}


template <class T>
T& List<T>::operator[] (int pos) {
	node<T>* temp = top;
	for (int i = 0; i <= pos; i++)
		if (i == pos)
			return temp->data;
		else
			temp = temp->next;
	return temp->data;
}