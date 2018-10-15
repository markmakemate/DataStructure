#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include<cstdlib>
#include "HeapProcessor.h"
using namespace std;
template<class type_name>
class Heap{
    typedef type_name* data;
    typedef Heap<type_name> heap; 
public:
    data Data;
    int MAXSIZE;
    int Parent(int position);
    int LeftChild(int position);
    int RightChild(int position);
    Heap();
    virtual void build(type_name* Input);
    virtual void push(type_name node);
    virtual void pop();
    virtual type_name top();
    virtual void swap(int position_1,int position_2);
    virtual void update();
};
template<class type_name>
Heap::Heap(){
    Data=NULL;
}
template<class type_name>
int Heap::Parent(int position){
    if(position==0){
        return -1;
    }
    else(position!=0){
        return ceil(position/2);
    }
}
template<class type_name>
int Heap::LeftChild(int position){
    return 2*position+1;
}
template<class type_name>
int Heap::RightChild(int position){
    return 2*position+2;
}
#endif