#include "BFS.h"
#include <queue>

bool BFS::connected(Node* begin, Node* end) {
	queue<Node*> nodes; //первый зашел первый вышел
	nodes.push(begin);
	set<Node*> visited;
	while (!nodes.empty()) {
		Node* next = nodes.front(); //первый элемент в контейнере 
		nodes.pop();
		if (end == next) return true;
		visited.insert(next);
		//в этом цикле пробегаемся по соседям next и если он ранее не проверялся на связь добавляется в очередь для проверки
		for (Node::nodes_iterator it = next->nb_begin(); it != next->nb_end(); it++) {
			if (visited.find(it->first) == visited.end()) //до того, как добавила веса тут просто искался Node*, щас 
				nodes.push(it->first);
		}
	}
	return false;
}