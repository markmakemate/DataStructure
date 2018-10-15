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
    double operator()(int start,int end){
        double result;
		if(AL!=NULL){
			List<double> candidate=AL[start];
			Node<double> p=(candidate.head)->next;
			while(p!=NULL){
				if(p->vertex!=end){
					p=p->next;
				}
				else{
					result=p->vertex;
				}
			}
			if(p==NULL){
				throw "No end vertex!";
			}
		}
        else{
            throw "Adjacent list has not been built!";
        }
        return result;
    }//Override operator (). Get the weight between start_vertex and end_vertex
    List<double> operator[](int vertex){
        return AL[vertex];
    } //Override operator []. Get the adjacent list of vertex. 
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