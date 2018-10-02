#include<iostream>
#include<blitz/array.h>
using namespace std;
using namespace blitz;
int main(){
    int B[4]={1,2,3,4};
    Array<int,1> A(2);
    Array<int,2> T(B,shape(2,2));
    A(Range::all())=-1;
    cout<<A(1);
    return 0;
}
