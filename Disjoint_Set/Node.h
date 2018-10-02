#ifndef NODE_H
#define NODE_H
#include<cstdlib>
#include<iostream>
#include"../Disjoint_Set/Union_Find.h"
using namespace std;
template<class Elemtype>
struct Node{
    Elemtype data;
    bool tag;
    Node<Elemtype>* Father;
    Node(Elemtype x):data(x),Father(NULL),tag(false){}
};
#endif