#pragma once

#include <iostream>

class Edge
{
public:
	Edge(char head, char tail, unsigned int capacity);
	~Edge();

	char m_head;
	char m_tail;
	unsigned int m_capacity;
	unsigned int m_flow = 0;

	friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};


