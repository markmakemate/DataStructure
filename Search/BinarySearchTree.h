#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<iostream>
#include<cstdlib>
#include "BSTProcessor.h"
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
	public:
        node root;
	    BinarySearchTree();   //Constructor
	    virtual node build(Elemtype* A);
        virtual node insert(node Node);
        virtual node pop(type_name value);	
		virtual void MidOT();
		virtual void PostOT();
		virtual void PreOT();		
};   //Binary search tree class
template<class type_name>
BinarySearchTree<type_name>::BinarySearchTree(){
    root=NULL;
}
#endif