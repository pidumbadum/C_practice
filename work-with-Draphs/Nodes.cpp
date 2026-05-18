#include "Nodes.h"
void Node::addNeighbour(Node* neighbour, int weight) {
	neighbours.insert({ neighbour , weight});
}
void Node::removeNeighbour(Node* neighbour) {
	neighbours.erase(neighbour);
}
set<string> Node::get_nb_name() const {
	set<string> names;
	for (node_iterator it = nb_begin(); it != nb_end(); it++) {
		string str_weight = to_string((it)->second);
		names.insert((it)->first->getName() + '('+ str_weight+')');
	}
	return names;
}