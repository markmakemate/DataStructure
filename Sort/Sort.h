#ifndef SORT_H
#define SORT_H
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
template<class Elemtype>
class Heap{
	private:
		Elemtype* Heap;
		int MAXSIZE;
		int Parent(int position){
			return floor(position/2);
		}   //Parent
		int LeftChild(int position){
			return 2*position+1;
		}   //Left child
		int RightChild(int position){
			return 2*position+2;
		}   //Right child
	public:
		Elemtype* Swap(Elemtype* A,int begin,int end){
			Elemtype temp=*(A+begin);
	        *(A+begin)=*(A+end);
	        *(A+end)=temp;
	        return A;
		}   //swap two elements in a series

		Elemtype* BuildMaxHeap(Elemtype* A,int SIZE){
			int L,R;
			MAXSIZE=SIZE;
			Heap=new Elemtype[MAXSIZE];
			Heap=A;
			for(int i=floor(MAXSIZE/2);i>=0;i--){
				L=LeftChild(i);
				R=RightChild(i);
				if(*(Heap+i)<*(Heap+L)){
					Heap=Swap(Heap,i,L);
				}
				if(*(Heap+i)<*(Heap+R)){
					Heap=Swap(Heap,i,R);
				}
				if(*(Heap+L)>*(Heap+R)){
					Heap=Swap(Heap,L,R);
				}
			}
			return Heap;
		}    //Build a max heap

		Elemtype* BuildMinHeap(Elemtype* A,int SIZE){
			int L,R;
			MAXSIZE=SIZE;
			Heap=new Elemtype[MAXSIZE];
			Heap=A;
			for(int i=floor(MAXSIZE/2);i>=0;i--){
				L=LeftChild(i);
				R=RightChild(i);
				if(*(Heap+i)>*(Heap+L)){
					Heap=Swap(Heap,i,L);
				}
				if(*(Heap+i)>*(Heap+R)){
					Heap=Swap(Heap,i,R);
				}
				if(*(Heap+L)>*(Heap+R)){
					Heap=Swap(Heap,L,R);
				}
	    		}
	  		return Heap;
                }   //Build a min heap
    
};    //Declaration of heap class

template<class Elemtype>
class Sort:public Heap<Elemtype>{
	private:
		Elemtype* SortingArray;
		int MAXSIZE;
		int partition;
	public:
		Sort(Elemtype* A,int SIZE);
                ~Sort();
                Elemtype* InsertSort();
		Elemtype* ShellSort(Elemtype* ShellNum);
		Elemtype* QuickSort(Elemtype* A,int p,int r);
		Elemtype* BubbleSort();
		Elemtype* HeapSort();
		Elemtype* Partition(Elemtype* A,int p,int r);
};    //Declaration of Sort class, inhabiting class Heap;

template<class Elemtype>
Sort<Elemtype>::Sort(Elemtype* A,int SIZE){
	MAXSIZE=SIZE;
	SortingArray=new Elemtype[MAXSIZE];
	SortingArray=A;
}    //Constructor

template<class Elemtype>
Sort<Elemtype>::~Sort(){
  delete[] SortingArray;
}    //

template<class Elemtype>
Elemtype* Sort<Elemtype>::InsertSort(){
  Elemtype* T=SortingArray;
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
Elemtype* Sort<Elemtype>::BubbleSort(){
}    //Bubble Sort
  
template<class Elemtype>
Elemtype* Sort<Elemtype>::ShellSort(Elemtype* ShellNum){
	int COUNT=sizeof(ShellNum)/sizeof(*ShellNum);
	Elemtype* T=SortingArray;
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

template<class Elemtype>
Elemtype* Sort<Elemtype>::HeapSort(){
typedef Elemtype* Row;
        int SIZE=MAXSIZE-1;
        Heap<Elemtype> H;
        Row temp=H.BuildMaxHeap(SortingArray,MAXSIZE);
        Row result=new Elemtype[MAXSIZE];
        while(SIZE>0){
                *(result+SIZE)=*temp;
                temp=H.Swap(temp,SIZE,0);
                SIZE--;
                temp=H.BuildMaxHeap(temp,SIZE);
        }
        *result=*temp;
        return result;
}    //Heap Sort
#endif
