#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    //nums = [-4,-1,-1,0,1,2]
    //排序nums = [-2,-1,0,1,2,3]
    //Expected: [[-2,-1,3],[-2,0,2],[-1,0,1]]
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1, k = n - 1; j < k; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            while(j < k - 1 && nums[i] + nums[j] + nums[k] > 0) k--;
            if (nums[i] + nums[j] + nums[k] == 0)
                res.push_back({ nums[i], nums[j], nums[k] });
        }
    }
    return res;
}
// {-2,-1,1,2} 针对 j < k-1 而非 j < k 的反例

int main() {
    vector<int> nums = { 3,0,-2,-1,1,2 };
    vector<vector<int>> ret = threeSum(nums);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}