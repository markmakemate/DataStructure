#include<iostream>
#include<cstdlib>
#include<map>
#include "GraphLoader.h"
//Adjacent Matrix class
class AdjMatrix{
    typedef map<int,map<int,double> > adjmatrix;
public:
    adjmatrix AM;
    AdjMatrix();
    void build(GraphLoader& Input);
    void initial();  //Set all elements as INF
    double operator()(int start,int end){
        double result;
        if(AM!=NULL){
            result = AM[start][end];
        }
        else{
            throw "Adjacent Matrix has not been built"
        }
        return result;
    }  //Override operator(). Get the weight between start_vertex and end_vertex
    map<int,double> operator[](int vertex){
        return AM[vertex];
    }  //Override operator[]. Get the row vertex of adjacent matrix
};
void AdjMatrix::AdjMatrix(){
    AM=NULL;
}
void AdjMatrix::initial(){
    AM=
}