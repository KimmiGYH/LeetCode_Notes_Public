#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(c, 0, target);
        return res;
    }

private:
    void dfs(vector<int>& c, int u, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        if (u == c.size()) return;

        for (int i = 0; c[u] * i <= target; i++) {
            dfs(c, u + 1, target - c[u] * i);
            path.push_back(c[u]);
        }

        for (int i = 0; c[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};

int main() {
    vector<int> c = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = Solution().combinationSum(c, target);

    for (auto p = begin(res); p != end(res); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q)
            cout<< *q <<' ';
        cout << endl;
    }
    return 0;
}
/* Output:
7
2 2 3 
*/