#include "Graph.h"
using namespace std;

void Graph::addNode(Node* node) {
	nodes.insert(node);
}
void Graph::removeNode(Node* node) {
	nodes.erase(node); //Удаление из списка
	// Remove also from all neighbours list
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
		(*it)->removeNeighbour(node); //цикл проходится по всем узлам и удалает из соседей указатель на удаленный объект...
	}
}
void Graph::addEdge(Node* begin, Node* end) {
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	begin->addNeighbour(end);
	end->addNeighbour(begin);
}
void Graph::removeEdge(Node* begin, Node* end) {
	//chek the nodes exist
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	//chek they are neighbours and delete
	if (begin->neighbours.find(end) == begin->neighbours.end()) return;
	begin->neighbours.erase(end);
	end->neighbours.erase(begin);
}