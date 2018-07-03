#include<iostream>
#include<vector>
#include "LinkList.h"
using namespace std;
int main(){
	int L[4]={2,4,5,6};
	int P[7]={1,2,3,4,5,6,7};
	vector<int> l(L,L+4);vector<int> p(P,P+7);
	LinkList<int> Temp1(l);
	LinkList<int> Temp2(p);
	Temp1.PrintLots(Temp1.BuildLinkList(),Temp2.BuildLinkList());
	return 0;
}
