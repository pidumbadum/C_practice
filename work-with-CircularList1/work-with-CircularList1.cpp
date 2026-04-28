// work-with-CircularList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <locale>
#include "CircularList.h"
#include <chrono>
using namespace std;
using namespace chrono;



int main()
{

    //setlocale(LC_ALL, "Russian");
    int sizes[] = { 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    int num_tests = 7;  // Сколько размеров в массиве
    int k = 3;
    /*cout << "Enter the k: ";
    cin >> k;*/

    for (int t = 0; t < num_tests; t++) {
        int SIZE = sizes[t];  // Берём текущий размер
        CircularList<int> list;

        //Cоздаем список:
        for (int i = 0; i < SIZE; i++) {
            CircularListitem<int>* ptr = list.getEnd();
            if (!ptr) {
                list.insertFirst(i + 1);
            }
            else {
                list.insertAfter(ptr, i + 1);
            }
        }
        auto start = chrono::high_resolution_clock::now(); //засекли
        //Удаляем каждый третий, пока не сотанется один
        while (list.getStart() != list.getEnd()) {
            for (int step = 0; step < k; step++) {
                //тут надо менять новую ссылку столько раз, чтоб она равнялась n-1 элементу списка
                // если тот, который нужно удалить = n
            }
        }

        auto end = chrono::high_resolution_clock::now(); //стоп
        chrono::duration<double> diff = end - start;
        cout << "Время(сек.)     Длина списка" << endl;
        cout << diff.count() <<"c." << "        " << SIZE << endl;
    }
    
    return 0;

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
