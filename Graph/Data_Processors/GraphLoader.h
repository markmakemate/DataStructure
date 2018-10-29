//GraphLoader Module
#include<iostream>
#include<cstdlib>
#include<map>
#define INF 1.7976931348623e+308
using namespace std;
//GraphLoader: A class which implements interfaces to load a graph for user
//GraphLoader is a middleware for Graph
//Input formula: std::map<int,pair<int,double> > Input={{start_1,(end_1,edge_1),...,(end_N,edge_N)},...,{start_M,(end_1,edge_1),...,(end_K,edge_K)}}
class GraphLoader{
    typedef map<int,pair<int,double> > graph;
    typedef pair<int,double> edge;
public:
    graph G;
    GraphLoader(graph& Input);  //Constructor
    void load(graph& Input);   //load a graph
    void push(graph& subgraph);   // push a subgraph
    void insert(int u,edge E);   //insert a new edge
    void clear();   //clear the loader
    
};
GraphLoader::GraphLoader(map<int,pair<int,double> >& Input){
    G=Input;
}
int GraphLoader::size(){
    return G.size();
}
void GraphLoader::load(map<int,pair<int,double> >& Input){
    G=Input;
}
void GraphLoader::clear(){
    Input.clear();
}

