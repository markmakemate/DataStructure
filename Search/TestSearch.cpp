#include<iostream>
#include "Search.h"
#include<cstdlib>
using namespace std;
void Print(BSTreeNode<int>* r);
int main(){
    int A[10]={1,2,3,4,5,6,7,8,9,11};
    int* T=A;
    BSTreeNode<int>* BSTN;
    BinarySearchTree<int> BST(T,10);
    BST.BuildBSTree();
    BSTN=BST.root;
    Print(BSTN);
    BSTreeNode<int>* BSTN1=new BSTreeNode<int>(12);
    BST.Insertion(BSTN,BSTN1);
    Print(BSTN);
    bool sign=BST.FindNode(13);
    if(sign==true){cout<<0;}
    else{cout<<1;}
    return 0;
}
void Print(BSTreeNode<int>* r){
    BSTreeNode<int>* p=r;
    if(p!=NULL){
       cout<<p->data<<", ";
       Print(p->left);
       Print(p->right);
    }
    cout<<"\n";
}
