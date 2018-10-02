#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H
#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;
class GraphLoader{
    typedef map<int,map<int,double> > graph;
public:
    graph G;
    GraphLoader(graph& Input);
    double operator()(int start,int end);
};
GraphLoader::GraphLoader(map<int,map<int,double> >& Input){
    G=Input;
}
double GraphLoader::operator()(int start,int end){
    return G.at(start).at(end);
}
template<class Elemtype>
struct DataSet{
    int vertex;
    Elemtype data;
    DataSet(int v,Elemtype d):vertex(v),data(d){}
};
#endif