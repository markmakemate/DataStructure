#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include "../Data_Processors/GraphLoader.h"
#include "../Data_Processors/AdjList.h"
#include "../Data_Processors/AdjMatrix.h"
#include<cstdlib>
#include<map>
#include<queue>
#define INF 1.7976931348623e+308
using namespace std;
//Graph class
class Graph{
	typedef GraphLoader graph;
private:
    AdjList G_L;   //Adjacent List
	graph Set;  
	AdjMatrix G_M;   //Adjacent Matrix
public:
    Graph()
    Graph(graph& G,int selection=0);   //Constructor
	void load(graph& G,int selection=0);
	int FindFirstVertex(int node);  //Find the first adjacent vertex
	int FindNextVertex(int node,int adj);   //Find the next adjacent vertex
	bool IsExistAdj(int node);    //Discriminate if the node exist adjacent vertex
	double operator()(int start,int end){
		return G_L(start,end);
	}
	int Vertex();
	int InOrder(int u);
	int OutOrder(int u);
	void setTag(int start,int end);
	bool getTag(int start,int end);
	virtual queue<int> Dijkstra(int u);   //Dijkstra Shortest-paths Algorithm
	virtual Graph Prim();    //Prim's Minimum-spanning-tree Algorithm
	virtual Graph Kruskal(); //Kruskal's Minimum-spanning-tree Algorithm
	virtual queue<int> TopologicalSort();  //Topological Sort 
	virtual queue<int> Bellman_Ford(int u); //Bellman-Ford Algorithm
	virtual queue<int> BFT(); //Breadth-First Traversal
	virtual queue<int> DFT();  //Depth-First Traversal
	virtual int* EulerCycuit();   //Find Euler path
	virtual queue<int> CriticalPath();  //Find a critical path
	virtual queue<int> MaxFlow();  //Find the max flow
};
//selection=0: directed graph
//selection=1: undirected graph
//Initial value: selection=0
//Load a GraphLoader object for parameter
Graph::Graph(){
	G_L=NULL;
	G_M=NULL;
}
Graph::Graph(GraphLoader& g,int selection){
	if(selection==0){
		G_L.build(g);
	}
	else{
		G_M.build(g);
	}
}

//selection=0: directed graph
//selection=1: undirected graph
void load(GraphLoader& g,int selection){
    if(selection==0){
		G_L.build(g);
	}
	else{
		G_M.build(g);
	}
}
int Graph::FindFirstVertex(int node){
	List<double> list=G_L[node];
	return ((list.head())->next)->vertex;
}
int Graph::FindNextVertex(int node,int adj){
	Node<double>* p=(G_L[node]).head();
	while(p!=NULL){
		if(p->vertex==adj){
			p=p->next;
			break;
		}
		else{
			p=p->next;
		}
	}
	return p->vertex;
}
int Graph::InOrder(int u){
	map<int,map<int,double> >::iterator it;
	List<double> candidate;
	Node<double>* N;
	int count=0;
	for(int it=G_L.begin();it!=G_L.end();++it){
		candidate=it->second;
		N=(candidate.head())->next;
		while(N!=NULL){
			if(N->vertex!=u){
				N=N->next;
			}
			else{
				count++;
				break;
			}
		}
	}
	return count;
}
int Graph::OutOrder(int u){
	List<double> candidate=G_L[u];
	Node<double>* N=(candidate.head())->next;
	int count=0;
	while(N!=NULL){
		count++;
	}
	return count;
}
void Graph::setTag(int start,int end){
	List<double> candidate=G_L[start];
	Node<double> p=(candidate.head())->next;
	while(p!=NULL){
		if(p->vertex!=end){
			p=p->next;
		}
		else{
			p->tag=true;
			break;
		}
	}
}
bool Graph::getTag(int start,int end){
	List<double> candidate=G_L[start];
	Node<double> p=(candidate.head())->next;
	while(p!=NULL){
		if(p->vertex!=end){
			p=p->next;
		}
		else{
			break;
		}
	}
	return p->tag;
}
#include "GraphAlgorithms.h"
#endif
