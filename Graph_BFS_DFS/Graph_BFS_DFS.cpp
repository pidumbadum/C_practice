// Graph_BFS_DFS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <locale>
#include <string>
#include <set>
#include "BFS.h"
#include "DFS.h"
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
    Node* e = new Node("E");

    //добавление узлов
    graph.addNode(a);
    graph.addNode(b);
    graph.addNode(c);
    graph.addNode(d);
    graph.addNode(e);

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
    //проверим bfs
    BFS bfs_test(graph);
    cout << "\nBFS:";
    cout << "\nЕсть ли путь A - C?";
    bfs_test.connected(a, c) ? cout << " Да!" : cout << " Нет!";
    cout << "\nЕсть ли путь A - E?";
    bfs_test.connected(a, e) ? cout << " Да!" : cout << " Нет!";

    //проверим dfs
    DFS dfs_test(graph);
    cout << "\n\nDFS:";
    cout << "\nЕсть ли путь A - C?";
    dfs_test.connected(a, c) ? cout << " Да!" : cout << " Нет!";
    cout << "\nЕсть ли путь A - E?";
    dfs_test.connected(a, e) ? cout << " Да!" : cout << " Нет!";
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
