#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
template<class Elemtype>
struct BSTreeNode{
	Elemtype* val;    //node's value
	BSTreeNode* P;    //Parent pointer
	BSTreeNode* left;  //left child pointer
	BSTreeNode* right; //right child pointer 
	BSTreeNode(Elemtype x):val(x),left(NULL),right(NULL),P(NULL){}  //initialize node
};   //declare node struct

template<class Elemtype>
class BinarySearchTree{          //declare a class of Binary Search Tree
typedef BSTreeNode<Elemtype> BS;
    private:
    	BS* root;    //root node
    	int NUM_NODES;  //The number of nodes
    	int Height;    //Tree's height
    	int COUNT;   //a sign parameter
    	Elemtype* elems;  //nodes' elements
    public:
    	BinarySearchTree(Elemtype* A,int SIZE);
    	BS* BuildBSTree();
    	BS* Search(BS* r,Elemtype Key);
    	void Insert(BS* r,BS* Node);
    	void Delete(BS* r,BS* Key);
    	void Transplant(BS* x,BS* y);
    	void InOrderTraversal(BS* r);
    	void PreOrderTraversal(BS* r);
    	void PostOrderTraversal(BS* r);
    	BS* Successor(BS* r);
    	BS* FindMin(BS* r);
    	BS* FindMax(BS* r);
};

template<class Elemtype>
BinarySearchTree<Elemtype>::BinarySearchTree(Elemtype* A,int SIZE){      //Constructor
	typedef BSTreeNode<Elemtype> BS;
	NUM_NODES=SIZE;
	Height=log(SIZE+1)/log(2);
	root=new BS(*A);
	COUNT=1;
	elems=A;
}

template<class Elemtype>
BSTreeNode<Elemtype>* BinarySearchTree<Elemtype>::BuildBSTree(){        //Building a binary search tree
	typedef BSTreeNode<Elemtype> BS;
	BS* p;
	while(COUNT<NUM_NODES){
		p=new BS(*(elems+COUNT));
		COUNT++;
		Insert(root,p);
	}
	return root;
}

template<class Elemtype>
BSTreeNode<Elemtype>* BinarySearchTree<Elemtype>::Search(BSTreeNode<Elemtype>* r,Elemtype Key){     //Find node "Key"
	typedef BSTreeNode<Elemtype> BS;
	BS* p=r;
	if(p!=NULL){
	  if(p->val==Key){
		return p;
	  }  
	  else if(p->val<Key){
		Search(p->right,Key);
	  }  
	  else if(p->val>Key){
		Search(p->right,Key);
	  }
    }
    else{return p;}
}

template<class Elemtype>
void BinarySearchTree<Elemtype>::Insert(BSTreeNode<Elemtype>* r,BSTreeNode<Elemtype>* Node){      //Insert a node in tree
	typedef BSTreeNode<Elemtype> BS;
	BS* p=r;
	BS* q;
	if(p==NULL){
		r=Node;
	}
	else{
	  while(p!=NULL){
		if(Node->val<p->val){
			p=p->left;
		}
		else{p=p->right;}
	    }
	    q=p->P;
	  if(Node->val<q->val){q->left=Node;Node->P=q;}
	  else{q->right=Node;Node->P=q;}
    }
}

template<class Elemtype>
void BinarySearchTree<Elemtype>::Delete(BSTreeNode<Elemtype>* r,BSTreeNode<Elemtype>* Key){         //Delete a node from tree
	typedef BSTreeNode<Elemtype> BS;
	BS* x=r;
	BS* q=NULL,y,temp;
	if(x!=NULL){
		if(Key->val==x->val){
			q=x;
		}
		else if(Key->val<x->val){
			Delete(x->left,Key);
		}
		else if(Key->val>x->val){
			Delete(x->right,Key);
		}
	}
	else{cout<<"No Key in BSTree!";}   //Error
	if(q!=NULL){
		if(q->left==NULL&&q->right!=NULL){
		   Transplant(q,q->left);
	   } 
	    else if(q->left!=NULL&&q->right==NULL){
		   Tranplant(q,q->right);
	   }
	   else if(q->left!=NULL&&q->right!=NULL){
	   	   y=FindMin(q->right);
	   	   temp=y;
	   	   if(y->P!=q){
	   	   	Tranplant(y,y->right);
	   	   	temp->right=q->right;
	   	   	temp->right->P=temp;
			  }
		   Transplant(q,temp);
		   temp->left=q->left;
		   temp->left->P=temp;
	   	   delete q;
	   }
	}
}

template<class Elemtype>
void BinarySearchTree<Elemtype>::Transplant(BSTreeNode<Elemtype>* x,BSTreeNode<Elemtype>* y){     //Transplant subtree x to y
	if(x==NULL){
		x=y;
	}
	if(x==x->P->left){
		x->P->left=y;
	}
	else if(x==x->P->right){
		x->P->right=y;
	}
	if(y!=NULL){
		y->P=x->P;
	}
}

template<class Elemtype>
BSTreeNode<Elemtype>* BinarySearchTree<Elemtype>::FindMin(BSTreeNode<Elemtype>* r){    //Find minimum of subtree r
	if(r->left==NULL){
		return r;
	}
	else{
		FindMin(r->left);
	}
}
template<class Elemtype>
BSTreeNode<Elemtype>* BinarySearchTree<Elemtype>::FindMax(BSTreeNode<Elemtype>* r){    //Find the maximum of subtree r
	if(r->right==NULL){
		return r;
	}
	else{
		FindMax(r->right);
	}
}

template<class Elemtype>
BSTreeNode<Elemtype>* BinarySearchTree<Elemtype>::Successor(BSTreeNode<Elemtype>* r){  //Find successor of node r
	typedef BSTreeNode<Elemtype> BS;
	BS* y;
	if(r->right!=NULL){
		FindMin(r->right);
	}
	else{
		y=r->P;
	}
}

template<class Elemtype>
void BinarySearchTree<Elemtype>::InOrderTraversal(BSTreeNode<Elemtype>* r){  //print the series of inorder traversal
	typedef BSTreeNode<Elemtype> BS;
	BS* p=r;
	if(p!=NULL){
	  InOrderTraversal(p->left);
	  cout<<p->val<<" ";
	  InOrderTraversal(p->right);
    }
}

template<class Elemtype>
void BinarySearchTree<Elemtype>::PreOrderTraversal(BSTreeNode<Elemtype>* r){   //print the series of preorder traversal
    typedef BSTreeNode<Elemtype> BS;
    BS* p=r;
    if(p!=NULL){
    	cout<<p->val<<" ";
    	PreOrderTraversal(p->left);
    	PreOrderTraversal(p->right);
	}
}

template<class Elemtype>
void BinarySearchTree<Elemtype>::PostOrderTraversal(BSTreeNode<Elemtype>* r){     //print the series of preorder travesal
	typedef BSTreeNode<Elemtype> BS;
	BS* p=r;
	if(p!=NULL){
		PostOrderTraversal(p->left);
		PostOrderTraversal(p->right);
		cout<<p->val<<" ";
	}
}
#endif
