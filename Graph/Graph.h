#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include "DataProcessor.h"
#include<cstdlib>
#include<map>
#include<list>             
#include<queue>
using namespace std;
//Graph class
namespace Graph{
class Graph:public GraphLoader{
	typedef map<int,list<int> > AdjList;
	typedef GraphLoader graph;
	typedef map<int,vector<int> > AdjMatrix;
public:
    Graph(graph& G,int selection=0);
	AdjList G_A;
	graph Set;
	AdjMatrix G_M;
	int FindFirstVertex(int node);  //Find the first adjacent vertex
	int FindNextVertex(int node,int adj);   //Find the next adjacent vertex
	bool IsExistAdj(int node);    //Discriminate if the node exist adjacent vertex
	double operator()(int start,int end){
		return Set(start,end);    //Get the weight between vertex start and end
	}
	int Vertex();
	int InOrder(int u);
	int OutOrder(int u);
	virtual queue<int> Dijkstra(Graph &g,int u);   //Dijkstra Shortest-paths Algorithm
	virtual Graph Prim(Graph &g);    //Prim's Minimum-spanning-tree Algorithm
	virtual Graph Kruskal(Graph &g); //Kruskal's Minimum-spanning-tree Algorithm
	virtual queue<int> TopologicalSort(Graph &g);  //Topological Sort 
	virtual queue<int> Bellman_Ford(Graph &g,int u); //Bellman-Ford Algorithm
	virtual queue<int> BFT(Graph &g); //Breadth-First Traversal
	virtual queue<int> DFT(Graph &g);  //Depth-First Traversal
	virtual int* EulerCycuit(Graph &g);   //Find Euler path
	virtual queue<int> CriticalPath(Graph &g);  //Find a critical path
};
int Graph::FindFirstVertex(int node){
	list<int>::iterator it;
	
}
}
#endif
