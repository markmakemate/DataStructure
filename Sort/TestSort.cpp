#include<iostream>
#include "Sort.h"
using namespace std;
void ShowSort(int* Q);
void Swap(int* A,int i,int j);
int main(){
	int A[10]={12,3,4,7,1,99,8,77,0,-1};
	int* T=new int[10];
        int SIZE=10;
        int* Q=new int[10];
    for(int i=0;i<SIZE;i++){
    	*(T+i)=A[i];
	}
	Sort<int> S(T,SIZE);
	Heap<int> H;
	Q=S.QuickSort(T,1,10);
	ShowSort(Q);
	Q=S.InsertSort();
	ShowSort(Q);
	return 0;
}
void ShowSort(int* Q){
    for(int i=0;i<10;i++){
       cout<<*(Q+i)<<", ";
    }
    cout<<endl;
}
void Swap(int* A,int begin,int end){
			int temp=*(A+begin);
	        *(A+begin)=*(A+end);
	        *(A+end)=temp;
		}   //swap two elements in a series
