#include<cstdlib>
#include<iostream>
#include<queue>
#include "BinarySearchTree.h"
using namespace std;
template<class T>
class BSTProcessor:public BinarySearchTree<T>{
    typedef BSTreeNode<T>* node;
private:
    queue<T> sequence;
    T* traversal;
public:
    void build(queue<T> A);
    void insert(node Node);
    void insert(T value);
    void pop(T value);
    T* MidOT(node r=this->root);
    T* PostOT(node r=this->root);
    T* PreOT(node r=this->root);
    int size(){
        return num;
    }
};
template<class T>
void BSTProcessor<T>::build(queue<T> A){
    this->num=A.size();
    traversal=new T[this->num]    for(T value=A.front();A.size()!=0;value=A.front()){
        insert(value);
        A.pop();
    }
}
template<class T>
void BSTProcessor<T>::insert(BSTreeNode<T>* Node){
    typedef BSTreeNode<T> node;
    node* p=this->root;
    if(p==NULL){
        p=Node;
    }
    else{
        while(p!=NULL){
            if(p->data<Node->data){
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
        p=Node;
    }
}
template<class T>
void BSTProcessor<T>::insert(T value){
    typedef BSTreeNode<T> node;
    node* p=this->root;
    if(p==NULL){
        p=new node(value);
    }
    else{
        while(p!=NULL){
            if(p->data<value){
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
        p=new node(value);
    }
}
template<class T>
T* BSTProcessor<T>::MidOT(node r){
    if(r!=NULL){
        traversal=MidOT((r->left);
        sequence.push_back(r->data);
        traversal=MidOT(r->right);
    }
    else{
        traversal=new T[this->num];
        int N=sequence.size();
        for(int i=0;i<N;i++){
            traversal[i]=sequence.front();
            sequence.pop();
        }
    }
    return traversal;
}
template<class T>
T* BSTProcessor<T>::PreOT(node r){
    if(r!=NULL){
        sequence.push_back(r->data);
        traversal=PreOT(r->left);
        traversal=PreOT(r->right);
    }
    else{
        traversal=new T[this->num];
        N=sequence.size();
        for(int i=0;i<N;i++){
            traversal[i]=sequence.front();
            sequence.pop();
        }
    }
    return traversal;
}
template<class T>
T* BSTProcessor<T>::PostOT(node r){
    if(r!=NULL){
        traversal=PostOT(r->left);
        traversal=PostOT(r->right);
        sequence.push_back(r->data);
    }
    else{
        traversal=new T[this->num];
        int N=sequence.size();
        for(int i=0;i<N;i++){
            traversal[i]=sequence.front();
            sequence.pop();
        }
    }
    return traversal;
}