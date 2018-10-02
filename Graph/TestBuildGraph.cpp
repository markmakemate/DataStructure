#include"Preperation.h"
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
class Test : public LinkList<int>{
	typedef vector<AdjacentListNode<int>*>* IntVector;
public:
	IntVector BuildAdjList(int* A[3], int SIZE) {
		typedef AdjacentListNode<int>* List;
		typedef AdjacentListNode<int> Node;
		IntVector result=new vector<List>(SIZE,NULL);
		List candidate;
		List node;
		List mid;
		int* S = new int[3];
		for (int i = 0; i < SIZE; i++) {
			int position = *(A + i)[0];
			S = *(A + i);
			if (result->at(position) == NULL) {
				candidate = this->BuildLinkList(S);
				result->insert(result->begin() + position, candidate);
				result->erase(result->begin() + position+1);
			}
			else {
				int position1 = S[1];
				int ref = S[2];
				node = new Node(ref,position1);
				mid = result->at(position);
				mid = this->InsertListNode(mid, node);
				result->insert(result->begin() + position, mid);
				result->erase(result->begin() + position+1);
			}
		}
		result->resize(2);
		return result;
	}
};
int main() {
	typedef vector<AdjacentListNode<int>*>* IntVector;
	LinkList<int> L;
	Test T;
	IntVector V;
	int A[2][3] = { {0,1,3},{0,2,4} };
	int* S[3];
	for (int i = 0; i < 2; i++) {
		*(S + i) = A[i];
	}
	V=T.BuildAdjList(S, 2);
	int N = L.Num_of_List(V->at(0));
	cout << N;
	return 0;
}

