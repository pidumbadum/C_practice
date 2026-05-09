#pragma once
#include <iostream>
#include <string>
#include <set> //глянуть как работает
using namespace std;

class Node {
private:
	string name; 
	set<Node*> neighbours;
	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);

	typedef set<Node*>::const_iterator node_iterator;
public:
	Node(const string& aname) : name(aname) {}
	const string& getName() const { return name; }
	node_iterator nb_begin() const { return neighbours.begin(); }
	node_iterator nb_end() const { return neighbours.end(); }
	friend class Graph;
};

