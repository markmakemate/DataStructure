#ifndef SORT_H
#define SORT_H
#include<iostream>
#include<cstdlib>
using namespace std;
template<class Elemtype>
class Sort{
	private:
		Elemtype* SortingArray;
		int MAXSIZE;
	public:
		Sort(Elemtype* A);
		void ShellSort(Elemtype* ShellNum);
		void QuickSort(Elemtype* A,int p,int r);
		void BubbleSort();
		void HeapSort();
		void Swap(Elemtype a,Elemtype b);
		void ShowQuickSort();
		int Partition(Elemtype* A,int p,int r);
};
template<class Elemtype>
Sort<Elemtype>::Sort(Elemtype* A){
	MAXSIZE=sizeof(A)/sizeof(*A);
	SortingArray=new Elemtype[MAXSIZE];
	SortingArray=A;
}
template<class Elemtype>
void Sort<Elemtype>::ShellSort(Elemtype* ShellNum){
	int COUNT=sizeof(ShellNum)/sizeof(*ShellNum);
	Elemtype* T=SortingArray;
	int shellnum;
	for(int i=0;i<COUNT;i++){		
		shellnum=*(ShellNum+i);
		if(shellnum<MAXSIZE){
			for(int j=0;j<MAXSIZE-*(ShellNum+i);j++){
			   if(*(T+j)>*(T+j+shellnum)){
				  Swap(*(T+j),*(T+j+shellnum));
			    }
		    }
	    }
		else{throw "ERROR,OUT OF RANGE!";break;} 
    }
}
template<class Elemtype>
void Sort<Elemtype>::QuickSort(Elemtype* A,int p,int r){
	if(p<r){
		int q=Partition(A,p,r);
	    QuickSort(A,p,q-1);
	    QuickSort(A,q+1,r);
    }
}
template<class Elemtype>
void Sort<Elemtype>::ShowQuickSort(){
	QuickSort(SortingArray,1,MAXSIZE);
	Elemtype* T=SortingArray;
	for(int i=0;i<MAXSIZE;i++){
		cout<<*(T+i)<<" ";
	}
}
template<class Elemtype>
int Sort<Elemtype>::Partition(Elemtype* A,int p,int r){
	r=r-1;
	p=p-1;
	Elemtype x=*(A+r);
	int i=p-1;
	for(int j=p;j<=r;j++){
		if(*(A+j)<=x){
			i++;
			Swap(*(A+i),*(A+j));
		}
	}
	i=i+1;
	Swap(*(A+i),*(A+r));
	return i+1;
}
template<class Elemtype>
void Sort<Elemtype>::Swap(Elemtype a,Elemtype b){
	Elemtype temp;
	temp=a;
	a=b;
	b=temp;
}
#endif
