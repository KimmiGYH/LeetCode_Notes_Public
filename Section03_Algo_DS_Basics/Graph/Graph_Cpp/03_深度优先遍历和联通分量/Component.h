#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>
using namespace std;

template <typename Graph>
class Component {

private:
    Graph &G;
    bool *visited;
    int cnt;
    int *id; //看两个节点是否相连，相连的节点id取相同的值，不相连的id取不同的值

    void dfs(int v) {

        visited[v] = true;
        id[v] = cnt;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if ( !visited[i] )
                dfs(i);
        }
    }

public:
    Component(Graph &graph) : G(graph) { //列表构造

        visited = new bool[G.V()];
        id = new int[G.V()];
        cnt = 0;
        for (int i = 0; i < G.V(); i ++) {
            visited[i] = false;
            id[i] = -1;
        }
        
        for (int i = 0; i < G.V(); i ++)
            if (!visited[i]) {
                dfs(i);
                cnt ++;
            }
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {
        return cnt;
    }

    bool isConnected(int v, int w) {
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[v] == id[w];
    }
};

#endif //GRAPH_COMPONENT_H
