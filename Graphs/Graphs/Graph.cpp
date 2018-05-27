/*==========================================================
Code: Graphs
Auth: Geeks for Geeks 
	  https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
	  https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
Name: Modifications by Kira Corbett
Date: 5/24/18
Desc: class implementation for C++ graphs to print DFS 
	  (Depth First Search) and BFS (Breadth First Search)
	  traversal routines from a given vertex in graph.
===========================================================*/

#include<iostream>
#include <queue>
#include "Graph.h"

using namespace std;

Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adjMatrix = new int*[vertices];

	// allocate memory and initialize array to 0
	for (int i = 0; i < vertices; i++)
	{
		adjMatrix[i] = new int[vertices];
		for (int j = 0; j < vertices; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph()
{
	for (int i = 0; i < vertices; i++)
	{
		delete[] adjMatrix;
	}
	delete[] adjMatrix;
}

/*=====================================
Name: addEdge
Desc: adds adjacent matrix setup
Args: v (int), w (int)
Retn: none
=====================================*/
void Graph::addEdge(int v, int w)
{
	adjMatrix[v][w] = 1; // add adjacent matrix
}

/*=====================================
Name: BFS
Desc: Breadth-first traversal routine
Args: s (int)
Retn: none
=====================================*/
void Graph::BFS(int s)
{
	// mark all the vertices as not visited
	bool *visited = new bool[vertices];

	for (int i = 0; i < vertices; i++)
	{
		visited[i] = false;
	}

	// create a queue for BFS
	queue<int> queue;

	// mark current node as visited & push onto the queue
	visited[s] = true;
	queue.push(s);

	while (!queue.empty())
	{
		// dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop();

		// traverse to find all adjacent vertices of dequeued vertex s.
		// If adjacent not visisted, then visit it and enqueue it.
		for (int i = 0; i < vertices; ++i)
		{
			// if we are on a vertex
			if (adjMatrix[s][i] == 0)
			{
				continue;
			}
			// if we have not visited node
			else if (!visited[i])
			{
				visited[i] = true;
				queue.push(i);
			}
			else
			{
				continue;
			}
		}
	}

	delete[] visited;
}

/*=====================================
Name: DFS
Desc: Depth-first traversal of matrix
	  vertices reachable from v.
Args: v (int), uses recursive DFSUtil()
Retn: none
=====================================*/
void Graph::DFS(int v)
{
	// mark all the vertices as not visited
	bool *visited = new bool[vertices];

	for (int i = 0; i < vertices; i++)
	{
		visited[i] = false;
	}

	// call recursive helper function to print traversal
	DFSUtil(v, visited);

	delete[] visited;
}

/*=====================================
Name: DFSUtil
Desc: recursive helper function for
	  DFS traversal routine
Args: current (int), visited[] (bool)
Retn: none
=====================================*/
void Graph::DFSUtil(int current, bool visited[])
{
	// mark the current placement as visited and print it
	visited[current] = true;
	cout << current << " ";

	for (int i = 0; i < vertices; i++)
	{
		if (!visited[i])
		{
			DFSUtil(i, visited);
		}
		else
		{
			continue;
		}
	}
}