#include<cstdlib>
#include<iostream>
#include<string>
#include<iterator>
#include "ListNode.h"
#include "LinkList.h"
using namespace std;
template<class elementype>
class Single:public LinkList<elementype>{
	typedef elementype* data;
	typedef SingleListNode<elementype>* node;
	private:
	    node head;
		int MAXSIZE;
	public:
		void push(elementype Key);
		void pop();
		void erase(node Key);
		void insert(elementype Key,int position);
		Single();
		void build(data Input);
		bool IsEmpty();
		node begin();
		node end();
		int size();
};
template<class type>
Single<type>::Single(){
	MAXSIZE=0;
	head=NULL;
}
template<class type>
void Single<type>::build(type* keys){
	int size=sizeof(keys)/sizeof(*keys);
	for(int i=0;i<size;i++){
		push(keys[i]);
		MAXSIZE++;
	}
}
template<class type>
void Single<type>::push(type Key){
	typedef SingleListNode<type>* node;
	node p=end();
	p=new SingleListNode<type>(Key);
	MAXSIZE++;
}
template<class type>
void Single::pop(){
	typedef SingleListNode<type>* node;
	node p=head->next;
	while(p->next!=NULL){
		p=p->next;
	}
	p=NULL;
	MAXSIZE--;
}
template<class type>
void Single<type>::erase(node Key){
	typedef SingleListNode<type>* node;
	node p=head;
	node q;
	while(p->next!=NULL){
		q=p;
		p=p->next;
		if(p==Key){
			Key->next=p->next;
			q->next=Key;
			break;
		}
	}
	MAXSIZE--;
}
template<class type>
void Single<type>::insert(type Key,int position){
	typedef SingleListNode<type>* node;
	node p=begin();
	node q=p+(position-1);
	node key=new SingleListNode<type>(Key);
	key->next=q+1;
	q->next=key;
	MAXSIZE++;
}
template<class type>
int Single<type>::size(){
	return MAXSIZE;
}
template<class type>
SingleListNode<type>* Single<type>::begin(){
	return head->next;
}
template<class type>
SingleListNode<type>* Single<type>::end(){
	SingleListNode<type>* p=head->next;
	while(p->next!=NULL){
		p=p->next;
	}
	return p;
}
template<class type>
bool Single<type>::IsEmpty(){
	if(head->next==NULL){
		return true;
	}
	else{
		return false;
	}
}