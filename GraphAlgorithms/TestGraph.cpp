#include<iostream>
#include"Graph.h"
#include<vector>
using namespace std;
void PrintShortestPath(int* a);
int main(){
  int A[8][3]={{0,1,5},{0,2,4},{1,3,6},{2,1,1},{2,4,3},{3,4,2},{3,5,7},{4,5,7}};
  int** T;
  int SIZE=sizeof(*A)/sizeof(**A);
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<3;j++){
      *(*(T+i)+j)=A[i][j];
    }
  }
  Graph<int> G(T,SIZE,"DIRECTED");
  int* DijkstraSeries=G.Dijkstra(0);
  PrintShortestPath(DijkstraSeries);
  return 0;
}
void PrintShortestPath(int* a){
  int length=sizeof(a)/sizeof(*a);
  cout<<"The shortest path is:";
  for(int i=0;i<length;i++){
    cout<<*(a+i)<<", ";
  }
  cout<<"\n";
}    
