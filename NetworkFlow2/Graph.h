#pragma once

#include <vector>
#include <iterator>
#include <set>

#include "Edge.h"

class Graph
{
public:
	Graph();
	~Graph();

	void addEdge(Edge edge);
	void addEdge(char head, char tail, int capacity);

	//std::vector<Edge> depthFirstSearch(char root);
	bool depthFirstSearch(char root, std::vector<Edge>& path, int& bottleneck, std::set<char> usedVertices);

	std::vector<Edge> m_edges;

	friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};



