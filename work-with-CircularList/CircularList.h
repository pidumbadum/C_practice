#include <iostream>
#include "CircularListItem.h"
using namespace std;
class CircularListException {};

template <class T> class CircularList
{
	CircularListitem<T>* start; // Начало списка
	CircularListitem<T>* end; // Конец списка
	//CircularList(const CircularList& list); //конструктор копирования, пока пусть поивисит
	//CircularList& operator =(const CircularList& list); НЕ ЗАБУДЬ ДОДЛАТЬ
public:
	//Конструктор по умолчанию
	CircularList();
	//Деструктор
	~CircularList();
	CircularListitem<T>* getStart() const { return start; };
	//Удаление
	void deleteFirst();
	void deleteAfter(CircularListitem<T>* ptr);
	//добавление
	void insertFirst(const T& data);
	void insertAfter(CircularListitem<T>* ptr, const T& data);
	//опретаоры ввода и вывода
	template <class T> friend ostream& operator <<(ostream& out, CircularList& list);
};

//Конструктор по умолчанию
template <class T> CircularList<T>::CircularList()
{
	start = 0;
	end = 0
}
//Деструктор
template <class T> CircularList<T>::~CircularList()
{
	while (start)
		deleteFirst();
}
//Удаление
template <class T> void CircularList<T>::deleteFirst()
{
	if (start)
	{
		if (start == end) {
			delete start;
			start = nullptr; 
			end = nullptr;
		}
		else {
			CircularListitem<T>* temp = start->next;
			end->next = temp;
			delete start;
			start = temp;
		}
	}
	else throw CircularListException();
}
template <class T> void CircularList<T>::deleteAfter(CircularListitem<T>* ptr)
{
	if (ptr && ptr->next) {
		if (ptr->next == start) {
			deleteFirst();
		}
		else {
			CircularListitem<T>* temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
		}
	}
	else throw CircularListException();
}
//добавление
template <class T> void CircularList<T>::insertFirst(const T& data)
{
	if (start) {
		CircularListitem<T>* second = start;
		start = new CircularListitem<T>(data, second);
		if (second->next == second) { second->next = start; }
	}
	else {
		start = new CircularListitem<T>(data, nullptr);
		start->next = start;
	}
}
template <class T> void CircularList<T>::insertAfter(CircularListitem<T>* ptr, const T& data)
{
	if (ptr) {
		CircularListitem<T>* temp = ptr->next;
		ptr->next = new CircularListitem<T>(data, temp);
	}
}
//опретаоры ввода и вывода
template <class T> ostream& operator <<(ostream& out, CircularList<T>& list)
{

	CircularListitem<T>* ptr = list.getStart();
	if (!ptr)
		out << "EMPTY ";
	else do
	{
		out << ptr->getData() << ' ';
		ptr = ptr->getNext();
	} while (ptr != list.getStart());
	return out;
}