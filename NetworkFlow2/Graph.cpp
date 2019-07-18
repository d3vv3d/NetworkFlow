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

bool Graph::depthFirstSearch(char root, std::vector<Edge>& path, int& bottleneck, std::set<char> usedVertices) {
	// Update usedVertices to prevent cycling
	usedVertices.emplace(root);
	/*for (std::set<char>::iterator iter = usedVertices.begin(); iter != usedVertices.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "root: " << root << std::endl;
	*/

	// Base case
	if (root == 't') {
		//std::cout << "WHA?" << std::endl;
		return true;
	}
	
	// Imperfect, edges can only connect two vertices not all of them
	for (int i = 0; i < m_edges.size(); i++) {
		// Is there a better way to do the Forward and backward edge code?
		//   I suppose that I could turn the code within the first if statements into a separate function
		// Forward edge
		if (m_edges[i].m_head == root && m_edges[i].m_flow < m_edges[i].m_capacity && usedVertices.count(m_edges[i].m_tail) == 0) {
			// There exists a path to t using the current edge 
			if (depthFirstSearch(m_edges[i].m_tail, path, bottleneck, usedVertices)) {
				// Add the current edge to the path
				path.push_back(m_edges[i]);

				// Check if the bottleneck should be updated & update if necessary
				int tmp = m_edges[i].m_capacity - m_edges[i].m_flow;
				if (bottleneck > tmp) {
					bottleneck = tmp;
				}

				return true;
			}
		}
		// Backward edge
		if (m_edges[i].m_tail == root && m_edges[i].m_flow > 0 && usedVertices.count(m_edges[i].m_head) == 0) {
			// There exists a path to t using the current edge 
			if (depthFirstSearch(m_edges[i].m_head, path, bottleneck, usedVertices)) {
				// Add the current edge to the path
				path.push_back(m_edges[i]);

				// Check if the bottleneck should be updated & update if necessary
				int tmp = m_edges[i].m_flow;
				if (bottleneck > tmp) {
					bottleneck = tmp;
				}

				return true;
			}
		}

	}

	// Signals the absence of a path
	return false;
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

