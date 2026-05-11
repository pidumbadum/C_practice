// work-with-Draphs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include <string>
#include <set>
#include "Graph.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Привет. Это тест графа\n";
    Graph graph;
    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    Node* d = new Node("D");

    //добавление узлов
    graph.addNode(a);
    graph.addNode(b);
    graph.addNode(c);
    graph.addNode(d);

    //добавление связей
    graph.addEdge(a, b);  // A - B
    graph.addEdge(b, c);  // B - C
    graph.addEdge(a, d);  // A - D
    graph.addEdge(d, b);  // D - B

    cout << "Все узлы в графе:\n";
    for (Graph::node_iterator node = graph.begin(); node != graph.end(); ++node) {
        cout << (*node)->getName() << endl;
    }
    cout << endl;

    cout << "Связи в графе:";
    for (Graph::node_iterator node = graph.begin(); node != graph.end(); ++node) {
        cout <<"\nЭлемент: "<< (*node)->getName() << endl;
        cout << "Связи:";
        // Используем const auto& для экономии ресурсов
        for (const auto& element : graph.nb_names(*node)) {
            cout << element << " ";
        }
        cout << "\n--------------------";
    }

    //проверка того, что удаление узлов работате как надо
    cout << "\n\nУдаление B";
    graph.removeNode(b);
    cout << "\nСвязи в графе после удаления:";
    for (Graph::node_iterator node = graph.begin(); node != graph.end(); ++node) {
        cout << "\nЭлемент: " << (*node)->getName() << endl;
        if (graph.nb_names(*node).empty()) {
            cout << " Нет связей";
        }
        else {
            cout << "Связи:";
            for (const auto& element : graph.nb_names(*node)) {
                cout << element << " ";
            }
        }
        cout << "\n--------------------";
    }

    //проверка того, что удаление связей между узлами работате как надо
    cout << "\n\nУдаление связи A-D";
    graph.removeEdge(a, d);
    cout << "\nСвязи в графе после удаления:";
    for (Graph::node_iterator node = graph.begin(); node != graph.end(); ++node) {
        cout << "\nЭлемент: " << (*node)->getName() << endl;
        if (graph.nb_names(*node).empty()) {
            cout << " Нет связей";
        }
        else {
            cout << "Связи:";
            for (const auto& element : graph.nb_names(*node)) {
                cout << element << " ";
            }
        }
        cout << "\n--------------------";
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
