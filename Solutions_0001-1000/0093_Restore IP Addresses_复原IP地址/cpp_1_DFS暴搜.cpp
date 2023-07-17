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

    // u 表示枚举到的字符串下标，k 表示当前搜到第几组数，path 表示当前的方案
    void dfs(string& s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();
                ans.push_back(path);
            }
            return;
        }
        if (k == 4)  return; // 表示还没结束时 当前方案至少会有五组数
        // num 表示当前这个数的值是多少
        for (int i = u, num = 0; i < s.size(); i++) {
            if (i > u && s[u] == '0')
                break; // 有两位且有前导0，则 break
            num = num * 10 + s[i] - '0';
            if (num <= 255) dfs(s, i + 1, k + 1, path + to_string(num) + '.') ;
            else break;
        }
    }
};