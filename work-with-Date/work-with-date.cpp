// work-with-date.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "date_time.h"
#include <clocale>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //жуть какие необхождимые строки
	//18 августа 2017
	date_time basic;
	date_time date2;
	cout << "Enter the second date: ";
	cin >> date2;
	date_time date3("2021-12-21T07:54:34");
	date_time date4("2021-12-21T18:20:40");
	cout << endl << "Difference between first date and second date: " << basic.dates_diff(date2)<<endl;
	cout << "First: " << basic<<endl;
	cout << endl << "Second: " << date2 << endl;
	cout << endl<< "Third: " << date3 << endl;
	cout << endl << "Four: " << date4 << endl;
	cout << endl << "Cheking comparison operators:" << endl;
	cout << "Second = Third? " << (date2 == date3) <<endl;
	cout << "Second != Third? " << (date2 != date3) << endl;
	cout << "Second < Third? " << (date2 < date3) << endl;
	cout << "Second > Third? " << (date2 > date3) << endl;
	cout << endl << "Cheking comparison operators with time:" << endl;
	cout << "Third = Four " << (date3 == date4) << endl;
	cout << "Third != Four " << (date3 != date4) << endl;
	cout << "Third < Four " << (date3 < date4) << endl;
	cout << "Third > Four " << (date3 > date4) << endl;


	//проверка проверки ввода
	cout << endl << "Input validation:" << endl;
	try {
		date_time check1("29.02.2000");
		cout <<"29.02.2000 is allright!"<< endl; 
	}
	catch(date_TimeException&){
		cout << "test 29.02.2000 Error" << endl;
	}
	try {
		date_time check2("29.02.1400");
		cout << "29.02.1400 is allright!"<< endl;
	}
	catch (date_TimeException&) {
		cout << "test 29.02.1400 Error" << endl;
	}
	try {
		date_time check3("31.08.2001");
		cout << "31.08.2001 is allright!"<< endl;
	}
	catch (date_TimeException&) {
		cout << "test 31.08.2001 Error" << endl;
	}
	try {
		date_time check4("2021-12-21T25:00:40");
		cout << "2021-12-21T25:00:40 is allright!" << endl;
	}
	catch (date_TimeException&) {
		cout << "test 2021-12-21T25:00:40 Error" << endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
