// work with vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Array arr(4);
    for (int i = 0; i < 4; i++)
        arr.insert(i + 1);
    cout << arr << endl;
    for (int i = 0; i < 8; i += 2)
        arr.insert(10 + i, i);
    cout << arr << endl;
    for (int i = 1; i < 8; i += 2)
        arr[i] = 20 + i;
    cout << arr << endl;
    for (int i = 6; i >= 0; i -= 3)
        arr.remove(i);
    cout << arr << endl;

    /*Array arr1(1000);
    for (int i = 0; i < 1000; i++)
        arr1.insert(i);
    Array arr2(5000);
    for (int i = 0; i < 5000; i++)
        arr1.insert(i);
    Array arr3(10000);
    for (int i = 0; i < 4; i++)
        arr1.insert(i);
    Array arr4(50000);
    for (int i = 0; i < 4; i++)
        arr1.insert(i);
    Array arr5(100000);
    for (int i = 0; i < 4; i++)
        arr1.insert(i);
    Array arr6(500000);
    for (int i = 0; i < 4; i++)
        arr1.insert(i);
    Array arr7(1000000);
    for (int i = 0; i < 4; i++)
        arr1.insert(i);*/

    /*Array arr(100);
    for (int i = 0; i < 13; i++)
        arr.insert(i+1);

    while (arr.size != 1)
    {
       

    }
    cout << arr;*/
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
