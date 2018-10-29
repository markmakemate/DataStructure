#include<iostream>
#include<cstdlib>
#include<map>
#include "List.h"
#include "GraphLoader.h"
//Graph Container: Adjacent List & Adjacent Matrix
//Graph Container namespace definition
//Adjacent List class
//build: build an adjacent list, an GraphLoader object as the parameter
class AdjList{
    typedef map<int,List<double> > adjlist;
public:
    adjlist AL;
    void build(const GraphLoader& Input);
    List<double> operator[](int vertex){
        return AL[vertex];
    } //Override operator []. Get the adjacent list of vertex.
	double operator(int& start_vertex,int& end_vertex){
		return AL[start_vertex][end_vertex];
	} //Override operator (). Get the weight between start_vertex and end_vertex
};
void AdjList::build(const GraphLoader& Input){
    map<int,map<int,double> > single;
	map<int,map<int,double> >::iterator it;
	List<double> list;
    for(it=Input.begin();it!=Input.end();++it){
		single.emplace(it->first,it->second);
		list.build(single);
		AL.emplace(it->first,list);
		single.clear();
		list.clear();
    }
}