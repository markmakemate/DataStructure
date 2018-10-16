#include<cstdlib>
#include<iostream>
using namespace std;
template<class elementype>
struct SingleListNode{
	elementype data;
	SingleListNode* next;
	SingleListNode(elementype x):data(x),next(NULL){}
	SingleListNode* operator + (int position);
	void operator ++ (){
		this=next;
	}
};
template<class elementype>
SingleListNode<elementype>* SingleListNode<elementype>::operator + (int position){
	SingleListNode<elementype>* p=next;
	for(int i=1;i<position;i++){
		p=p->next;
	}
	return p;
}