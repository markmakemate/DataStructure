#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
bool sign=false;
int size;

int check(void* data){
    
}
bool check(void* data){
    int size=sizeof(data)/sizeof(*data);
    for(int i=0;i<size;i++){
        if(*(data+i))
    }
}//check out whether data is sorted
template<class T>
bool Binary_Search(T value,int begin,int end,T* data=NULL){
    if(data!=NULL&&check(data)==true){
        int p=begin+(end-begin)/2;
        sign=false;
        if(value==*(data+p)){
            sign=true;
        }
        else{
            if(check(data)=1){
                if(value<*(data+p)){
                    sign=Binary_Search(value,begin,p-1,data);
                }
                else{
                    sign=Binary_Search(value,p+1,end,data);
                }
            }
            else{
                if(value>*(data+p)){
                    sign=Binary_Search(value,begin,p-1,data);
                }
                else{
                    sign=Binary_Search(value,p+1,end,data);
                }
            }
            
        }
    }
    else if(!check(data)){
        throw "the input series is not sorted! Please sort it first.";
    }
    return sign;
}
template<class T>
//Override Binary Search
bool Binary_Search(T value,int begin,int end,T* data){
    try{
        sign=Binary_Search(value,begin,end,data);
    }
    catch(string& s){
        cout<<s;
    }
    return sign;
}