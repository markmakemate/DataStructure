#include<iostream>
//B-Tree is a type of search tree which is often used in database systems for storage
//B-Tree has properties:
//1. Every node has the following attributes: a. the number of keys currently stored in a node; b. Keys stored in nondecreasing order; c.Leaf is boolean value with "true" and "false"
//2. Each node has n+1(n is keys number) pointers to its children. Leaf node have no children with these pointers undefined. 
//3. All leaves have the same depth whichis the tree's height. 
//
using namespace std;
template<class Elemtype>
