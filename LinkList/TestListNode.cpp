#include<iostream>
#include<cstdlib>
#include"LinkList.h"
using namespace std;
int main(){
	int A[3]={2,8};
	int B[10]={1,68,3,4,5,6,7,90,9,20};
	LinkList<int> L(A,3);
	LinkList<int> P(B,10);
	L.PrintLots(L.BuildLinkList(),P.BuildLinkList());
	return 0;
}
