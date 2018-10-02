#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H
#include<iostream>
#include<cstdlib>
#include "Graph.h"
#include "DataProcessor.h"
#include<queue>
//A class of often-used graph algorithms
using namespace std;
using namespace Graph;
class GraphAlgorithms:public Graph{	
	typedef double Distance;
private:
	double* distances;
public:
	GraphAlgorithms();
	map<int,Distance> Dijkstra(Graph &g,int u);   //Dijkstra Shortest-paths Algorithm
	Graph Prim(Graph &g);    //Prim's Minimum-spanning-tree Algorithm
	Graph Kruskal(Graph &g); //Kruskal's Minimum-spanning-tree Algorithm
	queue<int> TopologicalSort(Graph &g);  //Topological Sort 
	queue<int> Bellman_Ford(Graph &g,int u); //Bellman-Ford Algorithm
	queue<int> BFT(Graph &g); //Breadth-First Traversal
	queue<int> DFT(Graph &g);  //Depth-First Traversal
	int* EulerCycuit(Graph &g);   //Find Euler path
	queue<int> CriticalPath(Graph &g);  //Find a critical path
};
GraphAlgorithms::GraphAlgorithms() {
	distances = new double[g.Vertex()];
	for (int i = 0; i < g.Vertex(); i++) {
		if (i != u) { *(distance + i) = -1; }
		else { *(distance + i) = 0; }
	}
}
map<int,double> GraphAlgorithms::Dijkstra(Graph &g, int u) {
	map<int, double> result;
	for (int i = g.FindFirstVertex(u); g.FindNextVertex(u,i)!=-1; i = g.FindNextVertex(u, i)) {
		if (i != -1) {
			if (*(distances + i) >*(distances+u)+ g(u, i)||*(distances+i)==-1) {
				*(distances + i) = *(distances + u) + g(u, i);
			}
			return Dijkstra(g, i);
		}
	}
	for (int j = 0; j < g.Vertex(); j++) {
		result.emplace(j, *(distances + j));
	}
	return result;
}
queue<int> GraphAlgorithms::TopologicalSort(Graph &g) {
	queue<int> candidate;
	queue<int> result;
	for (int i = 0; i < g.Vertex(); i++) {
		if (g.InOrder(i) == 0) {
			candidate.push(i);
		}
	}
	for (int i = candidate.front(); candidate.size() != 0;i=candidate.front()) {
		for (int j = g.FindFirstVertex(i); g.FindNextVertex(i, j) != -1; j = g.FindNextVertex(i, j)) {
			if (g.InOrder(j) - 1 == 0) {
				candidate.push(j);
			}
		}
		result.push(i);
		candidate.pop();
	}
	return result;
}

#endif
