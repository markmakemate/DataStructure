#ifndef PREPERATION_H
#define PREPERATION_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
template<class Elemtype>
struct AdjacentListNode {
	Elemtype data;
	int Vertex;
	string sign;
	AdjacentListNode<Elemtype>* next;
	AdjacentListNode(Elemtype x, int v) :data(x), Vertex(v), sign("UNVISITED"), next(NULL) {}
};   //declaration of Linklist node

template<class Elemtype>
class Heap:LinkList<Elemtype> {
	typedef AdjacentListNode<Elemtype>* List;
private:
	List Parent(List S,List A);
	List LeftChild(List S,List A);
	List RightChild(List S,List A);
public:
	vector<List> BuildHeap(vector<List> A);
	void* FindMin(vector<List> A);
};

template<class Elemtype>
AdjacentListNode<Elemtype>* Heap<Elemtype>::Parent(AdjacentListNode<Elemtype>* S,AdjacentListNode<Elemtype>* A) {
	typedef AdjacentListNode<Elemtype>* Node;
	int P = FindPosition(S, A);
	Node candidate = FindInPosition(S, floor((P-1)/2));
	return candidate;
}

template<class Elemtype>
AdjacentListNode<Elemtype>* Heap<Elemtype>::LeftChild(AdjacentListNode<Elemtype>* S, AdjacentListNode<Elemtype>* A) {
	typedef AdjacentListNode<Elemtype>* Node;
	int P = FindPosition(S, A);
	Node candidate = FindInPosition(S, 2*P+1);
	return candidate;
}
template<class Elemtype>
AdjacentListNode<Elemtype>* Heap<Elemtype>::RightChild(AdjacentListNode<Elemtype>* S, AdjacentListNode<Elemtype>* A) {
	typedef AdjacentListNode<Elemtype>* Node;
	int P = FindPosition(S, A);
	Node candidate = FindInPosition(S, 2 * P + 2);
	return candidate;
}
template<class Elemtype>
vector<AdjacentListNode<Elemtype>*> BuildHeap(vector<AdjacentListNode<Elemtype>*> A) {

}

template<class Elemtype>
class LinkList {
	typedef AdjacentListNode<Elemtype>* Node;
	typedef AdjacentListNode<Elemtype> ListNode;
	typedef Elemtype* Row;
private:
	Node head;
public:
	void InsertListNode(Node head, Node node) {
		Node p;
		p = head;
		while (p != NULL) {
			p = p->next;
		}
		p = node;
	}   //Insert a node

	Node BuildLinkList(Elemtype* A) {
		Node p, q;
		p = new ListNode(0, (int)*A);
		q = new ListNode(*(A + 2), (int)*(A + 1));
		p->next = q;
		return p;
	}   //Build a list

	int Num_of_List(Node r) {
		Node p = r;
		int count = 1;
		while (p->next != NULL) {
			count++;
		}
		return count;
	}   //Number of list nodes

	bool IsExist(Node A, int u) {
		Node p = A;
		bool sign = false;
		while (p != NULL) {
			if (p->Vertex != u) { p = p->next; }
			else { sign = true; break; }
		}
		return sign;
	}
	bool IsExist(vector<Row> A, int u);
	Node Find(vector<Node> A, int v);
	Elemtype* Transform(ListNode* A);
	int FindPosition(ListNode* S, ListNode* A);
	ListNode* FindInPosition(ListNode* S, int P);
};   //declaration of Linklist class

template<class Elemtype>
Elemtype* LinkList<Elemtype>::Transform(AdjacentListNode<Elemtype>* A) {

}

#endif