#include "BFS.h"
#include <queue>

bool BFS::connected(Node* begin, Node* end) {
	queue<Node*> nodes; 
	nodes.push(begin);
	set<Node*> visited;
	while (!nodes.empty()) {
		Node* next = nodes.front(); 
		nodes.pop();
		if (end == next) return true;
		visited.insert(next);
		for (Graph::node_iterator it = next->nb_begin(); it != next->nb_end(); it++)
			if (visited.find(*it) == visited.end())
				nodes.push(*it);
	}
	return false;
}