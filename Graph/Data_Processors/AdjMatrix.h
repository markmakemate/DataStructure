#include<iostream>
#include<cstdlib>
#include<map>
#include "../Linear_Algebra/Matrix.h"
#include "GraphLoader.h"
#define INF 1.7976931348623e+308
//Adjacent Matrix class
template<class T>
class AdjMatrix{
private:
    Matrix<T> AM;
public:
    AdjMatrix(GraphLoader& Input);
    void load(GraphLoader& Input);
    void initial();  //Set all elements as INF
    T operator()(int start,int end){
        T result;
        if(AM!=NULL){
            result = AM[start][end];
        }
        else{
            throw "Adjacent Matrix has not been built"
        }
        return result;
    }  //Override operator(). Get the weight between start_vertex and end_vertex
    map<int,T> operator[](int vertex){
        return AM[vertex];
    }  //Override operator[]. Get the row vertex of adjacent matrix
    int size(){
        return AM.raws();
    }
};
template<class T>
void AdjMatrix<T>::AdjMatrix(GraphLoader& Input){

}
template<class T>
void AdjMatrix<T>::initial(){
    typedef map<int,map<int,T> > matrix;
    int N=(*this).size();
    T elem;
    AM.clear();
    matrix candidate;
    map<int,T> raw;
    for(int u=0;u<N;u++){
        for(int v=0;v<N;v++){
            elem=make_pair(INF,false);
            raw.insert(v,elem);
        }
        candidate.insert(u,raw);
    }
    AM.load(candidate);
}