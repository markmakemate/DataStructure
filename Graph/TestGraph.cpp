#include<iostream>
#include"Graph.h"
#include"GraphAlgorithms.h"
#include<cstdlib>
using namespace std;
int main(){
  int A[8][3]={{0,1,5},{0,2,4},{1,3,6},{2,1,1},{2,4,3},{3,4,2},{3,5,7},{4,5,7}};
  int** S=new int*[3];
  for (int i = 0; i < 8; i++) {
	  *(S + i) = A[i];
  }
  cout<<*(S+1)[3]<<endl;
  Graph<int> g(6);
  g.BuildGraph(S, 8);
  Print(g,2);
  return 0;
}
