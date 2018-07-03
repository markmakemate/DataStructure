#ifndef LINKLIST_H
#define LINKLIST_H
#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
template<class elementype>
struct ListNode{
	elementype data;
	ListNode* next;
	ListNode(elementype x):data(x),next(NULL){}
};
template<class elementype>
class LinkList{
	private:
		ListNode<elementype>* head;
		int MAXSIZE;
	public:
		LinkList(elementype* A,int SIZE);
		ListNode<elementype>* BuildLinkList();
		bool IsEmpty();
		void Traversal();
		int getLength();
		void DeleteNode(int position);
		void InsertNode(elementype Key,int position);
		bool FindNode(elementype key);
		elementype FindNthNode(int position,ListNode<elementype>* p);
		void PrintLots(ListNode<elementype>* L,ListNode<elementype>* P);
		
		
};
template<class elementype>
LinkList<elementype>::LinkList(elementype* A,int SIZE){
	MAXSIZE=SIZE;
	ListNode<elementype>* q=new ListNode<elementype>(*A);
	head=new ListNode<elementype>(MAXSIZE);
	head->next=q;
	for(int i=1;i<MAXSIZE;i++){
		q->next=new ListNode<elementype>(*(A+i));
		q=q->next;
	}
}
template<class elementype>
void LinkList<elementype>::Traversal(){
	ListNode<elementype>* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		cout<<temp->data<<" ";
	}
}
template<class elementype>
int LinkList<elementype>::getLength(){
	return head->data;
}
template<class elementype>
void LinkList<elementype>::DeleteNode(int Position){
	ListNode<elementype>* q=head;
	ListNode<elementype>* p;
	for(int i=1;i<Position;i++){
		q=q->next;
	}
	p=q->next;
	q->next=p->next;
}
template<class elementype>
void LinkList<elementype>::InsertNode(elementype Key,int Position){
	ListNode<elementype>* q=head;
	ListNode<elementype>* p=new ListNode<elementype>(Key);
	for(int i=1;i<Position;i++){
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
}
template<class elementype>
bool LinkList<elementype>::IsEmpty(){
	if(head->next==NULL){
		return true;
	}
	else{
		return false;
	}
}
template<class elementype>
elementype LinkList<elementype>::FindNthNode(int Position,ListNode<elementype>* p){
	ListNode<elementype>* q=p;
	string ERROR="ERROR!Out of Range!";
	for(int i=1;i<=Position;i++){
		if(q->next!=NULL){
		q=q->next;
	    }
	    else{q=q->next;break;}
	}
	if(q!=NULL){
		return q->data;
	}
	else{throw ERROR;}
}
template<class elementype>
ListNode<elementype>* LinkList<elementype>::BuildLinkList(){
	ListNode<elementype>* result=head;
	return result;
}
template<class elementype>
void LinkList<elementype>::PrintLots(ListNode<elementype>* L,ListNode<elementype>* P){
	ListNode<elementype>* L1=L;
	while(L1->next!=NULL){
		L1=L1->next;
		try{
		cout<<FindNthNode(L1->data,P)<<" ";
	   }catch(string e){cout<<e;break;}
	   
	}
}
#endif


