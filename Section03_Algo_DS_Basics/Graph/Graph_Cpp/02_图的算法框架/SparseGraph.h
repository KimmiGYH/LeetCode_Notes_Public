#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图 - 邻接表
class SparseGraph {
    
private:
    int n, m;
    bool directed;
    vector<vector<int>> g;

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i ++)
            g.push_back( vector<int>() );
    }

    ~SparseGraph() {

    }

    int V(){ return n; }
    int E(){ return m; }

    void addEdge(int v, int w) {
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        g[v].push_back(w);
        if (!directed)
            g[w].push_back(v);
        
        m ++;
    }

    bool hasEdge(int v, int w) { //平行边问题时邻接表的缺点
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        for (int i = 0; i < g[v].size(); i ++)
            if (g[v][i] == w)
                return true;
        return false;
    }

    // 将图以邻接表形式打印出来
    void show() {
        for (int i = 0; i < n; i ++) {
            cout << "vertext " << i << ":\t";
            for (int j = 0; j < g[i].size(); j ++)
                cout << g[i][j] << "\t";
            cout << endl;
        }
    }

    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;

    public:
        adjIterator(SparseGraph &graph, int v) : G(graph) { //构造列表的方式初始化
            this->v = v;
            this->index = 0;
        }

        int begin() {
            if (G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        int next() {
            index ++;
            if (index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};

#endif //GRAPH_SPARSEGRAPH_H