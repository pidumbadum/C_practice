#pragma once
#include <iostream>
#include <set>  //вот опять, хоть бы слово о том, что нужна эта библиотека, блин
#include "Nodes.h"
using namespace std;

typedef set<Node*>::const_iterator node_iterator;

class Graph {
private:
	set<Node*> nodes;
public:
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);
	node_iterator begin() const {
		return nodes.begin();
	}
	node_iterator end() const { return nodes.end(); }
};

