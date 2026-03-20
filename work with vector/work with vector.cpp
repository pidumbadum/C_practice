// work with vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "vector.h"
#include <chrono>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    /*Array arr(4);
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
    cout << arr << endl;*/

    Array arr1(1000);
    for (int i = 0; i < 1000; i++)
        arr1.insert(i + 1);
    Array arr2(5000);
    for (int i = 0; i < 5000; i++)
        arr2.insert(i + 1);
    Array arr3(10000);
    for (int i = 0; i < 10000; i++)
        arr3.insert(i + 1);
    Array arr4(50000);
    for (int i = 0; i < 50000; i++)
        arr4.insert(i + 1);
    Array arr5(100000);
    for (int i = 0; i < 100000; i++)
        arr5.insert(i + 1);
    Array arr6(500000);
    for (int i = 0; i < 500000; i++)
        arr6.insert(i + 1);
    Array arr7(1000000);
    for (int i = 0; i < 1000000; i++)
        arr7.insert(i + 1);

    int i = 0;
    int k = 3; 
    /*cout << "Enter the k: ";
    cin >> k;*/
    k--;
    
    auto start = chrono::high_resolution_clock::now(); //засекли
    while (arr1.size != 1)
    {
        i = (i + k) % arr1.size;
        arr1.remove(i);
    }
    cout << arr1;
   
    /*while (arr2.size != 1)
    {
        i = (i + k) % arr2.size;
        arr2.remove(i);
    }
    cout << arr2;*/
    
    /*while (arr3.size != 1)
    {
        i = (i + k) % arr3.size;
        arr3.remove(i);
    }
    cout << arr3;*/
    
    /*while (arr4.size != 1)
    {
        i = (i + k) % arr4.size;
        arr4.remove(i);
    }
    cout << arr4;*/
    
    /*while (arr5.size != 1)
    {
        i = (i + k) % arr5.size;
        arr5.remove(i);
    }
    cout << arr5;*/
    
    /*while (arr6.size != 1)
    {
        i = (i + k) % arr6.size;
        arr6.remove(i);
    }
    cout << arr6;*/
    
    /*while (arr7.size != 1)
    {
        i = (i + k) % arr7.size;
        arr7.remove(i);
    }
    cout << arr7;*/
    auto end = chrono::high_resolution_clock::now(); //стоп
    chrono::duration<double> diff = end - start;
    cout << "Время выполнения: " << diff.count() << " с" << std::endl;
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
