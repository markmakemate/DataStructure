#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<iostream>
#include<cstdlib>
using namespace std;
template<class Elemtype>
struct BSTreeNode{
   Elemtype data;
   BSTreeNode* left;
   BSTreeNode* right;
   BSTreeNode(Elemtype x):data(x),left(NULL),right(NULL){}
};   //Declaration  of Binary search tree node

template<class Elemtype>
class BinarySearchTree{
    typedef BSTreeNode<Elemtype>* node;
    private:
        node root;
        int num;
	public:
	    BinarySearchTree();   //Constructor
	    virtual void build();
        virtual void insert();
		virtual void MidOT();
		virtual void PostOT();
		virtual void PreOT();
        virtual int size();		
};   //Binary search tree class
template<class type_name>
BinarySearchTree<type_name>::BinarySearchTree(){
    root=NULL;
    num=0;
}
template<class T>
#include "BSTProcessor.h"
#endif