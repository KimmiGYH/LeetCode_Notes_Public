#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> p, sz;
    
    int find(int& x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    void unite(int& x, int& y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            p[fx] = fy;
            sz[fy] += sz[fx];
        }
    }

    bool equationsPossible(vector<string>& equations) {
        p.resize(26);
        sz.resize(26);
        for (int i = 0; i < 26; i++) {
            p[i] = i;
            sz[i] = 1;
        }

        for (auto &s : equations) {
            if (s[1] == '=') {
                int x = s[0] - 'a', y = s[3] - 'a';
                unite(x, y);
            }
        }

        for (auto &s : equations) {
            if (s[1] == '!') {
                int x = s[0] - 'a', y = s[3] - 'a';
                int fx = find(x), fy = find(y);
                if (fx == fy)
                    return false;
            }
        }

        return true;
    }
};