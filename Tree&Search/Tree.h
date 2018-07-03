#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<cstdlib>
using namespace std;
template<class Elemtype>
struct TreeNode {
	Elemtype val;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode(Elemtype x):val(x),lchild(NULL),rchild(NULL){}
};
template<class Elemtype>
class Tree {
private:
	TreeNode<Elemtype> * root;
	int NUM_NODES;
	int count;
	Elemtype* TreeElems;
public:
	Tree(Elemtype* A);
    ~Tree();
	void BuildTree(TreeNode<Elemtype>* r);
	void PreOrder(TreeNode<Elemtype>* r);
	void LDR(TreeNode<Elemtype>* r);
	void LRD(TreeNode<Elemtype>* r);
	void InsertNode(TreeNode<Elemtype>* Key);
	void DeleteNode(TreeNode<Elemtype>* Key);
};
template<class Elemtype>
Tree<Elemtype>::Tree(Elemtype* A) {
	TreeNode<Elemtype>* p = new TreeNode<Elemtype>(*A);
	root = p;
	NUM_NODES = sizeof(A) / sizeof(*A);
	TreeElems = new Elemtype[NUM_NODES];
	for (int i = 0; i < NUM_NODES; i++) {
		*(TreeElems + i) = *(A + i);
	}
	count = 0;
	BuildTree(root);
}
template<class Elemtype>
void Tree<Elemtype>::PreOrder(TreeNode<Elemtype>* r) {
	if(r!=NULL&&getTag(r)!=VISITED){
	  SetTag(r,VISITED);
	  MOT(r->lchild);
	  MOT(r->rchild);
    }
}
template<class Elemtype>
void Tree<Elemtype>::BuildTree(TreeNode<Elemtype>* r) {
	TreeNode<Elemtype>* p=r;
	if(count<NUM_NODES-2){
	TreeNode<Elemtype>* L = new TreeNode<Elemtype>(*(TreeElems+count+1));
	TreeNode<Elemtype>* R = new TreeNode<Elemtype>(*(TreeElems+count+2));
	p->lchild = L;
	p->rchild = R;
	count = count + 2;
	BuildTree(p->lchild);
	BuildTree(p->rchild);
	}
	else { count = 0; }

}
template<class Elemtype>
void Tree<Elemtype>::InsertNode(TreeNode<Elemtype>* Key){
	
}
#endif // !TREE_H

