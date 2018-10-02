#ifndef ELEMENT_H
#define ELEMENT_H
#include<iostream>

using namespace std;
template<class type_name>
class Element{
public:
    ElementProcessor();
    ElementProcessor(int index_row,int index_col) const;
    int row_index;
    int col_index;
    type_name value;
};
#endif