#pragma once
#include <iostream>
#include <locale.h>
using namespace std;
class Data_TimeException {};

class data_time
{	
	unsigned int Convert_to_Julian_Date(data_time& Greg_date);
	int day, month, year, sec;
public:
	//Конструктор по умолчанию и  с параматерами:
	data_time();
	data_time(const char* date);
	
	//ввод, вывод
	friend istream& operator >>(istream& in, data_time& date);
	friend ostream& operator <<(ostream& out, const data_time& str);
};

