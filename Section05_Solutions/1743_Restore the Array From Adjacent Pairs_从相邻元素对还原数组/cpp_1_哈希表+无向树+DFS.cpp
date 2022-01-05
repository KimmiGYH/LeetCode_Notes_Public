class Solution {
public:
    unordered_map<int, vector<int>> g; //vector存邻接表，存储每个点的邻边
    vector<int> path;
    
    void dfs(int u, int father) { //传入当前节点，父节点
        path.push_back(u); //将当前节点存下来
        for (int x : g[u])
            if (x != father) //如果当前邻点不是父节点的话
                dfs(x, u); //遍历一下
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int> cnt; //开哈希表记录每个点出现的次数
        for (auto& e : adjacentPairs) { //枚举所有邻边
            int a = e[0], b = e[1];
            g[a].push_back(b), g[b].push_back(a);
            cnt[a]++, cnt[b]++; //a的次数++，b的次数++
        }
        int root = 0;
        for (auto [k, v] : cnt)
            if (v == 1) { //出现次数唯一的点就是根节点
                root = k;
                break;
            }
        dfs(root, 0x3f3f3f3f);//根节点没有父节点，设其父节点为 0x3f3f3f3f
        return path;
    }
};