#ifndef UNION_FIND_H
#define UNION_FIND_H
#include<iostream>
#include<cstdlib>
#include"Node.h"
using namespace std;
template<class T>
class Set{
private:
    Node<T>* root;
    int rank;
public:
    Set(){
        root=NULL;
        rank=0;
    }
    void Make_Set(T& value){
        root=new Node<T>(value,0);
    }
    void Union(T& B);
    void Union(Node<T>* B);
    Node<T>* Find(Npde<T>* target);
    int rank(){
        return rank;
    }
};
template<class T>
void Set<T>::Union(T& B){
    Node<T>* p=new Node<T>(B,0);
    p->parent=root;
    root->rank++;
    rank++;
}
template<class T>
void Set<T>::Union(Node<T>* B){
    if((*this).rank()>B->rank){
        B->parent=root;
    }
    else{
        root->parent=B;
        if(root->rank==B->rank){
            B->rank++;
        }
    }
}
template<class T>
Node<T>* Set<T>::Find(Node<T>* target){
    Node<T>* result=NULL;
    if(target!=target->parent){
        target->parent=Find(target->parent);
        result=target->parent;
    }
    return result;
}
#endif