class Solution { //快慢指针
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val)
                nums[slow++] = nums[fast];
        }
        return slow;
    }
};

// -----------------------------------------------

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != val)
                nums[k++] = nums[i];
        return k;
    }
};

int main()
{
    vector<int> vec = {0,1,2,2,3,0,4,2};
    int val = 2;
    int len = Solution().removeElement(vec, val);
    for (int i = 0; i < len; i++)
        cout << vec[i] << " ";
    cout << endl;        
    return 0;
}