// 左闭右闭区间，l<=r，写法一，能通过
class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l; // 或者 r+1
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        // 如果 start 存在，那么 end 必定存在
        // 找 <= target 的数，即找 >= target+1 的数它左边的那个数
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};

// ==============================================================

// 左闭右开区间，l<r，写法二，能通过
class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};

// ==============================================================

// 左闭右开区间，l<r，写法三，报错

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};
/* Runtime Error错误，解决方案：应该补上判空 nums.empty()
nums=[1], target=1, 正确结果: [0,0]，但运行结果却是[0,-1],错误。解决方案：加了行 if (nums.size() == 1) return {0, 0}; 但还是不对，遇到另外情况：
nums=[2,2], target=2, 正确结果：[0,1]，但运行结果却是[0,0],错误。解决方案：分开来单独判断
- 由于是右闭区间所以取不到r=nums.size()，只能取到r=nums.size()-1，看传进去 target+1 求得的下标
*/


// 根据给到的报错数据修改searchRange函数里的代码后，能通过
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;//这里 r 取闭区间会导致最后一个元素取不到，比如[2,2] target=2, 传进来target+1=3，l=1不符合l<r因为r=1 于是终止循环了；如果是开区间r=2，得到 l=2或r=2 才停止
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (nums.empty() || start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1);
        //判断数组最后一个元素是否为target，如果不是target，那么找该元素左边那个数, end--；如果是target，那表示是重复的数，就找它自己了不找左边的数了。
        if (nums[end] != target)  end--;
        return {start, end};
    }
};


class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (nums.empty() || start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1);
        if (nums[end] != target)  end--;
        return {start, end};
    }
};