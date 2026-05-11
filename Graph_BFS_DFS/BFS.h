#pragma once
#include "Graph.h"
#include <iostream>
#include <set>

class BFS {
	const Graph& graph;
public:
	BFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end); //Проверка наличия пути из одной точки в другую 
};

