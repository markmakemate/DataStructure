#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
//Red black tree is a type of balanced binary search tree whose nodes are colored in "Red" or "Black" with properties:
//(1) Root is black
//(2) Every leaf is black
//(3) A node's children are black if it is red
//(4) All simple path to decendant leaves contain same number black nodes for each node from it. 
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
class RedBlackTree{
typedef RBTreeNode<Elemtype> RBT;
        private:
                RBT* root;   //declare root node
                int NUM_NODES;   //numbers of nodes
                int BLACK_HEIGHT;   //declare black-height
                int HEIGHT;  // declare height of RB tree
	            RBT* CANDIDATE;     //Candidate node;
        public:
                RedBlackTree(int SIZE);   //Constructor
                RBT* BuildRedBlackTree(Elemtype* A);    //Build a red-black tree
                void LeftRotation(RBT* r);   // left rotation
                void RightRotation(RBT* r);  //Right rotation
                RBT* Insert(RBT* r,RBT* Node);  //Insert Node in tree
                RBT* Delete(RBT* r,RBT* Key);   // Delete Key node in tree
                RBT* RBFixup(RBT*r,RBT* Node);  //Recolor nodes and Perform rotation
                void MOT(RBT* r);         //Middle order traversal
                void Pre_OT(RBT* r);      //Pre-order traversal
                void Post_OT(RBT* r);     //Post-order traversal
                
};   //Declaration of Red-Black tree class

template<class Elemtype>
RedBlackTree<Elemtype>::RedBlackTree(int SIZE){
typedef RBTreeNode<Elemtype> RBT;
        NUM_NODES=SIZE;
        BLACK_HEIGHT=0;
        HEIGHT=2*log(NUM_NODES+1)/log(2);
		root = NULL;
}    //Constructor

template<class Elemtype>
RBTreeNode<Elemtype>* RedBlackTree<Elemtype>::BuildRedBlackTree(Elemtype* A){
	typedef RBTreeNode<Elemtype> RBT;
	RBT* p = root;
	RBT* q;
	for (int i = 0; i < NUM_NODES; i++) {
		q = new RBT(*(A + i), "Black");
		p = Insert(p, q);
	}
	return p; 
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
        if(r!=NULL){
        	if(r->val>Node->val){
        		r->left=Insert(r->left,Node);
			}
			else{
				r->right=Insert(r->right,Node);
			}
		}
		else{
			Node->parent = r->parent;
			Node->color = "Red";
			r=Node;
        }			
        r=RBFixup(r,Node);
        return r;
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
}   //Delete a node from red black tree

template<class Elemtype>
RBTreeNode<Elemtype>* RedBlackTree<Elemtype>::RBFixup(RBTreeNode<Elemtype>* r,RBTreeNode<Elemtype>* Node){
	typedef RBTreeNode<Elemtype> RBT;
	RBT* y;
	if(Node!=NULL&&Node->parent!=NULL&&Node->parent->parent!=NULL){
		while (Node->parent->color == "Red") {
			if (Node->parent == Node->parent->parent->left) {
				y = Node->parent->parent->right;
				if (y->color == "Red") {
					Node->parent->color = "Black";
					y->color = "Black";
					Node->parent->parent->color = "Red";
					Node = Node->parent->parent;
				}
				else if (Node == Node->parent->right) {
					Node = Node->parent;
					LeftRotation(r, Node);
				}
				Node->parent->color = "Black";
				Node->parent->parent->color = "Red";
				RightRotation(r, Node);
				r=RBFixup(r, Node);
			}
			else if (Node->parent == Node->parent->parent->right) {
				y = Node->parent->parent->left;
				if (y->color == "Red") {
					Node->parent->color = "Black";
					y->color = "Black";
					Node->parent->parent->color = "Red";
					Node = Node->parent->parent;
				}
				else if (Node == Node->parent->left) {
					Node = Node->parent;
					RightRotation(r, Node);
				}
				Node->parent->color = "Black";
				Node->parent->parent->color = "Red";
				LeftRotation(r, Node);
				r=RBFixup(r, Node);
			}
		}
	}
	return r;
}   //Fix up a Red-Black tree

#endif
//Reference
//[1] Introduction to Algorithms, T.H.Cormen, 2009, MIT Press
//[2] Data Structure and Algorithm Analysis in C, 1997, Addison Wesley Longman           
