#pragma once
#include <iostream>
#include <set>  //вот опять, хоть бы слово о том, что нужна эта библиотека, блин
#include "Nodes.h"
using namespace std;

//прикольная строка, которая позволяет не писать каждый раз "set<Node*>::const_iterator", 
// а вместо этого только node_iterator
typedef set<Node*>::const_iterator node_iterator;

class Graph {
private:
	set<Node*> nodes; //что такое ыэт надо глянуть
public:
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);

	//Следующие две строки делают класс Graph итерируемым, тоесть я могу пройтись по нему в цикле
	//begin(), end() - это встроенные функции set
	node_iterator begin() const { return nodes.begin(); }
	node_iterator end() const { return nodes.end(); }
};

