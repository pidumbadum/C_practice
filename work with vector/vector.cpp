#include "vector.h"

Array::Array(int startCapacity)
{
	if (startCapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startCapacity;
	ptr = new int[capacity];
	size = 0;
}
Array::~Array()
{
	delete[] ptr;
}
Array& Array::operator = (const Array& arr)
{
	if (this == &arr)
		return *this; //почему тут указатели? 
	if (capacity != arr.capacity)
	{
		delete[] ptr;
		ptr = new int[arr.capacity];
		capacity = arr.capacity;
	}
	size = arr.size;
	for (int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
	return *this;
}
int& Array::operator [](int index) 
{
	if (index >= size || index < 0)
		throw ArrayException();
	else
		return ptr[index];
}