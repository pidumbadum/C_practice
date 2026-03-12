#pragma once
const int DEFAULT_CAPACITY = 10;
class ArrayException {};

class Array
{
private:
	int* ptr; // Указатель на массив в динамич. памяти
	int size; // Текущий размер
	int capacity;// Вместимость

public:
	explicit Array(int startCapacity = DEFAULT_CAPACITY);
	~Array();

	Array& operator =(const Array& arr);
	int& operator [](int index);
};

