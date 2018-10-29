#include<iostream>
#include<cstdlib>
#include "Graph.h"
#include "../Data_Processors/AdjMatrix.h"
#include "../Data_Processors/GraphLoader.h"
using namespace std;
class graph:public Graph{
    typedef GraphLoader graph;
    typedef pair<double,bool> T;
private:
    
public:
    bool is_strongly_connected();
    void set_tag(int u,int v,bool sign);
    bool get_tag(int u,int v);
    int degree(int u);
    virtual void EulerCycuit();

};
bool graph::get_tag(int u,int v){
    pair<double,bool> element=G_M(u,v);
    return get<1>(element);
}
void set_tag(int u,int v,bool sign){
    pair<double,bool> element=make_pair(G_M(u,v),sign);
    G_M(u,v)=element;
}
#include "GraphAlgorithms.h"