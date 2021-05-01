#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"

using namespace std;

int main() {
    int N = 20;
    int M = 100;

    srand( time(NULL) );

    // Sparse Graph
    SparseGraph g1(N, false);
    for (int i = 0; i < M; i ++) {
        int a = rand()%N;
        int b = rand()%N;
        g1.addEdge(a, b);
    }

    // O(E)
    for (int v = 0; v < N; v ++) {
        cout << v << " : ";
        SparseGraph::adjIterator adj( g1, v );
        for (int w = adj.begin(); !adj.end(); w = adj.next() )
            cout << w << " ";
        cout << endl;
    }

    cout << endl;

    // Dense Graph
    DenseGraph g2(N, false);
    for (int i = 0; i < M; i ++) {
        int a = rand()%N;
        int b = rand()%N;
        g2.addEdge(a, b);
    }

    // O(V^2)
    for (int v = 0; v < N; v ++) {
        cout << v << " : ";
        DenseGraph::adjIterator adj(g2, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }

    cout << endl;

    return 0;
}
/*稀疏图遍历邻边，输出：
0 : 14 7 2 0 0 15 18 6 10 5    
1 : 8 1 1 15 14 15 14 8 2 14 4 
2 : 3 13 0 12 18 7 14 1 11     
3 : 2 6 7 19 14 9 7 3 3        
4 : 15 4 4 6 9 19 11 1
5 : 12 6 8 0
6 : 10 4 3 5 16 10 13 0 17
7 : 9 0 8 3 11 19 9 2 3 13
8 : 12 1 12 11 19 14 7 5 1
9 : 16 18 7 12 4 12 7 13 3
10 : 6 10 10 13 6 10 10 0
11 : 13 16 15 12 8 18 11 11 7 19 4 17 15 2   
12 : 16 8 11 8 16 5 9 18 9 2 16 14 16 15     
13 : 19 11 17 2 10 6 9 7 16
14 : 0 15 1 8 17 18 17 1 2 12 3 1
15 : 4 11 15 15 1 14 16 16 1 17 0 11 12      
16 : 12 9 11 12 15 15 6 19 12 17 12 13 18 19 
17 : 19 13 14 14 15 11 16 6
18 : 9 11 19 12 19 14 2 0 16
19 : 17 13 8 18 18 7 16 4 3 11 16

*稠密图遍历邻边，输出：
0 : 1 2 3 5 15 16 17
1 : 0 3 6 11 12 13 19
2 : 0 4 5 7 9 10 11 13 14 16 19 
3 : 0 1 5 7 9 10 12 14 16       
4 : 2 5 6 8 16 19
5 : 0 2 3 4 7 11 13 15 17 18    
6 : 1 4 6 7 11 12 13 14 15 18   
7 : 2 3 5 6 11 12 15 16 17 18  
8 : 4 9 11 16 18 19
9 : 2 3 8 9 10 11 16 18 19     
10 : 2 3 9 13 14 18
11 : 1 2 5 6 7 8 9 11 13 14 15 
12 : 1 3 6 7 15 17
13 : 1 2 5 6 10 11 14 17 19    
14 : 2 3 6 10 11 13 18 19      
15 : 0 5 6 7 11 12 16 17 18 
16 : 0 2 3 4 7 8 9 15       
17 : 0 5 7 12 13 15 18      
18 : 5 6 7 8 9 10 14 15 17  
19 : 1 2 4 8 9 13 14  
*/