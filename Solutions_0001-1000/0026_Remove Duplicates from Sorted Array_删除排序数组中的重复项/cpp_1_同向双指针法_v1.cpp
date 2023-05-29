class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

// ------------------------------------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (!fast || nums[fast] != nums[fast - 1])
                nums[slow++] = nums[fast];
        }
        return slow;
    }
};

// --------- 把 slow 和 fast 都设置成从 1 开始 -------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[fast - 1])
                nums[slow++] = nums[fast];
        }
        return slow;
    }
};

// --------- 把 slow 和 fast 都设置成从 1 开始，写成 while循环 -------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, fast = 1;
        while (fast < nums.size()) {
            if (nums[fast] != nums[fast - 1])
                nums[slow++] = nums[fast++];
            else
                fast++;
        }
        return slow;
    }
};



int main()
{
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    int len = Solution().removeDuplicates(vec);
    for (int i = 0; i < len; i++)
        cout << vec[i] << " ";
    cout << endl;        
    return 0;
}

// 0 1 2 3 4
// Time: O(n); Space: O(1)