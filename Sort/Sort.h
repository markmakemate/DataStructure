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
		}
		int LeftChild(int position){
			return 2*position+1;
		}
		int RightChild(int position){
			return 2*position+2;
		}
	protected:
		void Swap(Elemtype a,Elemtype b){
			Elemtype temp;
	        temp=a;
	        a=b;
	        b=temp;
		}
		Elemtype* BuildMaxHeap(Elemtype* A,int SIZE){
			int L,R;
			MAXSIZE=SIZE;
			Heap=new Elemtype[MAXSIZE];
			Heap=A;
			for(int i=floor(MAXSIZE/2);i>=0;i--){
				L=LeftChild(i);
				R=RightChild(i);
				if(*(Heap+i)<*(Heap+L)){
					Swap(*(Heap+i),*(Heap+L));
				}
				if(*(Heap+i)<*(Heap+R)){
					Swap(*(Heap+i),*(Heap+R));
				}
				if(*(Heap+L)>*(Heap+R)){
					Swap(*(Heap+L),*(Heap+R));
				}
			}
			return Heap;
		}
		Elemtype* BuildMinHeap(Elemtype* A,int SIZE){
			int L,R;
			MAXSIZE=SIZE;
			Heap=new Elemtype[MAXSIZE];
			Heap=A;
			for(int i=floor(MAXSIZE/2);i>=0;i--){
				L=LeftChild(i);
				R=RightChild(i);
				if(*(Heap+i)>*(Heap+L)){
					Swap(*(Heap+i),*(Heap+L));
				}
				if(*(Heap+i)>*(Heap+R)){
					Swap(*(Heap+i)>*(Heap+R));
				}
				if(*(Heap+L)>*(Heap+R)){
					Swap(*(Heap+L),*(Heap+R));
				}
	    		}
	  		return Heap;
                }     
};
template<class Elemtype>
class Sort:protected Heap<Elemtype>{
	private:
		Elemtype* SortingArray;
		int MAXSIZE;
	public:
		Sort(Elemtype* A,int SIZE);
                ~Sort();
		void ShellSort(Elemtype* ShellNum);
		Elemtype* QuickSort(Elemtype* A,int p,int r);
		void BubbleSort();
		Elemtype* HeapSort();
		Elemtype* ShowQuickSort();
                Elemtype* ShowBubbleSort();
		int Partition(Elemtype* A,int p,int r);
};
template<class Elemtype>
Sort<Elemtype>::Sort(Elemtype* A,int SIZE){
	MAXSIZE=SIZE;
	SortingArray=new Elemtype[MAXSIZE];
	SortingArray=A;
}

template<class Elemtype>
Sort<Elemtype>::~Sort(){
  delete[] SortingArray;
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
				 this-> Swap(*(T+j),*(T+j+shellnum));
			    }
		    }
	    }
		else{throw "ERROR,OUT OF RANGE!";break;} 
    }
}

template<class Elemtype>
Elemtype* Sort<Elemtype>::QuickSort(Elemtype* A,int p,int r){
	if(p<r){
	    int q=Partition(A,p,r);
	    QuickSort(A,p,q-1);
	    QuickSort(A,q+1,r);
    }
    return A;
}
template<class Elemtype>
Elemtype* Sort<Elemtype>::ShowQuickSort(){
	QuickSort(SortingArray,1,MAXSIZE);
	Elemtype* T=SortingArray;
	return T;
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
	      this->Swap(*(A+i),*(A+j));
	  }
	}
	i=i+1;
	this->Swap(*(A+i),*(A+r));
	return i+1;
}

template<class Elemtype>
Elemtype* Sort<Elemtype>::HeapSort(){
typedef Elemtype* Row;
        int SIZE=MAXSIZE-1;
        Heap<Elemtype> H;
        Row temp=H.BuildMaxHeap(SortingArray,MAXSIZE);
        Row result=new Row[MAXSIZE];
        while(SIZE>0){
                *(result+SIZE)=*temp;
                H.Swap(*(temp+SIZE),*temp);
                SIZE--;
                H.BuildMaxHeap(temp,SIZE);
        }
        *result=*temp;
        delete[] temp;
        return result;
}
#endif
