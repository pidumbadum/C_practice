#pragma once
#include <iostream>
#include <set> 

class Node {
private:
	std::string name; 
	std::set<Node*> neighbours;
	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);
public:
	Node(const std::string& aname) : name(aname) {}
	const std::string& getName() const { return name; }
	node_iterator nb_begin() const {
		return neighbours.begin();
	}
	node_iterator nb_end() const { return neighbours.end(); }
	friend class Graph;
};

