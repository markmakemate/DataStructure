#ifndef SEARCH_H
#define SEARCH_H
#include<iostream>
#include<cstdlib>
#include"../LinkList/LinkList.h"
#include<vector>
#include<cmath>
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
	private:
            Elemtype* SearchingArray;
            int NUM_NODES;
	public:
            BSTreeNode<Elemtype>* root;
	    BinarySearchTree(Elemtype* A,int SIZE);
           ~BinarySearchTree();
	    void BuildBSTree();
            void Insertion(BSTreeNode<Elemtype>* r,BSTreeNode<Elemtype>* node);
            void AVL(BSTreeNode<Elemtype>* r);
	    bool FindNode(Elemtype x);			
};   //Binary search tree class

template<class Elemtype>
BinarySearchTree<Elemtype>::BinarySearchTree(Elemtype* A,int SIZE){
   typedef BSTreeNode<Elemtype> Node;
   SearchingArray=A;
   root=new Node(*A);
   NUM_NODES=SIZE;
}    //Constructor

template<class Elemtype>
BinarySearchTree<Elemtype>::~BinarySearchTree(){
   delete[] root;
   delete[] SearchingArray;
}

template<class Elemtype>
void BinarySearchTree<Elemtype>::BuildBSTree(){
   typedef BSTreeNode<Elemtype>* Node;
   typedef BSTreeNode<Elemtype> BST;
   Node p=root;
   Node q;
   int COUNT=0;
   while(COUNT<NUM_NODES){
     q=new BST(*(SearchingArray+COUNT));
     Insertion(p,q);
   }
}  //Build a binary search tree

template<class Elemtype>
void BinarySearchTree<Elemtype>::Insertion(BSTreeNode<Elemtype>* r,BSTreeNode<Elemtype>* node){
   typedef BSTreeNode<Elemtype>* Node;
   Node p=r;
   while(p!=NULL){
     if(p->data>node->data){
       p=p->left;
     }
     else{p=p->right;}
   }
   p=node;
}   //Insert a node

template<class Elemtype>
bool BinarySearchTree<Elemtype>::FindNode(Elemtype x){
   typedef BSTreeNode<Elemtype>* Node;
   Node p=root;
   bool sign=false;
   while(p!=NULL){
     if(p->data=x){sign=true;break;}
     else if(p->data>x){p=p->left;}
     else{p=p->right;}
   }
   return sign;
}    //Discriminate wheather node is in tree



//Here is the interface of B-Tree
template<class Elemtype>
class B_Tree{
};   //B-Tree class


//Here is the interface of Hash
template<class Elemtype>
class HashSearching:LinkList<Elemtype>{
	typedef ListNode<Elemtype>* Node;
     private:
          int LENGTH;
          int HashFunction(Elemtype input,int L);
          vector<Node> CHAIN;
          Elemtype* HASHTABLE;
     public:
          HashSearching(int SIZE);
          void Chaining(Elemtype* A,int SIZE);
          Elemtype* LinearProbing(Elemtype* A,int SIZE);
          Elemtype* QuadraticProbing(Elemtype* A,int SIZE,int a,int b);
          Elemtype* DoubleHash(Elemtype* A,int SIZE);
};  //Hash Class

template<class Elemtype>
int HashSearching<Elemtype>::HashFunction(Elemtype input,int L){
	int POSITION;
	POSITION=input%L;
}   //Hash function

template<class Elemtype>
HashSearching<Elemtype>::HashSearching(int SIZE){
	LENGTH=SIZE*2;
}   //Constructor

template<class Elemtype>
void HashSearching<Elemtype>::Chaining(Elemtype* A,int SIZE){
	typedef ListNode<Elemtype>* Node;
	int POSITION;
	Node p,q;
	for(int i=0;i<SIZE;i++){
		POSITION=HashFunction(*(A+i),LENGTH);
		if(POSITION<CHAIN.size()){
			p=CHAIN.at(POSITION);
			q=this->Insertion(p,*(A+i));
			CHAIN.push_back(q);
			CHAIN.swap(POSITION,CHAIN.end());
			CHAIN.pop_back();
		}
		else{
			p=new ListNode<Elemtype>(*(A+i));
			CHAIN.push_back(p);
		}
	}
}
template<class Elemtype>
Elemtype* HashSearching<Elemtype>::LinearProbing(Elemtype* A,int SIZE){
	int POSITION,COUNT=0;
	for(int i=0;i<LENGTH;i++){
		HASHTABLE+i=NULL;
	}
	while(COUNT<SIZE){
		POSITION=HashFunction(*(A+COUNT),LENGTH);
		if(HASHTABLE+POSITION==NULL){
			*(HASHTABLE+POSITION)=*(A+COUNT);
		}
		else{
			for(int i=0;i<LENGTH;i++){
			     POSITION=(POSITION+i)%LENGTH;
			     if(HASHTABLE+POSITION==NULL){*(HASHTABLE+POSITION)=*(A+COUNT);break;}
		    }
		}

	}
	return HASHTABLE;
}
template<class Elemtype>
Elemtype* HashSearching<Elemtype>::QuadraticProbing(Elemtype* A,int SIZE,int a,int b){
	int hash,COUNT=0;
	while(COUNT<SIZE){
		hash=HashFunction(*(A+COUNT),LENGTH);
		if(HASHTABLE+hash==NULL){
		    *(HASHTABLE+hash)=*(A+COUNT);
	    }
	    else{
	    	for(int i=0;i<LENGTH;i++){
			    hash=(hash+a*i+b*(int)pow(i,2))%LENGTH;
			    if(HASHTABLE+hash==NULL){*(HASHTABLE+hash)=*(A+COUNT);break;}
		    }
	    }
	}
	return HASHTABLE;
}


//Here is the interface of Binary Search algorithm
template<class Elemtype>
class BinarySearch{
     public:
          bool BiSearch(Elemtype* A,Elemtype val,int L);
};

template<class Elemtype>
bool BinarySearch<Elemtype>::BiSearch(Elemtype* A,Elemtype val,int LENGTH){
    bool sign=false;
    int POSITION;
    if(LENGTH>1){
      POSITION=LENGTH/2;
      if(val==*(A+POSITION-1)){sign=true;}
      if(val>*(A+POSITION-1)){Search(A+POSITION,val,LENGTH-POSITION);}
      else{Search(A,val,POSITION-1);}
    }
    return sign;
}      
        



#endif
