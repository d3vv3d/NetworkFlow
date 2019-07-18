#include "stdafx.h"
#include "Edge.h"


Edge::Edge(char head, char tail, unsigned int capacity) : m_head(head), m_tail(tail), m_capacity(capacity) {}


Edge::~Edge() {}

std::ostream& operator<<(std::ostream& os, const Edge& edge) {
	std::cout << "( " << edge.m_head << ", " << edge.m_tail << ", " << edge.m_capacity << ", " << edge.m_flow << " )";

	return os;
}
