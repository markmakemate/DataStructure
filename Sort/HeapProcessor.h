#ifndef HEAPPROCESSOR_H
#define HEAPPROCESSOR_H
#include<iostream>
#include<cstdlib>
#include "Heap.h"
using namespace std;
template<class type_name>
class HeapProcessor:public Heap<type_name>{
    typedef type_name* data;
public:
    void build(data Input);
    void push(type_name node);
    void pop();
    type_name top();
    void swap(int position_1,int position_2);
    void update();
    virtual 
};
template<class type_name>
void Heap::build(type_name* Input){
    int size=sizeof(Input)/sizeof(*Input);
    this->MAXSIZE=size;
    for(int i=0;i<size;i++){
        this->push(*(Input+i));
    }
}
template<class type_name>
void Heap::push(type_name node){
    int position=0;
    if(this->Data==NULL){
        *Data=node;
    }
    else{
        while(position!=this->MAXSIZE){
            if(*(Data+position)<node){
                position=this->RightChild(position);
            }
            else{
                position=this->LeftChild(position);
            }
        }
    }
    type_name* candidate=new type_name[position-MAXSIZE+1];
    if(position>=this->MAXSIZE){
        this->MAXSIZE=position+1;
    }


}
#endif
