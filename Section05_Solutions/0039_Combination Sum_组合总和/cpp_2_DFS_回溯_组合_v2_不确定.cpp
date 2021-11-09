#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int s, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        if (s == candidates.size()) return;

        for (int i = 0; candidates[s] * i <= target; i++) {
            dfs(candidates, s + 1, target - candidates[s] * i);
            path.push_back(candidates[s]);
        }

        for (int i = 0; candidates[s] * i <= target; i++) {
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = Solution().combinationSum(candidates, target);

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