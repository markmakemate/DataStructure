#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
	vector<int>* V=new vector<int>(10);
	V->insert(V->begin()+4,5);
	V->erase(V->begin()+5);
	cout<<V->at(4)<<endl;
	cout<<V->size();
	return 0;
}
