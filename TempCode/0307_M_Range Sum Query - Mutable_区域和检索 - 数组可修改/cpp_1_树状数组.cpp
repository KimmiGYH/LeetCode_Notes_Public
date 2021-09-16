#include <iostream>

using namespace std;

class NumArray {
public:
    int n;
    vector<int> tr, nums;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))    res += tr[i];
        return res;
    }
    
    void add(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i))    tr[i] += v;
    }
    
    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        tr.resize(n + 1);
        
        for (int i = 0; i < n; i ++)
            add(i + 1, nums[i]); //初始化，在第i+1个位置插入nums[i]，O(nlogn)
        /* O(n)做法，待研究
        for (int i = 1; i <= n; i ++)
            for (int j = i - 1; j > i - lowbit(i); j -= lowbit(j))
                tr[i] += tr[j];
        */
        
    }
    
    void update(int index, int val) {
        add(index + 1, val - nums[index]); //+1是因为下标是从1开始的
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */