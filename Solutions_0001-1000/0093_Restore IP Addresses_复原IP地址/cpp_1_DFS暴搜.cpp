#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;        
    }

    // u 表示枚举到的字符串下标，k 表示当前搜到第几个数，path 表示当前的方案
    void dfs(string& s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();
                ans.push_back(path);
            }
            return;
        }
        if (k > 4)  return;
        // t 表示当前这个数的值是多少
        for (int i = u, t = 0; i < s.size(); i++) {
            // 有两位 或者 有前导0，则 break
            if (i > u && s[u] == '0')  break;
            t = t * 10 + s[i] - '0';
            if (t <= 255) dfs(s, i + 1, k + 1, path + to_string(t) + '.') ;
            else break;
        }
    }
};