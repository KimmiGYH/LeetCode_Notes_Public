#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, res, path);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    void dfs(const vector<int>& candidates, int s, int target, set<vector<int>>& res, vector<int>& path) {
        if (target == 0) {
            res.insert(path);
            return;
        }

        for (int i = s; i < candidates.size(); i++) {
            int num = candidates[i];
            if (num > target)  return;
            path.push_back(num);
            dfs(candidates, i + 1, target - num, res, path);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = Solution().combinationSum2(candidates, target);

    for (auto p = begin(res); p != end(res); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q)
            cout<< *q <<' ';
        cout << endl;
    }
    return 0;
}
/* Output:
2 2 3 
7 
*/