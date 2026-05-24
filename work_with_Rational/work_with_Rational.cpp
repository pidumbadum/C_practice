// work with Rastional.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include "Rational.h"
#include <limits>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    //// Тестируем конструктор, +, -, *=, /, <<
    //Rational a(1, 2), b(-1, 6);
    //cout << "a=" << a << " b=" << b << " a+b=" << a + b << endl;
    //cout << "a(" << a << ") *= b(" << b << ")" << endl;
    //a *= b;
    //cout << "a=" << a << " b=" << b << " a-b=" << a - b << endl; // вот этот тест идет по одному месту
    //Rational c = 3;
    //cout << "b=" << b << " c=" << c << " b/c=" << b / c << endl;

    //// Тестируем >>, !=
    //Rational e(7, 8), f(5, 12);
    //cout << "e=" << e << " f=" << f << " e+f=?" << endl;
    //cout << "Введите результат g=m/n в формате: m n" << endl;
    //Rational g;
    //cin >> g;
    //if (e + f != g)
    //    cout << "Неправильно! e+f=" << e + f << endl;
    //else
    //    cout << "Правильно!" << endl;

    cout << "Double to Rational checking:" << endl;
    double chek_d = 2.0305;
    Rational chek_d2(chek_d);
    cout << "Rational: " << chek_d2 << ", double: " << double(chek_d2) << endl;
    cout << "\nSQRT func checking:" << endl;
    Rational eb(4, 25);
    Rational alo(11, 32);
    cout << "Number: " << eb << " sqrt:" << eb.sqrt() << endl;
    cout << "Number: " << alo << " sqrt:" << alo.sqrt() << endl;

    // Тестируем sqrt, решаем квадратное уравнение
    //Ожидаемый ответ х1 = 11/117, х2 = 19/119
    Rational a(1);
    Rational b(-3532, 13923);
    Rational c(209, 13923);
    cout << "\nx^2 + (" << b << "x) + " << c << " = 0\n";
    Rational D;
    D = b * b - Rational(4) * a * c;
    cout << "Discriminant is " << D;
    cout << endl << b * b;
    cout << endl << Rational(4) * a * c;
    bool chek = ((b * b) <= Rational(4) * a * c);
    cout <<endl<< chek;
  
    Rational x1, x2, SQ_D;

    if (D < Rational(0))
    {
        cout << "\nDiscriminant is lower then zero!";
    }
    else
    {
        SQ_D = D.sqrt();
        cout << "\nDiscriminant sqrt is ";
        cout << SQ_D << endl;
        x1 = (-b - SQ_D) / (a * Rational(2));
        x2 = (-b + SQ_D) / (a * Rational(2));
        if (x1 != x2)
        {
            cout << "X1 = " << x1 << endl;
            cout << "X2 = " << x2 << endl;
        }
        else { cout << "X1, X2 = " << x1; }
    }

    cout << "ТЕСТ ПЕРЕПОЛНЕНИЯ" << endl << endl;
    //переполнение при сложении
    try {
        Rational a(INT_MAX - 10, 1);
        Rational b(20, 1);
        cout <<endl << a<<'+'<<b << '=' << endl;
        Rational c = a + b; // Числитель превысит INT_MAX

        cout << "Плохо" << c << endl;
    }
    catch (...) {
        cout << "1. Переполнение при сложении!" << endl;
    }

    try {
        // 50 000 * 50 000 = 2 500 000 000 (> INT_MAX)
        Rational a(50000, 1);
        Rational b(50000, 1);
        cout << endl << a << '*' << b << '=' << endl;
        Rational c = a * b;

        cout << "Плохо " << c << endl;
    }
    catch (...) {
        cout << "2.Переполнение при умножении!" << endl;
    }

    try {
        Rational a(INT_MIN + 10, 1);
        Rational b(20, 1);
        cout << endl << a << '-' << b << '=' << endl;
        Rational c = a - b; // Числитель уйдёт ниже INT_MIN

        cout << "Плохо" << c << endl;
    }
    catch (...) {
        cout << "3.Переполнение при вычитании!" << endl;
    }

    cout << "\nТЕСТ ЗАВЕРШЁН" << endl;

    //Балуюсь с double

}
