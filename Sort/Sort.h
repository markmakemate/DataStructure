#ifndef SORT_H
#define SORT_H
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
template<class Elemtype>
class Heap{
	private:
		Elemtype* heap;
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
		Heap(){
			heap=NULL;
			MAXSIZE=0;
		}
		Elemtype* Swap(Elemtype* A,int begin,int end){
			Elemtype temp=*(A+begin);
	        *(A+begin)=*(A+end);
	        *(A+end)=temp;
	        return A;
		}   //swap two elements in a series

		Elemtype* BuildMaxHeap(Elemtype* A,int SIZE){
			int L,R;
			MAXSIZE=SIZE;
			heap=new Elemtype[MAXSIZE];
			heap=A;
			for(int i=floor(MAXSIZE/2);i>=0;i--){
				L=LeftChild(i);
				R=RightChild(i);
				if(*(heap+i)<*(heap+L)){
					heap=Swap(heap,i,L);
				}
				if(*(heap+i)<*(heap+R)){
					heap=Swap(heap,i,R);
				}
				if(*(heap+L)>*(heap+R)){
					heap=Swap(heap,L,R);
				}
			}
			return heap;
		}    //Build a max heap

		Elemtype* BuildMinHeap(Elemtype* A,int SIZE){
			int L,R;
			MAXSIZE=SIZE;
			heap=new Elemtype[MAXSIZE];
			heap=A;
			for(int i=floor(MAXSIZE/2);i>=0;i--){
				L=LeftChild(i);
				R=RightChild(i);
				if(*(heap+i)>*(heap+L)){
					heap=Swap(heap,i,L);
				}
				if(*(heap+i)>*(heap+R)){
					heap=Swap(heap,i,R);
				}
				if(*(heap+L)>*(heap+R)){
					heap=Swap(heap,L,R);
				}
	    		}
	  		return heap;
                }   //Build a min heap
    
};    //Declaration of heap class

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

template<class Elemtype>
Elemtype* Sort<Elemtype>::HeapSort(Elemtype* A,int SIZE){
typedef Elemtype* Row;
        Elemtype* T=A;
        SIZE=MAXSIZE-1;
        Heap<Elemtype> H;
        Row temp=H.BuildMaxHeap(T,MAXSIZE);
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
