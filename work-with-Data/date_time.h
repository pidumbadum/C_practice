#pragma once
#include <iostream>
#include <locale.h>
using namespace std;
class date_TimeException {};

class date_time
{	
	unsigned int toJulian_date() const;
	void Check_enters() const;
	int day, month, year, sec, day_week;
public:
	//Конструктор по умолчанию и  с параматерами:
	date_time();
	date_time(const char* date);
	
	//сравнение
	bool operator == (const date_time& r) const;
	bool operator != (const date_time& r) const;
	bool operator > (const date_time& r) const;
	bool operator >= (const date_time& r) const;
	bool operator < (const date_time& r) const;
	bool operator <= (const date_time& r) const;

	//ввод, вывод
	friend istream& operator >>(istream& in, date_time& date);
	friend ostream& operator <<(ostream& out, const date_time& str);
};

