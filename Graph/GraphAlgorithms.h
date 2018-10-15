#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H
#include<iostream>
#include<cstdlib>
#include<map>
#include<queue>
#include "../Data_Processors/GraphLoader.h"
#include "../Data_Processors/AdjList.h"
#include "../Data_Processors/AdjMatrix.h"
#include "Graph.h"
//A class of often-used graph algorithms
using namespace std;
class GraphAlgorithms:public Graph{
	typedef double Distance;
private:
	double* distances;
	Graph g;
public:
	GraphAlgorithms(Graph& graph);  //Constructor: Load a Graph object as parameter(must)
	map<int,Distance> Dijkstra(int u);   //Dijkstra Shortest-paths Algorithm
	Graph Prim();    //Prim's Minimum-spanning-tree Algorithm
	Graph Kruskal(); //Kruskal's Minimum-spanning-tree Algorithm
	queue<int> TopologicalSort();  //Topological Sort 
	queue<int> Bellman_Ford(int u); //Bellman-Ford Algorithm
	queue<int> BFT(); //Breadth-First Traversal
	queue<int> DFT();  //Depth-First Traversal
	int* EulerCycuit();   //Find Euler path
	queue<int> CriticalPath();  //Find a critical path
	queue<int> MaxFlow();
};
GraphAlgorithms::GraphAlgorithms(Graph& graph) {
	g=graph;
	distances = new double[g.Vertex()];
	for (int i = 0; i < g.Vertex(); i++) {
		if (i != u) { *(distance + i) = -1; }
		else { *(distance + i) = 0; }
	}
}
map<int,double> GraphAlgorithms::Dijkstra(int u) {
	map<int, double> result;
	for (int i = g.FindFirstVertex(u); g.FindNextVertex(u,i)!=-1; i = g.FindNextVertex(u, i)) {
		if (i != -1) {
			if (*(distances + i) >*(distances+u)+ g(u, i)&&*(distances+i)!=-1) {
				*(distances + i) = *(distances + u) + g(u, i);
			}
			else if(*(distances+i)==-1){
				*(distances+i)=g(u,i);
			}
			return Dijkstra(i);
		}
	}
	for (int j = 0; j < g.Vertex(); j++) {
		result.emplace(j, *(distances + j));
	}
	return result;
}
queue<int> GraphAlgorithms::TopologicalSort() {
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
queue<int> GraphAlgorithms::Bellman_Ford(int u){

	
}
queue<int> GraphAlgorithms::CriticalPath(){

}
Graph GraphAlgorithms::Prim(){
	
}
#endif
