#include<cstdlib>
#include<iostream>
#include "DoubleListNode.h"
#include "LinkList.h"
using namespace std;
template<class type_name>
class Double:pubic LinkList<elementype>{
    typedef elementype* data;
	typedef DoubleListNode<type_name>* node;
private:
    node head;   //head node, NULL value
	int MAXSIZE;  //List's size
public:
    Double();   //Constructor, initialize head and MAXSIZE
	void push(type_name Key);   //insert a node with value Key in List's last position
    void pop();   //delete the last node
    void erase(node Node);    //erase a node from list
    void build(data Input);   //transfer a sequence to a list
    void insert(elementype Key,int position);   //insert a node with value Key in a fixed position
    bool IsEmpty();   //discriminate wheather the list is empty
    node begin();   //return the first element after head node
    node end();     //return the expected last element
    int size();   //return list's size
};
template<class type>
Double<type>::Double(){
    head=NULL;
    head->next->previous=head;
    MAXSIZE=0;
}
template<class type>
void Double<type>::push(type Key){
    DoubleListNode<type>* p;
    p=end();
    p=new DoubleListNode<type>(Key);
    p->previous=end()->previous;
    MAXSIZE++;
}
template<class type>
void Double<type>::build(type* Input){
    int size=sizeof(Input)/sizeof(*Input);
    for(int i=0;i<size;i++){
        push(Input[i]);
        MAXSIZE++;
    }
}
template<class type>
void Double<type>::pop(){
    DoubleListNode<type>* p=head->next;
    while(p->next!=NULL){
        p=p->next;
    }
    p->previous=NULL;
    p=NULL;
    MAXSIZE--;
}
template<class type>
int Double<type>::size(){
    return MAXSIZE;
}
template<class type>
DoubleListNode<type>* Double<type>::begin(){
    return head->next;
}
template<class type>
DoubleListNode<type>* Double<type>::end(){
    DoubleListNode<type>* p=head->next;
    while(p!=NULL){
        p=p->next;
    }
    return p;
}
template<class type>
bool Double<type>::IsEmpty(){
    if(head->next==NULL){
        return true;
    }
    else{
        return false;
    }
}
