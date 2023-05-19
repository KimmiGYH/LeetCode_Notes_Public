#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        string temp;
        //直接遍历  0:00 -> 12:00   每个时间有多少 1
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (count1(i) + count1(j) == num) {
                    temp = to_string(i) + ":"
                           + (j < 10 ? "0" + to_string(j) : to_string(j));
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }

    //计算二进制中 1 的个数
    int count1(int n) {
        int res = 0;
        while (n != 0) {
            // n = n & (n - 1); // 将 u 最右边的 1 清除
            // res += n & 1, n >>= 1;
            n -= n & -n; // lowbit 写法
            res++;
        }
        return res;
    }
};