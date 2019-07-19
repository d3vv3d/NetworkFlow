#pragma once

#include <vector>
#include <iterator>
#include <set>
#include <memory>

#include "Edge.h"

class Graph
{
public:
	Graph();
	~Graph();

	void addEdge(Edge edge);
	void addEdge(char head, char tail, unsigned int capacity);

	//std::vector<Edge> depthFirstSearch(char root);
	bool depthFirstSearch(char root, std::vector<Edge*>& path, unsigned int& bottleneck, std::set<char> usedVertices);
	unsigned int maxFlow();

	std::vector<Edge> m_edges;

	friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};



