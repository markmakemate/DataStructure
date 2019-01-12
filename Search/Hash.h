#ifndef HASH_H
#define HASH_H
#include<iostream>
#include "../LinkList/LinkList.h"
#include<cstdlib>
#include "HashProcessor.h"
using namespace std;
//Key-Value Hash Table structure
template<class key_type,class value_type>
struct Unit{
	key_type Key;
	value_type Value;
	Unit(key_type x,value_type y):Key(x),Value(y){}
	Unit operator{}(key_type key,value_typ value){
		Key=key;
		Value=value;
	}
};
template<class key_type,class value_type>
class Hash{
	typedef Unit<key_type,value_type> unit;
private:
    Unit<key_type,Single<value_type> > chain;
	unit hash;
protected:
    void OpenAddressing();
	void Chaining();
public:
	Hash();
	
};
