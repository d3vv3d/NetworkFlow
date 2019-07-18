#include "stdafx.h"
#include "Graph.h"

Graph::Graph() {}


Graph::~Graph()
{
	m_edges.clear();
}

void Graph::addEdge(Edge edge) {
	m_edges.push_back(edge);
}

void Graph::addEdge(char head, char tail, int capacity) {
	m_edges.push_back(Edge(head, tail, capacity));
}



// Willnot always find a path to t if there is one, needs a dead end case, also this doe not preventy cycles, whoops
// Do not add edges to result unitl 't' has been reached, also
// bool Graph::depthFirstSearch(char root, std::vector
// Broken first attempt
/*
std::vector<Edge> Graph::depthFirstSearch(char root) {
	std::vector<Edge> result;
	
	for (int i = 0; i < m_edges.size(); i++) {
		if (m_edges[i].m_head == root && m_edges[i].m_flow < m_edges[i].m_capacity) {
			result.push_back(m_edges[i]);
			std::vector<Edge> tmp = depthFirstSearch(m_edges[i].m_tail);
			result.insert(result.end(), tmp.begin(), tmp.end());
		}
	}

	if (result.back().m_tail == 't') {
		return result;
	}

	for (int i = 0; i < m_edges.size(); i++) {
		if (m_edges[i].m_tail == root && m_edges[i].m_flow > 0) {
			result.push_back(m_edges[i]);
			std::vector<Edge> tmp = depthFirstSearch(m_edges[i].m_head);
			result.insert(result.end(), tmp.begin(), tmp.end());
		}
	}

	return result;

}
*/

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
	std::vector<Edge>::const_iterator iter;

	for (iter = graph.m_edges.begin(); iter != graph.m_edges.end(); iter++) {
		std::cout << *iter << std::endl;
	}

	return os;
}

