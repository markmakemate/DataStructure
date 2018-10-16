#include<cstdlib>
#include<iostream>
using namespace std;
template<class type_name>
struct DoubleListNode{
	type_name data;
	DoubleListNode<type_name>* next;
	DoubleListNode<type_name>* previous;
	DoubleListNode(type_name x):data(x),next(NULL),previous(NULL){}
	DoubleListNode* operator + (int position){
		DoubleListNode* p=next;
		for(int i=1;i<position;i++){
			p=p->next;
		}
		return p;
	}
	DoubleListNode* operator - (int position){
		DoubleListNode* p=previous;
		for(int i=1;i<position;i++){
			p=p->previous;
		}
		return p;
	}
	DoubleListNode* operator ++(){
		return next;
	}
	DoubleListNode* operator --(){
		return previous;
	}
};

