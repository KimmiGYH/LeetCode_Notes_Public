#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return n;
        
        vector<int> nums(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                nums[i] = nums[i - 1] + 1;
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i] < ratings[i - 1])
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        }
        
        // for (int num : nums) res += num;
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

/*在样例中，ratings = [1,0,2]
我们初始化糖果分配为 [1,1,1]，
第一次遍历更新后的结果为 [1,1,2]，
第二次遍历更新后的结果为 [2,1,2]。

样例2：ratings = [1,3,4,5,2]
Expected: 11
我们初始化糖果分配为 [1,1,1,1,1]，
第一次遍历更新后的结果为 [1,2,3,4,1]，
第二次遍历时要比较 max(4, 1+1)
第二次遍历更新后的结果为 [1,2,3,4,1]，所以答案为 11
*/