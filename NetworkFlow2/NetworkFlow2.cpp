// NetworkFlow2.cpp : Defines the entry pounsigned int for the console application.
//

#include "stdafx.h"

#include "Graph.h"

void aug(Graph& graph, std::vector<Edge> path, unsigned int bottleneck);

unsigned int main()
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
	

	//graph.addEdge('s', 't', 1);

	std::cout << graph;

	/*for (std::vector<Edge> path = graph.depthFirstSearch('s'); path.back().m_tail == 't'; path = graph.depthFirstSearch('s')) {
		//aug(graph, path);
	}*/

	std::vector<Edge> path;
	unsigned int b = UINT_MAX;
	std::set<char> usedVertices;
	while (graph.depthFirstSearch('s', path, b, usedVertices)) {
		aug(graph, path, b);

		// Reset values
		path.clear();
		b = UINT_MAX;

		std::cout << std::endl << graph << std::endl;
	}
	/*if (graph.depthFirstSearch('s', path, b, usedVertices)) {

		aug(graph, path, b);
		std::cout << b << std::endl;

		std::cout << graph;
	}*/

	std::cout << graph;

	system("PAUSE");

    return 0;
}

void aug(Graph& graph, std::vector<Edge> path, unsigned int bottleneck) {
	// Change the flows
	graph.m_edges[0].m_flow += bottleneck;
	for (unsigned int i = 1; i < path.size(); i++) {
		// Check if the edge is a forward edge
		if (graph.m_edges[i - 1].m_tail == graph.m_edges[i].m_head) {
			graph.m_edges[i].m_flow += bottleneck;
		}
		else {
			graph.m_edges[i].m_flow -= bottleneck;
		}
	}
}

// Original aug()
/*
void aug(Graph& graph, std::vector<Edge> path) {

	// Determine the bottleneck
	unsigned int b = path[0].m_capacity - path[0].m_flow;

	for (unsigned int i = 1; i < path.size(); i++) {
		// Check if the edge is a forward edge
		if (path[i - 1].m_tail == path[i].m_head) {
			unsigned int tmp = path[i].m_capacity - path[i].m_flow;
			if (tmp < b) {
				b = tmp;
			}
		}
		// Must be a back edge
		else {
			unsigned int tmp = path[i].m_flow;
			if (tmp < b) {
				b = tmp;
			}
		}
	}

	// Change the flows
	path[0].m_flow += b;
	for (unsigned int i = 1; i < path.size(); i++) {
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