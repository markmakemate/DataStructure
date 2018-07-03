#ifndef HEAP_H
#define HEAP_H
template<class Elemtype>
class Heap{
	private:
		Elemtype* Heap;
	public:
		Heap(Elemtype* A);
		void BulidMaxHeap();
		void BuildMinHeap();
		
};
