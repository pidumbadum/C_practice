#include "Nodes.h"
void Node::addNeighbour(Node* neighbour) {
	neighbours.insert(neighbour);
}
void Node::removeNeighbour(Node* neighbour) {
	neighbours.erase(neighbour);
}
set<string> Node::get_nb_name() const {
	set<string> names;
	for (node_iterator it = nb_begin(); it != nb_end(); it++) {
		names.insert((*it)->getName());
	}
	return names;
}