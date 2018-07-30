#include<iostream>
#include "Search.h"
#include<cstdlib>
using namespace std;
int main(){
    int A[10]={111,22,120,4,50,6,70,2,91,11};
    int* T=A;
    for(int i=0;i<10;i++){
    	*(T+i)=A[i];
	}
    BSTreeNode<int>* BSTN;
    HashSearching<int> H(10);   //Hash class
    BinarySearchTree<int> BST(10);  //Binary Search tree class
    BSTN=BST.BuildBSTree(T);  //Build a BS tree
    BSTreeNode<int>* BSTN1=new BSTreeNode<int>(12);   //Build a new node
    BSTN=BST.Insertion(BSTN,BSTN1);
    bool sign=BST.FindNode(BSTN,13);
    if(sign==true){cout<<0<<endl;}
    else{cout<<1<<endl;}
    BST.MOT(BSTN);
    cout<<endl;
    int* R=H.LinearProbing(T,10);
    int p=H.Find(22,"Linear probing");
    cout<<p;
    return 0;
}


