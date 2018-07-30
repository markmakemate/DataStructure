#ifndef SEARCH_H
#define SEARCH_H
#include<iostream>
#include<cstdlib>
#include"../LinkList/LinkList.h"
#include<vector>
#include<cmath>
#include<cstring>
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
            int NUM_NODES;
            BSTreeNode<Elemtype>* root;
	public:
	    BinarySearchTree(int SIZE);
	    BSTreeNode<Elemtype>* BuildBSTree(Elemtype* A);
        BSTreeNode<Elemtype>* Insertion(BSTreeNode<Elemtype>* r,BSTreeNode<Elemtype>* node);
        void AVL(BSTreeNode<Elemtype>* r);
	    bool FindNode(BSTreeNode<Elemtype>* r,Elemtype x);	
		void MOT(BSTreeNode<Elemtype>* r);
		void PostOT(BSTreeNode<Elemtype>* r);
		void PreOT(BSTreeNode<Elemtype>* r);		
};   //Binary search tree class

template<class Elemtype>
BinarySearchTree<Elemtype>::BinarySearchTree(int SIZE){
   NUM_NODES=SIZE;
}    //Constructor


template<class Elemtype>
BSTreeNode<Elemtype>* BinarySearchTree<Elemtype>::BuildBSTree(Elemtype* A){
   typedef BSTreeNode<Elemtype>* Node;
   typedef BSTreeNode<Elemtype> BST;
   root=NULL;
   int COUNT=0;
   while(COUNT<NUM_NODES){
     Node q=new BST(*(A+COUNT));
     root=Insertion(root,q);
     COUNT++;
   }
   return root;
}  //Build a binary search tree

template<class Elemtype>
BSTreeNode<Elemtype>* BinarySearchTree<Elemtype>::Insertion(BSTreeNode<Elemtype>* r,BSTreeNode<Elemtype>* node){
   typedef BSTreeNode<Elemtype>* Node;
   if(r==NULL){
   	r=node;
   }
   else{
   	if(r->data>node->data){
       r->left=Insertion(r->left,node);
     }
     else{r->right=Insertion(r->right,node);}
   }
   return r;
}   //Insert a node

template<class Elemtype>
bool BinarySearchTree<Elemtype>::FindNode(BSTreeNode<Elemtype>* r,Elemtype x){
   typedef BSTreeNode<Elemtype>* Node;
   Node p=r;
   bool sign=false;
   while(p!=NULL){
     if(p->data==x){sign=true;break;}
     else if(p->data>x){p=p->left;}
     else{p=p->right;}
   }
   return sign;
}    //Discriminate wheather node is in tree

template<class Elemtype>
void  BinarySearchTree<Elemtype>::MOT(BSTreeNode<Elemtype>* r){
	typedef BSTreeNode<Elemtype>* Node;
	if(r!=NULL){
		cout<<r->data<<", ";
		MOT(r->left);
		MOT(r->right);
	}
}   //Mid-order traversal

template<class Elemtype>
void BinarySearchTree<Elemtype>::PostOT(BSTreeNode<Elemtype>* r){
	if(r!=NULL){
		PostOT(r->left);
		PostOT(r->right);
		cout<<r->data<<", ";
	}
}   //Post order traversal

template<class Elemtype>
void BinarySearchTree<Elemtype>::PreOT(BSTreeNode<Elemtype>* r){
	if(r!=NULL){
		PreOT(r->left);
		cout<<r->data<<", ";
		PreOT(r->right);
	}
}


//Here is the class of Hash
template<class Elemtype>
class HashSearching:LinkList<Elemtype>{
	typedef ListNode<Elemtype>* Node;
     private:
          int LENGTH;
          int HashFunction(int input,int L);
          int CollisionSolve(string selection,Elemtype A);
          vector<Node> CHAIN;
          Elemtype* HASHTABLE;
     public:
          HashSearching(int SIZE);
          void Chaining(Elemtype* A,int SIZE);
          Elemtype* LinearProbing(Elemtype* A,int SIZE);
          Elemtype* QuadraticProbing(Elemtype* A,int SIZE);
          Elemtype* DoubleHash(Elemtype* A,int SIZE);
          int Find(Elemtype A,string selection);
};  //Hash Class

template<class Elemtype>
int HashSearching<Elemtype>::HashFunction(int input,int L){
	int POSITION;
	POSITION=input%L;
}   //Hash function

template<class Elemtype>
int HashSearching<Elemtype>::CollisionSolve(string selection,Elemtype A){
	int Position;
	Position=HashFunction((int)A,LENGTH);	
	if(selection=="Linear probing"){		
		for(int i=0;i<LENGTH;i++){
			 if(*(HASHTABLE+Position)==A){break;}
			 else{Position=(Position+i)%LENGTH;}
		}
	}
	else if(selection=="Quadratic probing"){
		for(int i=0;i<LENGTH;i++){
			if(*(HASHTABLE+Position)==A){break;}
			else{Position=(Position+(int)pow(i,2))%LENGTH;}
		}
	}
	return Position;
}    //Collision Solution

template<class Elemtype>
HashSearching<Elemtype>::HashSearching(int SIZE){
	LENGTH=SIZE*2;
	HASHTABLE=new Elemtype[LENGTH];
}   //Constructor

template<class Elemtype>
void HashSearching<Elemtype>::Chaining(Elemtype* A,int SIZE){
	typedef ListNode<Elemtype>* Node;
	typedef ListNode<Elemtype> List;
	int POSITION;
	Node p,q;
	for(int i=0;i<SIZE;i++){
		POSITION=HashFunction((int)*(A+i),LENGTH);
		if(POSITION<CHAIN.size()){
			p=CHAIN.at(POSITION);
			q=this->Insertion(p,*(A+i));
			CHAIN.push_back(q);
			CHAIN.swap(POSITION,CHAIN.end());
			CHAIN.pop_back();
		}
		else{
			p=new List(*(A+i));
			CHAIN.push_back(p);
		}
	}
}   //Chaining method

template<class Elemtype>
Elemtype* HashSearching<Elemtype>::LinearProbing(Elemtype* A,int SIZE){
	int POSITION,COUNT=0;
	while(COUNT<SIZE){
		POSITION=HashFunction((int)*(A+COUNT),LENGTH);
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
}   //Linear probing

template<class Elemtype>
Elemtype* HashSearching<Elemtype>::QuadraticProbing(Elemtype* A,int SIZE){
	int hash,COUNT=0;
	while(COUNT<SIZE){
		hash=HashFunction((int)*(A+COUNT),LENGTH);
		if(HASHTABLE+hash==NULL){
		    *(HASHTABLE+hash)=*(A+COUNT);
	    }
	    else{
	    	for(int i=0;i<LENGTH;i++){
			    hash=(hash+(int)pow(i,2))%LENGTH;
			    if(HASHTABLE+hash==NULL){*(HASHTABLE+hash)=*(A+COUNT);break;}
		    }
	    }
	}
	return HASHTABLE;
}   //Quadratic probing, a and b are parameters

template<class Elemtype>
int HashSearching<Elemtype>::Find(Elemtype A,string s){
	int h=HashFunction((int)A,LENGTH);
	if(*(HASHTABLE+h)!=A){
	    h=CollisionSolve(s,A);
    }
	return h;
}

//Here is the Class of Binary Search algorithm
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
      if(val>*(A+POSITION-1)){BiSearch(A+POSITION,val,LENGTH-POSITION);}
      else{BiSearch(A,val,POSITION-1);}
    }
    return sign;
}      
        



#endif
