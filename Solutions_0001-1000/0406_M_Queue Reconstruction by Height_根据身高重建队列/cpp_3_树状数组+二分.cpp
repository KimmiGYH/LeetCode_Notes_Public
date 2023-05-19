#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<int> tr;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i))    tr[i] += v;
    }
    
    int query(int x) {
        int cnt = 0;
        for (int i = x; i; i -= lowbit(i))    cnt += tr[i];
        return cnt;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        tr.resize(n + 1);
        
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<vector<int>> res(n);
        for (auto p : people) {
            int h = p[0], k = p[1];
            int l = 1, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                // 如果0的个数（即总和减去1的个数）>= k + 1，则答案在左边，否则在右边
                if (mid - query(mid) >= k + 1)  r = mid;
                else l = mid + 1; 
            }
            res[r - 1] = p;
            add(r, 1); // 如果位置被占，就要赋值1
        }
        return res;
    }
};