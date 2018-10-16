#include<cstdlib>
#include<iostream>
#include<string>
#include<iterator>
using namespace std;
template<class elementype>
class LinkList{
	public:
		virtual void push();
		virtual void pop();
		virtual void erase();
		virtual void insert();
		virtual void build();
		virtual bool IsEmpty();
		virtual void* begin();
		virtual void* end();
		virtual int size();
};
#include "SingleLinkList.h"
#include "DoubleLinkList.h"