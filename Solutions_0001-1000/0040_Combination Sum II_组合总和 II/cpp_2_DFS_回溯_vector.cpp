#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, res, path);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    void dfs(vector<int>& candidates, int s, int target, vector<vector<int>>& res, vector<int>& path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = s; i < candidates.size(); i++) {
            int num = candidates[i];
            if (num > target)  return;
            // 加上判重的条件: i > s 即 i 从 s+1 开始，表示对于当前这层递归循环只能使用其中一个元素，另一个重复元素可以在下层循环使用。
            if (i > s && candidates[i] == candidates[i - 1]) continue;
            // 比较 if (i > 0 && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], res, path);
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
            cout<< *q << ' ';
        cout << endl;
    }
    return 0;
}
/* Output:
1 1 6 
1 2 5 
1 7 
2 6
----if (i > 0 && candidates[i] == candidates[i - 1]) continue;----
1 2 5 
1 7 
2 6 
*/