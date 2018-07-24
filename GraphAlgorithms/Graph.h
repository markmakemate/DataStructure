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
              void InsertListNode(Node head,Elemtype A,int v){
                  Node p;
                  p=head;
                  while(p->next!=NULL){
                     p=p->next;
                  }
                  p=new ListNode(A,v);
              }
              Node BuildLinkList(Elemtype* A){
                Node p,q;
                p=new ListNode(0,*A);
                q=new ListNode(*(A+2),(int)*(A+1));
                p->next=q;
                return p;
              }
              int Num_of_List(Node r){
                   Node p=r;
                   int count=1;
                   while(p->next!=NULL){
                         count++;
                   }
                   return count;
              }
              bool IsExist(vector<Node> A,int u);
              bool IsExist(vector<Row> A,int u);
};   //declaration of Linklist class

template<class Elemtype>
class Graph:public LinkList<Elemtype>{
typedef AdjacentListNode<Elemtype>* Node;
typedef Elemtype* Row;
typedef vector<Node > AdjList;
typedef vector<Row > AdjMatrix;
      private:
              AdjList ADJ_LIST;   //Store Adjacent list
              int NUM_VERTEXS;    //Number of vertexs
              AdjMatrix ADJ_MATRIX;   //Store of Adjacent matrix
              Row* CANDIDATE;       
      public:
              Graph(Row* A,int SIZE,string DISCRIBE);   //Constructor
              void DFT(int u);      //Depth-First Traversal
              void BFT(int u);      //Breath-First Traversal
              Row Dijkstra(int u);   //Dijkstra Shortest-paths Algorithm
              void Prim();    //Prim's Minimum-spanning-tree Algorithm
              void  Kruskal(); //Kruskal's Minimum-spanning-tree Algorithm
              Row TopologicalSort();  //Topological Sort 
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
Graph<Elemtype>::Graph(Elemtype** A,int SIZE,string DESCRIBE){
typedef AdjacentListNode<Elemtype>* Node;
typedef AdjacentListNode<Elemtype> ListNode;
typedef Elemtype* Row;
              CANDIDATE=A;
              int q;
              Node p;
              Row temp;
              int POSITION;
              if(DESCRIBE=="UNDIRECTED"){
                 for(int i=0;i<SIZE;i++){
                  if(this->IsExist(ADJ_MATRIX,(int)*(*CANDIDATE+i))!=false){
                    temp=ADJ_MATRIX.at((int)*(*CANDIDATE+i)); 
                   }
                 }
              NUM_VERTEXS=ADJ_MATRIX.size();
              }
              else if(DESCRIBE=="DIRECTED"){
                  for(int i=0;i<SIZE;i++){
                    temp=*CANDIDATE+i;
                    if(this->IsExist(ADJ_LIST,(int)*temp)!=false){
                      q=(int)*temp;
                      p=ADJ_LIST.at(q);
                      this->InsertListNode(p,*(temp+2),(int)*(temp+1));
                    }
                    else{p=this->BuildLinkList(temp);ADJ_LIST.push_back(p);}
                   
                  }
              NUM_VERTEXS=ADJ_LIST.size();
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
}   

template<class Elemtype>              
string Graph<Elemtype>::getTag(int u,int v){
typedef AdjacentListNode<Elemtype>* Node;
              Node p;
              p=ADJ_LIST(u);
              for(int i=1;i<v;i++){
                  p=p->next;
              }
              return p->sign;
}             

template<class Elemtype>
int Graph<Elemtype>::FindFirstVertex(int u){
typedef AdjacentListNode<Elemtype>* Node;
             Node p=ADJ_LIST.at(u);
             Node q=p->next;
             return q->Vertex;
}

template<class Elemtype>
int Graph<Elemtype>::FindNextVertex(int u,int v){
typedef AdjacentListNode<Elemtype>* Node;
             Node p=ADJ_LIST.at(u);
             Node q=p->next;
             for(int i=1;i<v;i++){
                 q=q->next;
             }
             if(q!=NULL){return q->Vertex;}
}

template<class Elemtype>
int Graph<Elemtype>::OutOrder(int u){
typedef AdjacentListNode<Elemtype>* Node;
             Node p=ADJ_LIST.at(u);
             return Num_of_List(p);
}

template<class Elemtype>
int Graph<Elemtype>::InOrder(int u){
typedef Elemtype* Column;
             Column candidate;
             int count=0;
             for(int i=0;i<NUM_VERTEXS;i++){
                 candidate=ADJ_MATRIX.at(i);
                 if(*(candidate+u)!=-1){count++;}
             }
             return count;
}

template<class Elemtype>
Elemtype* Graph<Elemtype>::Dijkstra(int u){
typedef Elemtype* Series;
            Series Dist=*CANDIDATE+u;
            int p;
            Elemtype weight;
            for(int v=FindFirstVertex(u);v!=-1;v=FindNextVertex(u,v)){
                 for(p=FindFirstVertex(v);p!=-1;p=FindNextVertex(u,p)){
                       weight=GetWeight(v,p);
                       if(*(Dist+p)==-1||*(Dist+p)>*(Dist+v)+weight){
                            *(Dist+p)=*(Dist+v)+weight;
                       }
                 }
            }
            return Dist;                 
}

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
}


            
            
#endif             
