#include<cstdlib>
#include<iostream>
#include "Union_Find.h"
using namespace std;
template<class T>
class DisjointSet{
private:
    Set<T>* sets;
public:
    void Make_Sets(T* values);
    void Union()
};