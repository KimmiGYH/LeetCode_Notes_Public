#include <vector>

using namespace std;

class Solution {
public:
    vector<int> p;
    
    int find(int x) { //并查集找根节点和路径压缩的函数
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p.resize(n + 1); //初始化并查集数组
        for (int i = 1; i <= n; i ++)  p[i] = i;
        
        for (auto& e: edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a != b) p[a] = b; // a != b 说明没有出现环，则直接合并 a, b 即可
            else return e; // 否则当前边就是环里出现的最后一条边
        }
        return {};
    }
};