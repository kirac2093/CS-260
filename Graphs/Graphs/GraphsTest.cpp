/*==========================================================
Code: Graphs
Name: Kira Corbett
Date: 5/24/18
Desc: store a graph using an adjacency matrix instead
	  of an adjacency list. Traversal routines demonstrated
	  using depth-first and breadth-first traversal. 
===========================================================*/

#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
	std::cout << "CS-260 Assignment 7 - Graphs\n";
	std::cout << "Author: Kira Corbett\n\n";

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	// correct print: 2 0 3 1
	std::cout << "Breadth First Traversal (starting from vertex 2):\n";
	g.BFS(2);

	// correct print: 2 0 1 3
	std::cout << "\n\nDepth First Traversal (starting from vertex 2):\n";
	g.DFS(2);

	cin.get();
	cin.ignore();

	return 1;
}
