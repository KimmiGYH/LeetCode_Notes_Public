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
                //计算二进制中 1 的个数  __builtin_popcount
                if (__builtin_popcount(i) + __builtin_popcount(j) == num) {
                    temp = to_string(i) + ":"
                           + (j < 10 ? "0" + to_string(j) : to_string(j));
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};