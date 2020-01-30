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

void Graph::addEdge(char head, char tail, unsigned int capacity) {
	m_edges.push_back(Edge(head, tail, capacity));
}

bool Graph::depthFirstSearch(char root, std::vector<Edge*>& path, unsigned int& bottleneck, std::set<char> usedVertices) {
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
	for (unsigned int i = 0; i < m_edges.size(); i++) {
		// Is there a better way to do the Forward and backward edge code?
		//   I suppose that I could turn the code within the first if statements unsigned into a separate function
		// Forward edge
		if (m_edges[i].m_head == root && m_edges[i].m_flow < m_edges[i].m_capacity && usedVertices.count(m_edges[i].m_tail) == 0) {
			// There exists a path to t using the current edge 
			if (depthFirstSearch(m_edges[i].m_tail, path, bottleneck, usedVertices)) {
				// Add the current edge to the path
				path.insert(path.begin(), &m_edges[i]);

				// Check if the bottleneck should be updated & update if necessary
				unsigned int tmp = m_edges[i].m_capacity - m_edges[i].m_flow;
				if (bottleneck > tmp) {
					bottleneck = tmp;
				}

				return true;
			}
		}

		// The suspect
		// Backward edge
		// Cannot backflow to s
		if (m_edges[i].m_tail == root && m_edges[i].m_flow > 0 && usedVertices.count(m_edges[i].m_head) == 0 && m_edges[i].m_head != 's') {
			// There exists a path to t using the current edge 
			if (depthFirstSearch(m_edges[i].m_head, path, bottleneck, usedVertices)) {
				// Add the current edge to the path
				path.insert(path.begin(), &m_edges[i]);

				// Check if the bottleneck should be updated & update if necessary
				unsigned int tmp = m_edges[i].m_flow;
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

void aug(Graph& graph, std::vector<Edge*> path, unsigned int bottleneck) {

	bool lastEdgeWasBackwards = false;

	// Change the flows
	path[0]->m_flow += bottleneck;
	for (unsigned int i = 1; i < path.size(); i++) {
		//std::cout << "path[i - 1].m_tail: " << path[i - 1]->m_tail << std::endl;
		//std::cout << "path[i].m_head: " << path[i]->m_head << std::endl;

		// Check if the edge is a forward edge
		// Need both side of the or, the left side identfies the general case of a forward edge and the right case identifies a forward edge that comes after a backward one
		if ((path[i - 1]->m_tail == path[i]->m_head && !lastEdgeWasBackwards) || (path[i - 1]->m_head == path[i]->m_head && lastEdgeWasBackwards)) {
			path[i]->m_flow += bottleneck;
			lastEdgeWasBackwards = false;
		}
		else {
			path[i]->m_flow -= bottleneck;
			lastEdgeWasBackwards = true;
		}
	}
}

unsigned int Graph::maxFlow() {
	std::vector<Edge*> path;
	unsigned int b = UINT_MAX;
	std::set<char> usedVertices;
	while (depthFirstSearch('s', path, b, usedVertices)) {
		aug(*this, path, b);

		/*std::cout << "\npath:\n";
		for (int i = 0; i < path.size(); i++) {
		std::cout << *path[i] << std::endl;
		}*/

		// Reset values
		path.clear();
		b = UINT_MAX;

		//std::cout << std::endl << graph << std::endl;
	}

	unsigned int minCut = 0;

	for (int i = 0; i < m_edges.size(); i++) {
		if (m_edges[i].m_tail == 't') {
			minCut += m_edges[i].m_flow;
		}
	}

	return minCut;
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
	std::vector<Edge>::const_iterator iter;

	for (iter = graph.m_edges.begin(); iter != graph.m_edges.end(); iter++) {
		std::cout << *iter << std::endl;
	}

	return os;
}

