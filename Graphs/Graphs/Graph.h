/*==========================================================
Code: Graphs
Auth: Geeks for Geeks
	  https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
	  https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
Name: Modifications by Kira Corbett
Date: 5/24/18
Desc: class definitions for a directed C++ graph using an
	  adjacency matrix representation.
===========================================================*/

#pragma once
#include<list>

using namespace std;

class Graph
{
public:
	Graph(int vertices);	// constructor

	~Graph();	// destructor

	void addEdge(int v, int w); // function to add an edge to graph

	void DFS(int v); // DFS traversal of vertices reachable from v

	void BFS(int s); // prints BFS traversal from a given source s

private:
	int vertices; // number of vertices
	int** adjMatrix; // adjacency matrix

	void DFSUtil(int v, bool visited[]); // recursive function helper for DFS
};