//It is assume to be restricted in dense graph
//Generic Programming
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
template<class Elemtype>
struct AdjacentListNode{
       Elemtype data;
       int Vertex;
       string sign;
       AdjacentListNode* next;
       AdjacentListNode(Elemtype x,int v):data(x),Vertex(v),sign("UNVISITED"),next(NULL){}
};   //declaration of Linklist node

template<class Elemtype>
class LinkList{
typedef AdjacentListNode<Elemtype>* Node;
typedef AdjacentListNode<Elemtype> ListNode;
typedef Elemtype* Row;
      private:
              Node head;
      public:
              void InsertListNode(Node head,Elemtype A,Node node){
                  Node p;
                  p=head;
                  while(p!=NULL){
                     p=p->next;
                  }
                  p=node;
              }   //Insert a node
              
              Node BuildLinkList(Elemtype* A){
                Node p,q;
                p=new ListNode(0,(int)*A);
                q=new ListNode(*(A+2),(int)*(A+1));
                p->next=q;
                return p;
              }   //Build a list
              
              int Num_of_List(Node r){
                   Node p=r;
                   int count=1;
                   while(p->next!=NULL){
                         count++;
                   }
                   return count;
              }   //Number of list nodes
              
              bool IsExist(Node A,int u){
              	Node p=A;
              	bool sign=false;
              	while(p!=NULL){
              		if(p->Vertex!=u){p=p->next;}
              		else{sign=true;break;}
				  }
				  return sign;
			  }
              bool IsExist(vector<Row> A,int u);
};   //declaration of Linklist class

template<class Elemtype>
class Graph:LinkList<Elemtype>{
typedef AdjacentListNode<Elemtype>* Node;
typedef Elemtype* Row;
typedef vector<Node> AdjList;
typedef vector<Row> AdjMatrix;
      private:
              AdjList ADJ_LIST;   //Store Adjacent list
              int NUM_VERTEX;    //Number of vertexs
              AdjMatrix ADJ_MATRIX;   //Store of Adjacent matrix      
      public:
              Graph(Elemtype* A[3],int SIZE,string DISCRIBE);   //Constructor
              void DFT(int u);      //Depth-First Traversal
              void BFT(int u);      //Breath-First Traversal
              Row Dijkstra(int u);   //Dijkstra Shortest-paths Algorithm
              queue<int*> Prim();    //Prim's Minimum-spanning-tree Algorithm
              queue<int*>  Kruskal(); //Kruskal's Minimum-spanning-tree Algorithm
              int* TopologicalSort();  //Topological Sort 
              void SetTag(int u,int v,string c);   //Set a Tag c on vertex v in path u->v
              int FindFirstVertex(int u);    //Find u's first adjacent vertex
              int FindNextVertex(int u,int v);  //Find u's next adjacent vertex
              int InOrder(int u);    //Calculating u's in-order
              int OutOrder(int u);   //Calculating u's out-order
              string getTag(int u,int v);  // Get v's tag in path u->v      
              Row Bellman_Ford(int u); //Bellman-Ford Algorithm
              Elemtype GetWeight(int u,int v);
};

template<class Elemtype>
Graph<Elemtype>::Graph(Elemtype* A[3],int SIZE,string DESCRIBE){
typedef AdjacentListNode<Elemtype>* Node;
typedef AdjacentListNode<Elemtype> ListNode;
typedef Elemtype* Row;
typedef vector<Row> AdjMatrix;
typedef vector<Node> AdjList;
              NUM_VERTEX=SIZE;
              ADJ_MATRIX=new AdjMatrix(SIZE,NULL); 
			  ADJ_LIST=new AdjList(SIZE,NULL);  //Initialization
              int q,begin,end;
              Node p,NODE;
              Elemtype* VAL=new Elemtype[SIZE],MID;
              Row temp;
              int POSITION;
              if(DESCRIBE=="UNDIRECTED"){
                 for(int i=0;i<SIZE;i++){
                      temp=A.at(i);
                      begin=(int)*temp;
                      end=(int)*(temp+1);
                      *(VAL+end)=*(temp+2);
                      if(*(ADJ_MATRIX.at(begin)+end)==NULL){
                      	ADJ_MATRIX.insert(begin,VAL);
                      	ADJ_MATRIX.erase(begin+1);
					  }
                      else{
                      	MID=ADJ_MATRIX.at(begin);
                      	*(MID+end)=*(temp+2);
                      	ADJ_MATRIX.insert(begin);
                      	ADJ_MATRIX.erase(begin+1);
					  }
                   }
                   
                 }  //Undirected graph will be stored in adjacent matrix
              else if(DESCRIBE=="DIRECTED"){
                  for(int i=0;i<SIZE;i++){
                    temp=A.at(i);
                    begin=(int)*temp;
                    end=(int)*(temp+1);
                    VAL=*(temp+2);
                    NODE=new ListNode(VAL);
                    if(ADJ_LIST.at(begin)!=NULL){
                      p=ADJ_LIST.at(begin);
                      this->InsertListNode(p,NODE);
                      ADJ_LIST.insert(begin,p);
                      ADJ_LIST.erase(begin+1);
                    }
                    else{p=this->BuildLinkList(temp);ADJ_LIST.insert(begin,p);ADJ_LIST.erase(begin+1);}
                   
                  }   //Directed graph will be stored in adjacent list
              }       
}    //Constructor


template<class Elemtype>
void Graph<Elemtype>::SetTag(int u,int v,string c){
typedef AdjacentListNode<Elemtype>* Node;
              Node p;
              p=ADJ_LIST.at(u);
              for(int i=0;i<v-1;i++){
                   p=p->next;
              }
              p->sign=c;
}     //Set tag c on path u->v

template<class Elemtype>              
string Graph<Elemtype>::getTag(int u,int v){
typedef AdjacentListNode<Elemtype>* Node;
              Node p;
              p=ADJ_LIST(u);
              for(int i=1;i<v;i++){
                  p=p->next;
              }
              return p->sign;
}   //Get the tag of path u->v             

template<class Elemtype>
int Graph<Elemtype>::FindFirstVertex(int u){
typedef AdjacentListNode<Elemtype>* Node;
             Node p=ADJ_LIST.at(u);
             Node q=p->next;
             return q->Vertex;
}    //Find the first adjacent node of u

template<class Elemtype>
int Graph<Elemtype>::FindNextVertex(int u,int v){
typedef AdjacentListNode<Elemtype>* Node;
             Node p=ADJ_LIST.at(u);
             Node q=p->next;
             if(q->next!=NULL){return q->Vertex;}
             else{return -1;}
}   //Find the next adjacent node of u besides v

template<class Elemtype>
int Graph<Elemtype>::OutOrder(int u){
typedef AdjacentListNode<Elemtype>* Node;
             Node p=this->ADJ_LIST.at(u);
             return Num_of_List(p);
}   //Calculate the outorder of u

template<class Elemtype>
int Graph<Elemtype>::InOrder(int u){
typedef Elemtype* Column;
typedef AdjacentListNode<Elemtype>* Node;
             Node p;
             Column candidate;
             int count=0;
             for(int i=0;i<NUM_VERTEX;i++){
                 p=ADJ_LIST.at(i);
                 if(this->IsExist(p,u)==true){count++;}
             }
             return count;
}    //Calculate the inorder of u

template<class Elemtype>
Elemtype* Graph<Elemtype>::Dijkstra(int u){
typedef Elemtype* Series;
typedef AdjacentListNode<Elemtype>* Node;
            Series Dist=NULL;
            Node Temp=ADJ_LIST.at(u);
            int COUNT=0;
            int p;
            Elemtype weight;
            while(Temp!=NULL){
            	if(COUNT==Temp->Vertex){
            		*(Dist+COUNT)=Temp->data;
				}
				else{
					*(Dist=COUNT)=-1;
				}
				COUNT++;
				Temp=Temp->next;
			}
            for(int v=FindFirstVertex(u);v!=-1;v=FindNextVertex(u,v)){
                 for(p=FindFirstVertex(v);p!=-1;p=FindNextVertex(u,p)){
                       weight=GetWeight(v,p);
                       if(*(Dist+p)==-1||*(Dist+p)>*(Dist+v)+weight){
                            *(Dist+p)=*(Dist+v)+weight;
                       }
                 }
            }
            return Dist;                 
}   //Dijkstra shortest-path algorithm

template<class Elemtype>
Elemtype Graph<Elemtype>:: GetWeight(int u,int v){
typedef AdjacentListNode<Elemtype>* Node;
            Node temp=ADJ_LIST.at(u);
            Node p=temp->next;
            while(p!=NULL){
                   if(p->Vertex==v){
                      break;
                      return p->data;
                   }
                   else{p=p->next;}
            }
            if(p==NULL){throw "EROOR!";}
}    //Get path u->v's weight

template<class Elemtype>
int* Graph<Elemtype>::TopologicalSort(){
	int* T=new int[NUM_VERTEX];
	int COUNT=0;
	int Source;
	queue<int> Q;
	for(int i=0;i<NUM_VERTEX;i++){
		if(InOrder(i)==0){Q.push(i);}
	}
	while(Q.size()!=0){
		Source=Q.front();
		*(T+COUNT)=Source;
		for(int j=FindFirstVertex(Source);j!=-1;j=FindNextVertex(Source,j)){
			if(--InOrder(j)==0){Q.push(j);}
		}
		Q.pop();
		COUNT++;	
	}
	return T;
}     //Topological sort

template<class Elemtype>
queue<int* > Graph<Elemtype>::Kruskal(){
    Elemtype* candidate=new Elemtype[2],Symbol;
    Elemtype MIN=*ADJ_MATRIX.at(0);
    Elemtype VAL;
    queue<int*> Result;
	while(Result.size()<=NUM_VERTEX){
		for(int i=0;i<NUM_VERTEX;i++){
			Symbol=ADJ_MATRIX.at(i);
			for(int j=i;j<NUM_VERTEX;j++){
				VAL=*(Symbol+j);
				if(MIN>VAL){MIN=VAL;*candidate=i;*(candidate+1)=j;}
				
			}
		}
		Result.push(candidate);
	}
	return Result;
}   //Kruskal minimum spanning tree
            
            
#endif             
