#ifndef SEARCH_H
#define SEARCH_H
#include<istream>
#include<cstdlib>
#include "Tree.h"
using namespace std;
template<class Elemtype>
template<class Elemtype>
class BinarySearhTree:public Tree<Elemtype>{
	typedef TreeNode<Elemtype> BSTreeNode;
	private:
		BSTreeNode* root;
		Elemtype* SearchingArray;
	public:
		BinarySearchTree(Elemtype* A);
		void BuildBSTree(BSTreeNode* r);
		void PercolateDown(BSTreeNode* r);
		void PercolateUp(BSTreeNode* r);
		void AVLTree(BSTreeNode* r);
		bool FindNode(Elemtype x);
		
		
};
#endif
