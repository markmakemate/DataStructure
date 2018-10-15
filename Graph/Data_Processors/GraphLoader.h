//GraphLoader Module
#include<iostream>
#include<cstdlib>
#include<map>
#define INF 1.7976931348623e+308
using namespace std;
//GraphLoader: A class which implements interfaces to load a graph for user
//GraphLoader is a middleware for Graph
//Input formula: std::map<int,map<int,double> > Input={{start_vertex_1,{{adjacent_vertex_1,weight_1},...,{adjacent_vertex_N,weight_N}}},...,{start_vertex_n,{...}}}
class GraphLoader{
    typedef map<int,map<int,double> > graph;
public:
    graph G;
    GraphLoader(graph& Input);  //Constructor
    void clear();   //clear the loader
    int size();   //num of vertexs of graph
};
GraphLoader::GraphLoader(map<int,map<int,double> >& Input){
    G=Input;
}
int GraphLoader::size(){
    return G.size();
}

