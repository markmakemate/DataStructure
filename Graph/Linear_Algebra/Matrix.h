#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
#include"Vector.h"
#include"Element.h"
using namespace std;
namespace Linear_Algebra
{
template<class type_name>
class Matrix:public Element<type_name>{
    typedef map<int,vector<type_name> > Row;
    typedef map<int,vector<type_name> > Col;
    typedef map<int,vector<type_name> > container;
	typedef container matrix;   //First element is row set, second is column set
    typedef MatrixBase<type_name> MatrixXt;
    typedef vector<type_name> input_model;
public:
    int rows;
	int cols;
    matrix Data;
    list<matrix > DataLoader;
    Element<type_name> element;
    Matrix();
    Matrix(int row,int col);
    Matrix(input_model Input);
    int rows();
    int cols();
    type_name operator()(int& i,int& j);
	virtual MatrixXt operator * (MatrixXt& A,MatrixXt& B) const;
	virtual MatrixXt operator + (MatrixXt& A,MatrixXt& B) const;
    void operator = (type_name& value,type_name& target) const;
    virtual void transposition();
};
template<class type_name>
Matrix::Matrix(){
    rows=0;
    cols=0;
}
template<class type_name>
Matrix::Matrix(int row,int col){
    rows=row;
    cols=col;
}
template<class type_name>
Matrix::Matrix(vector<type_name>* Input) const{
    typedef map<int,vector<type_name> > Row;
    typedef map<int,vector<type_name> > Col;
	rows=sizeof(Input);
    cols=(*Input).size();
    Row row;
    Col col;
    int sign=0;
    vector<type_name> candidate;
    list<map<int,vector<type_name> > >::iterator it=DataLoader.begin();
    for(int i=0;i<rows;i++){
        row.push(make_pair(sign,Input[sign]));
    }
    while(sign<cols){
        for(int i=0;i<rows;i++){
            candidate.push_back((*(Input+i)).at(sign));
        }
        col.push(make_pair(sign,candidate));
        candidate.clear();
        sign++;
    }
    Data=row;
    *it=row;
    *(it+1)=col;
    row.clear();
    col.clear();
    delete it;
}


template<class type_name>
void Matrix<type_name>::operator = (type_name& value,type_name& target) const{
    element.value=target;
    map<int,vector<type_name> >::iterator it=Data.begin();
    (*(it+element.row_index)).second=target;
    delete it;
}
template<class type_name>
int Matrix<type_name>::rows(){
    this->rows=Data.size();
    return this->rows;
}
template<class type_name>
int Matrix<type_name>::cols(){
    this->cols=(*(DataLoader.begin()+1)).size();
    return this->cols;
}



//Subclass
template<class type_name>
class MatrixBase:public Matrix<type_name>,public Vector<type_name>{
    typedef map<int,vector<type_name> > Row;
    typedef map<int,vector<type_name> > Col;
    typedef map<int,vector<type_name> > container;
	typedef container matrix;   //First element is row set, second is column set
    typedef Matrix<type_name> MatrixXt;
    typedef vector<type_name> input_model;
    MatrixXt operator * (MatrixXt& A,MatrixXt& B) const;
    MatrixXt operator + (MatrixXt& A,MatrixXt& B) const;
    
};
template<class type_name>
type_name MatrixBase<type_name>::operator()(int& i,int& j){
    vector<type_name> candidate=this->Data.at(i);
    return candidate.at(j);
    
}
template<class type_name>
Matrix<type_name> MatrixBase<type_name>::operator * (Matrix<type_name>& A,Matrix<type_name>& B) const{
    Matrix<type_name> result(A.rows(),B.cols());
    vector<type_name> candidate;
    if(A.cols()==B.rows()){
        B.transposition();
        for(int i=0;i<A.rows();i++){
            for(int j=0;j<B.rows();j++){
                candidate.push(A.Data.at(i)*B.Data.at(j));
            }
            result.Data.push(make_pair(i,candidate));
            candidate.clear();
        }
    }
    else{
        throw "The first matrix's column number should be equal to second's row number!";
    }
    return result;
}
template<class type_name>
Matrix<type_name> Matrix<type_name>::operator + (Matrix<type_name>& A,Matrix<type_name>& B) const{
    Matrix<type_name> result;
    if(A.rows()==B.rows()&&A.cols()==B.cols()){
        for(int i=0;i<A.rows();i++){
            result.Data.push(make_pair(i,A.Data.at(i)+B.Data.at(i)));
        }
    }
    else{
        throw "Two matrixs' rows and cols should be the same!";
    }
    return result;
}
void MatrixBase<type_name>::transposition(){
    list<map<int,vector<type_name> > >::iterator temp=this->DataLoader.begin();
    list<map<int,vector<type_name> > >::iterator it=this->DataLoader.begin();
    *it=*(it+1);
    *(it+1)=*temp;
    Data=*it;
    int t=this->rows;
    this->rows=this->cols;
    this->cols=t;
    delete it;
    delete temp;
}
//Space-time Trade-off
}
#endif