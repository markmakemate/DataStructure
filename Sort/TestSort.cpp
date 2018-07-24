#include<iostream>
#include "Sort.h"
using namespace std;
int main(){
	int A[10]={12,3,4,7,1,99,8,77,0,-1};
	int* T=A;
        int SIZE=10;
	Sort<int> S(T,SIZE);
	S.ShowQuickSort();
	return 0;
}
