#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include ".\Search.h"
using namespace std;
template<class Elemtype>
struct RBTreeNode{
	Elemtype val;
	RBTreeNode* parent;
	RBTreeNode* left;
	RBTreeNode* right;
	string color;
	RBTreeNode(Elemtype x,string c):val(x),left(NULL),right(NULL),parent(NULL),color(c){}
};   //declaration of Red-Black tree node

template<class Elemtype>
class RedBlackTree:public BinarySearchTree<Elemtype>{
typedef RBTreeNode<Elemtype> RBT;
        private:
                RBT* root;   //declare root node
                int NUM_NODES;   //numbers of nodes
                Elemtype* CANDIDATES;
                int BLACK_HEIGHT;   //declare black-height
                int HEIGHT;  // declare height of RB tree
        public:
                RedBlackTree(Elemtype* A,int SIZE);   //Constructor
                RBT* BuildRedBlackTree();    //Build a red-black tree
                void LeftRotation(RBT* r);   // left rotation
                void RightRotation(RBT* r);  //Right rotation
                RBT* Insert(RBT* r,RBT* Node);  //Insert Node in tree
                RBT* Delete(RBT* r,RBT* Key);   // Delete Key node in tree
                void RBFixup(RBT*r,RBT* Node);  //Recolor nodes and Perform rotation
                
};   //declaration of Red-Black tree class, inheriting BianrySearchTree class

template<class Elemtype>
RedBlackTree<Elemtype>::RedBlackTree(Elemtype* A,int SIZE){
typedef RBTreeNode<Elemtype> RBT;
        CANDIDATES=A;
        NUM_NODES=SIZE;
        BLACK_HEIGHT=0;
        HEIGHT=2*log(NUM_NODES+1)/log(2);
        root=new RBT(*A,"black");
        BLACK_HEIGHT++;
}    //Constructor

template<class Elemtype>
RBTreeNode<Elemtype>* RedBlackTree<Elemtype>::BuildRedBlackTree(){
typedef RBTreeNode<Elemtype> RBT;
        RBT* p=root;
}    //Build a Red-Black tree

template<class Elemtype>
void RedBlackTree<Elemtype>::LeftRotation(RBTreeNode<Elemtype>* r){
typedef RBTreeNode<Elemtype> RBT;
        RBT* p=r,q=p->right;
        RBT* temp,m=p->parent;
        temp=q->left;
        if(m->left=p){m->left=q;}
        else{m->right=q;}
        q->left=p;
        p->right=temp;
        q->parent=m;
        p->parent=q;
}   //Left Rotation

template<class Elemtype>
void RedBlackTree<Elemtype>::RightRotation(RBTreeNode<Elemtype>* r){
typedef RBTreeNode<Elemtype> RBT;
        RBT* p=r,q=p->left;
        RBT* temp,m=p->parent;
        temp=q->right;
        if(m->left==p){m->left=q;}
        else{m->right=q;}
        p->left=temp;
        q->right=p;
        q->parent=m;
        p->parent=q;
}   //Right Rotation

template<class Elemtype>
RBTreeNode<Elemtype>* RedBlackTree<Elemtype>::Insert(RBTreeNode<Elemtype>* r,RBTreeNode<Elemtype>* Node){
typedef RBTreeNode<Elemtype> RBT;
        RBT* p=r,q;
        q=p;
        while(q!=NULL){
             if(q->val<Node->val){
                  q=q->right;
                  Node->parent=q->parent;
             }
             else{q=q->left;Node->parent=q->parent;}
        }
        if(q->parent->left=q){q->parent->left=Node;q=Node;}
        else{q->parent->right=Node;q=Node;}
        RBFixup(p,q);
        return p;
}   //Insert Node in RB Tree

template<class Elemtype>
RBTreeNode<Elemtype>* RedBlackTree<Elemtype>::Delete(RBTreeNode<Elemtype>* r,RBTreeNode<Elemtype>* Key){
typedef RBTreeNode<Elemtype> RBT;
        RBT* p=r,q;
        q=p;
        while(q!=NULL){
             if(q->val<Key->val){
                  q=q->left;
             }
             else{q=q->right;}
        }
        if(q==NULL){throw "ERROR,NO KEY!";}
        else{
             
        }
}

template<class Elemtype>
void RedBlackTree<Elemtype>::RBFixup(RBTreeNode<Elemtype>* r,RBTreeNode<Elemtype>* Node){
typedef RBTreeNode<Elemtype> RBT;
        RBT* p=r,q;
        RBT* Temp;
        while(Node->parent->color=="Red"){
              if(Node->parent==Node->parent->parent->left){
                   q=Node->parent->parent->right;
                   if(q->color=="Red"){
                       Node->parent->color="Black";
                       q->color="Black";
                       Node->parent->parent->color="Red";
                       Temp=Node->parent->parent;
                   }
                   else if(Node==Node->parent->right){
                           Temp=Node->parent;
                           LeftRotation(r,Temp);
                   }
                   Temp->parent->color="Black";
                   Temp->parent->parent->color="Red";
                   RightRotation(p,Temp->parent->parent);
               }
        }
        p->color="Black";
}   //Fix Red-Black tree

                
