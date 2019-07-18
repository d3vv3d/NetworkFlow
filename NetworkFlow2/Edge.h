#pragma once

#include <iostream>

class Edge
{
public:
	Edge(char head, char tail, int capacity);
	~Edge();

	char m_head;
	char m_tail;
	int m_capacity;
	int m_flow = 0;

	friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};


