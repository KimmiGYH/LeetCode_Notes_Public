class Solution {
public:
    bool check(int& x) {
        return x > 0 && (x & (x - 1)) == 0;
    }

    int countPairs(vector<int>& d) {
        int n = d.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = d[i] + d[j];
                if (check(tmp)) res ++;
            }
        }
        return res;
    }
};
/* Time Limit Exceeded
为什么？
因为数据范围为：1 <= deliciousness.length <= 10^5
双重循环的话就到 10^10，一般 int 在 10^9，会爆int
需要把时间复杂度做到 nlogn 以内