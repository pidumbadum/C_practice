#pragma once
#include <iostream>
#include <locale.h>
using namespace std;
class date_TimeException {};

class date_time
{	
	double toJulian_date() const;
	void Check_enters() const;
	int day, month, year, sec;
public:
	//Конструктор по умолчанию и  с параматерами:
	date_time();
	date_time(const char* date);

	date_time operator = (const date_time& date);
	
	//разница между датами в днях
	int dates_diff(const date_time &date1) const;
	//день недели
	const char* day_of_week();
	//Дата пасхи
	static date_time Easter_date(int year);


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

