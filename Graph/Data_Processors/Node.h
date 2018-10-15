#include<iostream>
#include<cstdlib>
//Node of List--definition
template<class Elemtype>
struct Node{
    int vertex;   //vertex
    Elemtype data;   //weight
    Node<Elemtype>* next;   //pointer to next adjacent vertex
    bool tag;    //tag
    Node(int v,Elemtype d):vertex(v),data(d),next(NULL),tag(false){}   //Constructor
};