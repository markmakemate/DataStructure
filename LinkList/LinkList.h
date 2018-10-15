#ifndef LINKLIST_H
#define LINKLIST_H
#include<cstdlib>
#include<iostream>
#include<string>
#include<iterator>
#include "Processor.h"
using namespace std;
template<class elementype>
struct SingleListNode{
	elementype data;
	SingleListNode* next;
	SingleListNode(elementype x):data(x),next(NULL){}
};
template<class elementype>
class SingleLinkList{
	typedef elementype* data;
	typedef SingleListNode<elementype>* node;
	public:
		node head;
		int MAXSIZE;
		int SIGN;
		data Keys;
		virtual void push(elementype Key);
		virtual void pop();
		virtual void erase(int position);
		virtual void insert(elementype Key,int position);
		SingleLinkList();
		virtual void build(data Input);
		virtual bool IsEmpty();
		virtual node begin();
		virtual node end();
		virtual int size();
		virtual node operator+(node start,int steps);
};

template<class type_name>
struct DoubleListNode{
	type_name data;
	DoubleListNode<type_name>* next;
	DoubleListNode<type_name>* previous;
	DoubleListNode(type_name x):data(x),next(NULL),previous(NULL){}
};
template<class type_name>
class DoubleLinkList{
	typedef DoubleListNode<type_name>* node;
public:
    DoubleLinkList();
	node head;
	int MAXSIZE;
	virtual void push(type_name Key);


};
#endif


