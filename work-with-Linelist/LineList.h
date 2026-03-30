#pragma once
#include <iostream>
#include "LineListItem.h"
using namespace std;
class LineListException {};

template <class T> class LineList 
{
	LineListElem<T>* start; // Начало списка
	LineList(const LineList& list); 
	//LineList& operator =(const LineList& list);
public:
	LineList();
	~LineList();
	//LineListElem<T>* getStart();
	void deleteFirst();
	void deleteAfter(LineListElem<T>* ptr);
	void insertFirst(const T& data);
	void insertAfter(LineListElem<T>* ptr, const T& data);
	template <class T> friend ostream& operator <<(ostream& out, LineList& list);
};

//Определения функций:
template <class T> LineList<T>::LineList()
{
	start = 0;
}
template <class T> LineList<T>::~LineList()
{
	while (start)
		deleteFirst();
}
template <class T> void LineList<T>::deleteFirst()
{
	if (start)
	{
		LineListElem<T>* temp = start->next;
		delete start;
		start = temp;
	}
	else throw LineListException();
}
template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr)
{
	if (ptr && ptr->next) {
		LineListElem<T>* temp = ptr->next;
		ptr->next = ptr->next->next;
		delete temp;
	}
	else throw LineListException();
}
template <class T> void LineList<T>::insertFirst(const T& data)
{
	LineListElem<T>* second = start;
	start = new LineListElem<T>(data, second);
}
template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data) 
{
	if (ptr) {
		LineListElem<T>* temp = ptr->next;
		ptr->next = new LineListElem<T>(data, temp);
	}
}
template <class T> ostream& operator <<(ostream& out, LineList<T>& list)
{
	LineListElem<T>* ptr = list.start;
	if (!ptr)
		out << "EMPTY ";
	else while (ptr)
	{
		out << ptr->getData() << ' ';
		ptr = ptr->getNext();
	}
	return out;
}