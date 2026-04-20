#pragma once

template <class T> class CircularListitem
{
	T data;
	CircularListitem* next;
public:
	CircularListitem(const T& adata, CircularListitem* anext);
	const T& getData() const;
	CircularListitem* getNext();
	// В объявлениях друзей
	// template повторяется
	template <class T> friend class CircularList;
};

//Работа с элементами списка:
template <class T> CircularListitem<T>::CircularListitem(const T& adata, CircularListitem<T>* anext)
{
	data = adata;
	next = anext;
}
template <class T> CircularListitem<T>* CircularListitem<T>::getNext()
{
	return next;
}
template <class T> const T& CircularListitem<T>::getData() const
{
	return data;
}
