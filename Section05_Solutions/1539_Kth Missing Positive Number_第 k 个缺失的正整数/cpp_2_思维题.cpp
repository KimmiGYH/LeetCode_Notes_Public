class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int& x : arr)
            if (x <= k) k++;
        return k;
    }
};
/*
1) 缺失的正整数一定 >= k
2) 数组中每出现一个 <= k 的数字, 意味着少了一个缺失的数字, 此时k+1
*/