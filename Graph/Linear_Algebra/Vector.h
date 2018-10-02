#ifndef VECTOR_H
#define VECTOR_H
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;
template<class type_name>
class Vector{
public:
    type_name operator * (vector<type_name>& A,vector<type_name>& B);
    vector<type_name> operator * (float& parama,vector<type_name>& B);
    vector<type_name> operator * (vector<type_name>& A,float& parama);
    vector<type_name> operator + (vector<type_name>& A,vector<type_name>& B);
};
template<class type_name>
type_name Vector<type_name>::operator * (vector<type_name>& A,vector<type_name>& B){
    dimension_A=A.size();
    dimension_B=B.size();
    type_name result=0;
    if(dimesion_A==dimension_B){
        for(int i=0;i<dimension_A;i++){
            result+=A.at(i)*B.at(i);
        }
    }
    else{
        throw "Two vectors should have a same dimension!";
    }
    return result;
}
template<class type_name>
vector<type_name> Vector<type_name>::operator * (float& paramas,vector<type_name>& B){
    vector<type_name>::iterator it;
    for(it=B.begin();it!=B.end();++it){
        *it=(*it)*paramas;
    }
    return B;
}
template<class type_name>
vector<type_name> Vector<type_name>::operator * (vector<type_name>& A,float& paramas){
    vector<type_name>::iterator it;
    for(it=A.begin();it!=A.end();++it){
        *it=(*it)*paramas;
    }
    return A;
}
template<class type_name>
vector<type_name> Vector<type_name>::operator + (vector<type_name>& A,vector<type_name>& B){
    vector<type_name> result;
    vector<type_name>::iterator it_1;
    vector<type_name>::iterator it2=B.begin();
    if(A.size()==B.size()){
        for(it_1=A.begin();it_1!=A.end();++it_1){
            result.push_back((*it_1)*(*it_2));
        }
        ++it_2;
    }
    else{
        throw "The vectors' dimensions should be the same!";
    }
    return result;
}
#endif