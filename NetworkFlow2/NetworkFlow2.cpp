// NetworkFlow2.cpp : Defines the entry pounsigned int for the console application.
//

#include "stdafx.h"

#include "Graph.h"

void aug(Graph& graph, std::vector<Edge*> path, unsigned int bottleneck);

unsigned int main()
{
	Graph graph = Graph();
	
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
	

	/*
	graph.addEdge('s', 'u', 20);
	graph.addEdge('s', 'v', 10);
	graph.addEdge('u', 'v', 30);
	graph.addEdge('u', 't', 10);
	graph.addEdge('v', 't', 20);
	*/

	//graph.addEdge('s', 't', 1);

	std::cout << graph;

	std::cout << "\n\nMax Flow & Min Cut: " << graph.maxFlow() << std::endl;

	std::cout << "\nResult:\n";
	std::cout << graph;

	system("PAUSE");

    return 0;
}
