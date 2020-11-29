#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        char str[10];
        for (int i = 0; i < 1 << 10; i++) {
            int s = 0;
            for (int j = 0; j < 10; j++)
                if (i >> j & 1)
                    s++;
            if (s == num) {
                // 返回最高的四位(小时) 最低的六位(分钟)
                int a = i >> 6, b = i & 63; // ☆
                if (a < 12 && b < 60) {
                    sprintf(str, "%d:%02d", a, b);
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};