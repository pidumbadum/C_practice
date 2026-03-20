#pragma once
#include <iostream>
using namespace std;
const int DEFAULT_CAPACITY = 10;
class ArrayException {};

class Array
{
private:

public:
	int* ptr;
	int size; // Текущий размер
	int capacity; // Вместимость
	explicit Array(int startCapacity = DEFAULT_CAPACITY);

	~Array();

	Array(const Array& arr);
	Array& operator = (const Array& arr); //вот тут почему передается const Array& arr, а не int

	int& operator [] (int index);

	//вставка элемпентов в массив 
	void increaseCapacity(int newCapacity);
	void insert(int index, int elem);
	void insert(int elem);
	void remove(int index);

	//Получение размера
	// Вывод массива в поток
	int getSize() const;
	friend ostream& operator <<(ostream& out, const Array& arr);
};

