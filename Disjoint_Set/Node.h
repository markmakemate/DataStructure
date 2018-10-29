#ifndef NODE_H
#define NODE_H
#include<cstdlib>
#include<iostream>
#include"../Disjoint_Set/Union_Find.h"
using namespace std;
template<class Elemtype>
struct Node{
    Elemtype data;
    int rank;
    Node<Elemtype>* parent;
    Node(Elemtype x,int r):data(x),parent(this),rank(r){}
};
#endif