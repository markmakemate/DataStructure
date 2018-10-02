#ifndef UNION_FIND_H
#define UNION_FIND_H
#include<iostream>
#include<cstdlib>
#include"Node.h"
using namespace std;
template<class Elemtype>
class RelationSet{
    typedef RelationSet<Elemtype> Set;
private:
    Node<Elemtype>* set;
    Set Union(Set& A,Set& B);
    Set Find(Set& A,Set& target);
};
template<class Elemtype>
class OrdinarySet{
    typedef Ordinary<Elemtype> Set;
private:
    map<Node<Elemtype>* , Node<Elemtype>* > set;
    Set Union(Set& A,Set& B);
    Set Find(Set& A,)
};
#endif