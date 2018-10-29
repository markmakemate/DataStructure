#include<iostream>
#include<cstdlib>
#include<map>
#include "Node.h"
//List: a class to store a sparse graph
//push: push a new adjacent vertex
//pop: pop the last adjacent vertex
//clear: delete a vertex and the connections of all its adjacent vertexs
//build: build a list
template<class Elemtype>
class List{
    typedef Node<Elemtype>* node;
private:
    node head;
public:
    List();
    void push(map<int,double>& Vertex);
    void pop();
    void build(map<int,map<int,double> >& Input);
    void clear();
    node head();
    Elemtype operator[](int& vertex)
        node p=head->next;
        while(p!=NULL){
            if(p->vertex==vertex){
                break;
            }
        }
        return p->data;
    }
    bool is_traversed(int u,int v);
};
template<class Elemtype>
List<Elemtype>::List(){
    head=NULL;
}
template<class Elemtype>
void List<Elemtype>::push(map<int,double>& Vertex){
    map<int,double>::iterator it=Vertex.begin();
    Node<Elemtype>* p=head->next;
    while(p!=NULL){
        p=p->next;
    }
    p=new Node<Elemtype>(it->first,it->second);
}
template<class Elemtype>
void List<Elemtype>::build(map<int,map<int,double> >& Input){
    map<int,map<int,double> >::iterator it_1=Input.begin();
    map<int,double>::iterator it_2;
    head=new Node<Elemtype>(it_1->first,0);
    for(it_2=(it_1->second).begin();it_1!=(it_1->second).end();++it_1){
        push(*it_1);
    }
    
}
template<class type_name>
void List<Elemtype>::clear(){
    Node<Elemtype>* p=head->next;
    Node<Elemtype>* q=p->next;
    while(q!=NULL){
        delete p;
        p=q;
        q=q->next;
    }
    delete q;
    head=NULL;
}
template<class Elemtype>
Node<Elemtype>* List<Elemtype>::head(){
    return head;
}