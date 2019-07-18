// NetworkFlow2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Graph.h"

void aug(Graph& graph, std::vector<Edge> path, int bottleneck);

int main()
{
	Graph graph = Graph();
	/*
	graph.addEdge('s', 'a', 10);
	graph.addEdge('s', 'b', 3);
	graph.addEdge('s', 'd', 1);
	graph.addEdge('a', 'b', 1);
	graph.addEdge('a', 'c', 2);
	graph.addEdge('a', 't', 5);
	graph.addEdge('b', 'c', 6);
	graph.addEdge('d', 'b', 3);
	graph.addEdge('d', 'c', 3);
	graph.addEdge('d', 't', 10);
	graph.addEdge('c', 't', 5);
	*/

	graph.addEdge('s', 'u', 20);
	graph.addEdge('s', 'v', 10);
	graph.addEdge('u', 'v', 30);
	graph.addEdge('u', 't', 10);
	graph.addEdge('v', 't', 20);

	std::cout << graph;

	/*for (std::vector<Edge> path = graph.depthFirstSearch('s'); path.back().m_tail == 't'; path = graph.depthFirstSearch('s')) {
		//aug(graph, path);
	}*/

	std::vector<Edge> path;
	int b = INT_MAX;
	if (graph.depthFirstSearch('s', path, b)) {

		aug(graph, path, b);

		std::cout << graph;
	}

	std::cout << "\n\npath:\n";
	for (int i = 0; i < path.size(); i++) {
		std::cout << path[i] << std::endl;
	}
	

	system("PAUSE");

    return 0;
}

void aug(Graph& graph, std::vector<Edge> path, int bottleneck) {
	// Change the flows
	path[0].m_flow += bottleneck;
	for (int i = 1; i < path.size(); i++) {
		// Check if the edge is a forward edge
		if (path[i - 1].m_tail == path[i].m_head) {
			path[i].m_flow += bottleneck;
		}
		else {
			path[i].m_flow -= bottleneck;
		}
	}
}

// Original aug()
/*
void aug(Graph& graph, std::vector<Edge> path) {

	// Determine the bottleneck
	int b = path[0].m_capacity - path[0].m_flow;

	for (int i = 1; i < path.size(); i++) {
		// Check if the edge is a forward edge
		if (path[i - 1].m_tail == path[i].m_head) {
			int tmp = path[i].m_capacity - path[i].m_flow;
			if (tmp < b) {
				b = tmp;
			}
		}
		// Must be a back edge
		else {
			int tmp = path[i].m_flow;
			if (tmp < b) {
				b = tmp;
			}
		}
	}

	// Change the flows
	path[0].m_flow += b;
	for (int i = 1; i < path.size(); i++) {
		// Check if the edge is a forward edge
		if (path[i - 1].m_tail == path[i].m_head) {
			path[i].m_flow += b;
		}
		else {
			path[i].m_flow -= b;
		}
	}
}
*/