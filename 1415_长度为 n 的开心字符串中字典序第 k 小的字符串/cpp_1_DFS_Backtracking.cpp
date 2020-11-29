#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string res;
    string getHappyString(int n, int k) {
        string str;
        dfs(str, n, k);
        return k == 0 ? res : "";
    }

    void dfs(string& str, int n, int& k) {
        if (k <= 0) return;

        if (n == 0) {
            if (--k == 0)  res = str;
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ++ch) {
            if (!str.empty() && ch == str.back()) continue;
            str.push_back(ch);
            dfs(str, n - 1, k);
            str.pop_back();
        }
    }
};

int main()
{
    
    string ans = Solution().getHappyString(3, 9);
    for (int i = 0; i < ans.length(); i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}