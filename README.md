# DataStructure and often-used Algorithms implement in C++
# Features:
* **Template Design Pattern**
* **Extensionability**: Parallal/Distributed/Multithread
* **Only STL imported**, no third-party library imported.
* **Graph and Graph Algorithms' implement** are improved. 
* **OOP thinking is perfectly reflected**. 
# References:
1. *Introduction to Algorithms: third edition*, T.H.Cormen,2006<br/>
2. *Challenge Programming Contest*, 2013<br/>
3. *Algorithm*, R.Sedgewick&K.Wayne, 2012<br/>
4. *Thingking in Java*, Bruce Eckel，China Mechine Press, 2007<br/>
5. *C++ Primer Plus*,Stephen Prata, 2015<br/>
6. *C++ Reference*: http://www.cplusplus.com/reference/
7. *Design Patterns: Elements of Reusable Object-Oriented Software*,Erich Gamma & Richard Helm & Ralph Johnson, China Mechine Press,2007
# Contents
## LinkList
* Single Linklist and Double linklist objects
* Define a single node with struct
* Insertion and deletion operations' complexity: O(1)
* Locate node with given value
* Design Pattern: iterator, factory
## Sort Algorithms
Methods:<br/>
* Quick sort
* Dict-order sort
* Shell Sort
* Heap Sort(Max+Min)
* Bubble Sort
* Insert Sort
Classes:<br/>
* Heap:Interfaces Provided
* HeapProcessor: Implement interfaces in Heap class. 
## Search Algorithms
* Binary Search Tree, a single node defined by struct
* B-Tree
* Binary Search: recursion
* Hash(Interfaces provided, HashTable object call)<br/>
1. Open Addressing: Linear probing, Double probing<br/>
2. Chaining: Override LinkList<br/>
3. Hash Function: n mod m(m is the size of hash table)<br/>
4. Hash Table class<br/>
5. Collection class:<br/>
(1) Override operator {}, function as a dictionary<br/>
(2) Key-Value storage model<br/>
* Red-Black Tree:<br/>
1. Rotation<br/>
2. Insertion<br/>
3. Transplant<br/>
4. Mixup<br/>
* AVL Tree
## Graph
<br/>Classes:<br/>
* Graph: Interfaces provided
* Graph Algorithms: *Subclass of Graph*. Implement interfaces in Graph class.
1. Minimum-spanning-tree: Kruskal+Prim<br/>
2. Single source Shortest path: Dijkstra, Bellman Ford<br/>
3. Euler circuit<br/>
4. Critical Path<br/>
* Graph Loader: Load a graph(Key-Value: map<>)
* AdjList: Container of Adjacent List
* AdjMatrix: Container of Adjacent Matrix
* **The Framework**:
![image](https://github.com/markmakemate/DataStructure/blob/master/Relationship.png)
## Greedy Algorithms(some instances)
* Bin packing problem
* Nonpreemptive scheduling
## Divide and Conquer(some instances)
* Nearest points problem
* Strassen Algorithm
## Dynamic Programming(some instances)
* rod-cut
* Longest common sequence
* Matrix Chain
* Shortest path with cost
* State compress DP: covering tile
## Heuristic Algorithms(some instances)
* A* Algorithm
* Generic Algorithm
* Simulate Anneal Arithmetic
* Particle Swarm Algorithm

