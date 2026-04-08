// work-with-data.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "data_time.h"
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	data_time basic;
	data_time date2;
	cout << "Enter the second date: ";
	cin >> date2;
	data_time date3("41 августа 2017");
	cout << "First: " << basic<<endl;
	cout << endl;
	cout << "Second: " << date2 << endl;
	cout << endl;
	cout << "Third: " << date3 << endl;
	cout << "Second = Third? " << (date2 == date3) <<endl;
	cout << "Second != Third? " << (date2 != date3) << endl;
	cout << "Second < Third? " << (date2 < date3) << endl;
	cout << "Second > Third? " << (date2 > date3) << endl;

	//проверка проверки ввода
	try {
		data_time check1("29.02.2000");
		cout <<"Everything is allright!"<< check1 << endl; 
	}
	catch(Data_TimeException()){
		cout << "test 1 Error" << endl;
	}
	try {
		data_time check2("29.02.1400");
		cout << "Everything is allright!" << check2 << endl;
	}
	catch (Data_TimeException()) {
		cout << "test 2 Error" << endl;
	}
	try {
		data_time check3("31.08.2001");
		cout << "Everything is allright!" << check3 << endl;
	}
	catch (Data_TimeException()) {
		cout << "test 3 Error" << endl;
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
