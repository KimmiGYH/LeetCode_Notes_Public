// 左开右开区间，写法一：
class Solution {
public:
    int findMin(vector<int>& nums) {
        // [0, n-2]
        // (-1, n-1)
        int l = -1, r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums.back()) r = mid;
            else l = mid;
        }
        return nums[r];
    }
};

/*【问】：闭区间为什么取 n-2 呀？
【答】：1. 设最小值的下标是 p，二分的是 >= p 的最小位置，而数组最右边那个数，要么是最小值，要么在最小值的右侧，所以无需二分（这个思路和视频中讲的寻找峰值那题是类似的）
*/
// --------------------

class Solution {
public:
    int findMin(vector<int>& nums) {
        // [0, n-2]
        // (-1, n-1)
        int l = -1, r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[0] < nums.back()) return nums[0];//这行省去也可以
            if (nums[mid] < nums.back()) r = mid;
            else l = mid;
        }
        return nums[r];
    }
};

// -------------------------------------------------
// 左闭右开区间 写法二：

class Solution {
public:
    int findMin(vector<int>& nums) {
        // [0, n-2]
        // [0, n-1) 左闭右开区间写法
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums.back()) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};

// -------------------------------------------------
// 左闭右闭区间 写法三：

class Solution {
public:
    int findMin(vector<int>& nums) {
        // [0, n-2]
        int l = 0, r = nums.size() - 2;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums.back()) r = mid - 1;
            else l = mid + 1;
        }
        return nums[l];
    }
};
//注意这个写法不要死套模板，这题求的是两个分段里的最小值，尽量收拢相关区间