#ifndef SORT_H
#define SORT_H
#include<iostream>
#include<cstdlib>
#include<cmath>
#include "Heap.h"
using namespace std;
template<class Elemtype>
class Sort:public Heap<Elemtype>{
	private:
		int MAXSIZE;
		int partition;
	public:
		Sort();
    Elemtype* InsertSort(Elemtype* A,int SIZE);
		Elemtype* ShellSort(Elemtype* A,int SIZE,Elemtype* ShellNum);
		Elemtype* QuickSort(Elemtype* A,int p,int r);
		Elemtype* BubbleSort(Elemtype* A,int SIZE);
		Elemtype* HeapSort(Elemtype* A,int SIZE);
		Elemtype* Partition(Elemtype* A,int p,int r);
};    //Declaration of Sort class, inhabiting class Heap;

template<class Elemtype>
Sort<Elemtype>::Sort(){
	MAXSIZE=0;
}    //Constructor

    //

template<class Elemtype>
Elemtype* Sort<Elemtype>::InsertSort(Elemtype* A,int SIZE){
  Elemtype* T=A;
  int count=1;
  for(int i=0;i<MAXSIZE;i++){
    for(int j=0;j<count;j++){
      if(*(T+j)>*(T+i)){
        T=this->Swap(T,j,i);
      }
    }
    count++;
  }
  return T;
}   //Insert sort
    

template<class Elemtype>
Elemtype* Sort<Elemtype>::BubbleSort(Elemtype* A,int SIZE){
	for(int i=0;i<SIZE;i++){
		for(int j=i;j<SIZE;j++){
			if()
		}
	}
}    //Bubble Sort
  
template<class Elemtype>
Elemtype* Sort<Elemtype>::ShellSort(Elemtype* A,int SIZE,Elemtype* ShellNum){
	int COUNT=sizeof(ShellNum)/sizeof(*ShellNum);
	Elemtype* T=A;
	int shellnum;
	for(int i=0;i<COUNT;i++){		
		shellnum=*(ShellNum+i);
		if(shellnum<MAXSIZE){
			for(int j=0;j<MAXSIZE-*(ShellNum+i);j++){
			   if(*(T+j)>*(T+j+shellnum)){
				 T=this-> Swap(T,j,j+shellnum);
			    }
		    }
	    }
		else{throw "ERROR,OUT OF RANGE!";break;} 
    }
    return T;
}    //Shell Sort

template<class Elemtype>
Elemtype* Sort<Elemtype>::QuickSort(Elemtype* A,int p,int r){
	Elemtype* T=A;
	if(p<r){
	    A=Partition(A,p,r);
	    A=QuickSort(A,p,partition);
	    A=QuickSort(A,partition+1,r);
    }
    return A;
}   //Quick Sort

template<class Elemtype>
Elemtype* Sort<Elemtype>::Partition(Elemtype* A,int p,int r){
	r=r-1;
	p=p-1;
	Elemtype x=*(A+r);
	partition=p-1;
	for(int j=p;j<=r;j++){
	  if(*(A+j)<=x){
	      partition++;
	      A=this->Swap(A,partition,j);
	  }
	}
	A=this->Swap(A,partition+1,r);
	return A;
}    //Partition


#endif
