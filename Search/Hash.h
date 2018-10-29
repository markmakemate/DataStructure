#ifndef HASH_H
#define HASH_H
#include<iostream>
#include "../LinkList/LinkList.h"
#include<cstdlib>
#include "HashProcessor.h"
using namespace std;
//Key-Value Hash Table structure
template<class key_type,class value_type>
struct HashTable{
	key_type Key;
	value_type Value;
	HashTable(key_type x,value_type y):Key(x),Value(y){}
	HashTable<key_type,value_type> operator{}(key_type key,value_typ value){
		Key=key;
		Value=value;
	}
};
template<class key_type,class value_type>
class Hash{
	typedef HashTable<key_type,value_type> unit;
private:
    HashTable<key_type,Single<value_type> > chain;
	unit hash;
protected:
    void OpenAddressing();
	void Chaining();
public:
	Hash();
	virtual operator=(Hash<key_type,value_type> hash,Collection<key_type,value_type> collection);

};
template<class key_type,class value_type>
class Collection{
	
};