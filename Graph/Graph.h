#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<vector>
#include "Preperation.h"
#include "../Sort/Sort.h"
#include<cstdlib>
#include<queue>             
using namespace std;
template<class Elemtype>
class Graph<Elemtype>:public LinkList<Elemtype>,public Sort<Elemtype>{
	typedef Elemtype* Row;
	typedef AdjacentListNode<Elemtype>* List;
	typedef vector<Row> graph;
private:
	graph G;
	vector<List> ADJ_LIST;
	int NUM_VERTEX;

public:
	Graph(int SIZE);
	void BuildGraph(Elemtype* A[3]);
	vector<List> BuildAdjList(Elemtype* A[3],int SIZE);
	int* BFT();
	int* DFT();
	Row Dijkstra(int u);   //Dijkstra Shortest-paths Algorithm
	void* Prim();    //Prim's Minimum-spanning-tree Algorithm
	void*  Kruskal(); //Kruskal's Minimum-spanning-tree Algorithm
	int* TopologicalSort();  //Topological Sort 
	void SetTag(int u, int v, string c);   //Set a Tag c on vertex v in path u->v
	int FindFirstVertex(int u);    //Find u's first adjacent vertex
	int FindNextVertex(int u, int v);  //Find u's next adjacent vertex
	int InOrder(int u);    //Calculating u's in-order
	int OutOrder(int u);   //Calculating u's out-order
	string getTag(int u, int v);  // Get v's tag in path u->v      
	Row Bellman_Ford(int u); //Bellman-Ford Algorithm
	Elemtype GetWeight(int u, int v);
	Elemtype* FindMinWeightEdge();
	Elemtype* FindMinWeightEdge(int u);
	friend bool IsExit(vector<int> Set,int u);
};

template<class Elemtype>
Graph<Elemtype>::Graph(int SIZE) {
	NUM_VERTEX = SIZE;
	Graph = new vector(2*NUM_VERTEX,NULL);
	ADJ_LIST = new vector(2*NUM_VERTEX,NULL);
}

template<class Elemtype>
void Graph<Elemtype>::BuildGraph(Elemtype* A[3]) {
	ADJ_LIST = BuildAdjList(A);
	for (int i = 0; i < NUM_VERTEX; i++) {
		G.push_back(Transform(ADJ_LIST.at(i),NUM_VERTEX));
	}
}

template<class Elemtype>
vector<AdjacentListNode<Elemtype>* > Graph<Elemtype>::BuildAdjList(Elemtype* A[3],int SIZE) {
	typedef AdjacentListNode<Elemtype>* List;
	vector<List> result=new vector<List>(NUM_VERTEX,NULL);
	List candidate,mid;
	for (int i = 0; i < SIZE; i++) {
		if (result.at((int)*(A+i)[0])==NULL) {
			result.push_back(BuildLinkList(*(A + i)));
			result.swap(result.end(), (int)*(A+i)[0]);
			result.pop();
		}
		else {
			candidate = new AdjacentListNode<Elemtype>(*(A + i)[2], (int)*(A + i)[1]);
			mid = result.at((int)*(A + i)[0]);
			InsertListNode(mid, candidate);
			result.push_back(mid);
			result.swap(result.end(), (int)*(A + i)[0]);
			result.pop();

		}
	}
	return result;
}

template<class Elemtype>
Elemtype* Graph<Elemtype>::Dijkstra(int u) {
	typedef Elemtype* Row;
	Row result=G.at(u);
	Elemtype weight;
	for (int i = FindFirstVertex(u); i != -1; i = FindNextVertex(u, i)) {
		for(int j=FindFirstVertex(i);j!=-1;j=FindNextVertex(i,j)){
			weight = GetWeight(i, j);
			if (*(result + j) > *(result + i) + weight) {
				*(result + j) = *(result + i) + weight;
			}
		}
	}
	return result;
	
}

template<class Elemtype>
int* Graph<Elemtype>::TopologicalSort() {
	queue<int> candidate;
	int u,count=0;
	int* result=NULL;
	for (int i = 0; i<NUM_VERTEX; i++) {
		if (InOrder(i) == 0) {
			candidate.push(i);
		}
	}
	while (candidate.size() != 0) {
		u = candidate.top();
		*(result + count) = u;
		for (int i = FindFirstVertex(u); i != -1; i = FindNextVertex(u, i)) {
			SetTag(u, i,"VISITED");
			if (InOrder(i)== 0) {
				candidate.push(i);
			}
		}
		candidate.pop();
		count++;
	}
	return result;
}

template<class Elemtype>
void Graph<Elemtype>::SetTag(int u, int v, string c) {
	typedef AdjacentListNode<Elemtype>* List;
	List p = ADJ_LIST.at(u);
	List q= = Find(p, v);
	q->sign = c;
}

template<class Elemtype>
int Graph<Elemtype>::FindFirstVertex(int u) {
	typedef AdjacentListNode<Elemtype>* List;
	List p = ADJ_LIST.at(u);
	return p->next->Vertex;
}

template<class Elemtype>
int Graph<Elemtype>::FindNextVertex(int u, int v) {
	typedef AdjacentListNode<Elemtype>* List;
	List p = ADJ_LIST.at(u);
	List q = p->next;
	while (q != NULL) {
		if (q->Vertex == v) {
			q = q->next;
			break;
		}
		else {
			q = q->next;
		}
	}
	if (q == NULL) {
		return -1;
	}
	else {
		return q ->Vertex;
	}
}

template<class Elemtype>
int Graph<Elemtype>::InOrder(int u) {
	typedef Elemtype* Row;
	typedef AdjacentListNode<Elemtype>* List;
	Row candidate;
	int COUNT=0;
	for (int i = 0; i < NUM_VERTEX; i++) {
		candidate = G.at(i);
		if (*(candidate + u) != -1) {
			COUNT++;
		}
	}
	return COUNT;
}

template<class Elemtype>
int Graph<Elemtype>::OutOrder(int u) {
	typedef AdjacentListNode<Elemtype>* List;
	List p = ADJ_LIST.at(u);
	return Num_of_List(p);
}

template<class Elemtype>
string Graph<Elemtype>::getTag(int u, int v) {
	typedef AdjacentListNode<Elemtype>* List;
	List p = ADJ_LIST.at(u);
	while (p != NULL) {
		p = p->next;
		if (p->Vertex == v) {
			break;
		}
	}
	return p->sign;
}

template<class Elemtype>
void* Graph<Elemtype>::Prim() {
	typedef AdjacentListNode<Elemtype>* List;
	Elemtype* MST[3]=NULL;   //Minimum-Spanning-Tree
	queue<Elemtype*> result;
	vector<int> Set;
	Elemtype* Val = new Elemtype[3];
	Val = FindMinWeightEdge();
	result.push(Val);
	Set.push_back((int)Val[0]);
	Set.push_back((int)Val[1]);
	for (int i = 1; i < NUM_VERTEX; i++) {
		Val=FindMinWeightEdge(Set);
		result.push(Val);
		Set.push_back((int)Val[1]);
	}
	for (int i = 0; i < result.size(); i++) {
		*(MST + i) = result.top();
		result.pop();
	}
	return MST;
}

template<class Elemtype>
Elemtype* Graph<Elemtype>::FindMinWeightEdge() {
	Elemtype* Val=new Elemtype[3];
	int COUNT = 0;
	Elemtype* Candidate;
	Elemtype Min=999999999;
	int Index;
	for (int i = 0; i < NUM_VERTEX; i++) {
		Candidate = QuickSort(G.at(i), 1, G.size());
		while (*(Candidate + COUNT) == -1) {
			COUNT++;
		}
		if (Min > *(Candidate + COUNT)) {
			Min = *(Candidate + COUNT);
			for (int j = 0; j < NUM_VERTEX; j++) {
				if (*(G.at(i) + j) == Min) {
					Index = j;
					break;
				}
			}
			Val[0] = Index; Val[1] = i; Val[2] = Min;
		}
		COUNT = 0;
	}
	return Val;
}

template<class Elemtype>
Elemtype* Graph<Elemtype>::FindMinWeightEdge(vector<int> Set) {
	bool sign = false;
	Elemtype* Val = new Elemtype[3];
	int COUNT = 0;
	Elemtype* Candidate;
	Elemtype Min=99999999;
	int Index;
	List p;
	for (int i = 0; i < NUM_VERTEX&& IsExit(Set,i)!; i++) {
		Candidate = QuickSort(G.at(i), 1, NUM_VERTEX);
		// We don't know what the two vertices are the edge belongs to after quick sort 
		//so that checking if the edge with min value connect one vertex 'Index' in 'Set' and another outside is deemed to be a failure.   
		//A discrimating program should be included. 
		try{
			while (*(Candidate + COUNT) == -1) {
				COUNT++;
			}
			if (Min > *(Candidate + COUNT)) {
				Min = *(Candidate + COUNT);
				for (int j = 0; j < NUM_VERTEX; j++) {
					if (*(G.at(i) + j) == Min) {
						Index = j;
						break;
					}
				}
				Val[0] = Index; Val[1] = i; Val[2] = Min;
			}
			if (IsExit(Set, Index)!) {
				throw sign;
			}
		}   //Throw sign
		catch (sign) {
			if (sign!) {
				for (int k = COUNT+1; k < NUM_VERTEX&&IsExit(Set,Index)!; k++) {
					Min = *(Candidate + k);
					for (int j = 0; j < NUM_VERTEX; j++) {
						if (*(G.at(i) + j) == Min) {
							Index = j;
							break;
						}
					}
				
			    }
				Val[0] = Index; Val[1] = i; Val[2] = Min;
			}    // Discriminate whether Index is in Set
		}
			
		COUNT = 0;
	}
	return Val;
}

template<class Elemtype>
void* Graph<Elemtype>::Kruskal() {
	Elemtype* MST[3];  //Minimum-Spanning-Tree
	
}

template<class Elemtype>
Elemtype Graph<Elemtype>::GetWeight(int u, int v) {
	typedef AdjacentListNode<Elemtype>* List;
	List p = ADJ_LIST.at(u);
	Elemtype weight;
	while (p != NULL) {
		if (p->Vertex == v) {
			weight = p->data;
			break;
		}
		else {
			p = p->next;
		}
	}
	return weight;
}
bool IsExit(vector<int> Set, int u) {
	bool sign = false;
	for (int i = 0; i < Set.size(); i++) {
		if (u == Set.at(i)) {
			sign = true;
			break;
		}
	}
	return sign;
}
#endif