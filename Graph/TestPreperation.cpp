#include<iostream>
#include<cstring>
#include<cstdlib>
#include "Preperation.h"
#include<vector>
using namespace std;
void Show(int* A,int SIZE);
int main(){
	typedef AdjacentListNode<int>* Node;
	typedef AdjacentListNode<int> ListNode;
	Node p = new ListNode(10, 0);
	vector<Node> V;
	int A[3]={1,2,3};
	int B[3] = { 2,3,5 };
	int* T=new int[3];
	int* M = new int[3];
	LinkList<int> L;
	T=A;
	M = B;
	Node l=L.BuildLinkList(T);
	Node q = L.BuildLinkList(M);
	V.push_back(l);
	V.push_back(q);
	V.push_back(L.InsertListNode(q,p));
	p->sign = "VISITED";
	string g = p->sign;
	cout << g<<endl;
	cout<<"Number of list: "<<L.Num_of_List(l)<<endl;
	cout << "Length: " << V.size();
	cout << "Number of list q: " << L.Num_of_List(V.at(1)) << endl;
	cout<<"After initial: "<<L.Initial(p)->sign<<endl;
	cout<<"After transform: ";
	Show(L.Transform(V.at(2),10),10);
	return 0;
}
void Show(int* A,int SIZE){
	cout<<*A;
	for(int i=1;i<SIZE;i++){
		cout<<", "<<*(A+i);
	}
	cout<<endl;
}
