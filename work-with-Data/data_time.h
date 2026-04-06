#pragma once
#include <iostream>
#include <locale.h>
using namespace std;
class Data_TimeException {};

class data_time
{	
	unsigned int toJulian_date() const;
	int day, month, year, sec, day_week;
public:
	//Конструктор по умолчанию и  с параматерами:
	data_time();
	data_time(const char* date);
	
	//сравнение
	bool operator == (const data_time& r) const;
	bool operator != (const data_time& r) const;
	bool operator > (const data_time& r) const;
	bool operator >= (const data_time& r) const;
	bool operator < (const data_time& r) const;
	bool operator <= (const data_time& r) const;

	//ввод, вывод
	friend istream& operator >>(istream& in, data_time& date);
	friend ostream& operator <<(ostream& out, const data_time& str);
};

