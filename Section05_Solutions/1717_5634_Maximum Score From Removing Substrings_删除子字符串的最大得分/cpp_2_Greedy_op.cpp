#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        int ca = 0, cb = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != 'a' && s[i] != 'b')
            {   // 其他字符截断
                if (ca && cb) //剩余的可以用较小的
                    res += min(x, y) * min(ca, cb);
                ca = cb = 0;
            }
            else
            {
                if (s[i] == 'a') ca++;
                else if (s[i] == 'b') cb++;
                if (ca && s[i] == 'b' && x >= y) // ab 优先
                    res += x, ca--, cb--;
                else if (s[i] == 'a' && cb && x < y) // ba优先
                    res += y, ca--, cb--;
            }
        }
        return res;
    }
};