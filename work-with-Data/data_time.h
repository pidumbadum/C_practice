#pragma once
#include <iostream>
#include <locale.h>
using namespace std;
//setlocale(LC_ALL, "ru");
class Data_TimeException {};

class data_time
{	
	int day, month, year, sec;
public:
	//Конструктор по умолчанию и  с параматерами:
	data_time();
	data_time(const char* date);
	
	//ввод, вывод
	friend istream& operator >>(istream& in, data_time& str);
	friend ostream& operator <<(ostream& out, const data_time& str);
};

