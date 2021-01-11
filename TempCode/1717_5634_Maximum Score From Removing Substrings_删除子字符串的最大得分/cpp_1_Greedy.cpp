#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'a') s[i] = 'b';
                else if (s[i] == 'b') s[i] = 'a';
            }
        }
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'a' && s[i] != 'b') i++;
            
            int ca = 0, cb = 0;
            while (i < s.size() && (s[i] == 'a' || s[i] == 'b')) {
                if (s[i] == 'a') ca++;
                else if (s[i] == 'b') {
                    if (ca > 0) {
                        ca--;
                        res += x;
                    } else cb++;
                }
                i++;
            }
            res += min(ca, cb) * y;
        }
        return res;
    }
};