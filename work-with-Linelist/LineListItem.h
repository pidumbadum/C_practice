#pragma once

template <class T> class LineListElem
{
	T data;
	LineListElem* next;
public:
	LineListElem(const T& adata, LineListElem* anext);
	const T& getData() const;
	LineListElem* getNext();
	// В объявлениях друзей
	// template повторяется
	template <class T> friend class LineList;
};

//Определения функций:
template <class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext)
{
	data = adata;
	next = anext;
}
template <class T> LineListElem<T>* LineListElem<T>::getNext()
{
	return next;
}
template <class T> const T& LineListElem<T>::getData() const
{
	return data;
}
