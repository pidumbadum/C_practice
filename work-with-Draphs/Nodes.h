#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set> //глянуть как работает
using namespace std;

class Node {
private:
	string name; 
	//Идея: вместо set использовать map<ссылка узла, вес пути к нему>
	map<Node*, int> neighbours;
	void addNeighbour(Node* neighbour, int weight);
	void removeNeighbour(Node* neighbour);
	set<string> get_nb_name() const;
	typedef map<Node*, int>::const_iterator node_iterator;
public:
	Node(const string& aname) : name(aname) {}
	const string& getName() const { return name; }
	node_iterator nb_begin() const { return neighbours.begin(); }
	node_iterator nb_end() const { return neighbours.end(); }
	friend class Graph;
};

