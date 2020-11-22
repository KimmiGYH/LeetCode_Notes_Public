#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for (int i = 0, sum = 0; i < n; i++) {
            for (int c = 1; c <= 26; c++) {
                int rest = k - sum - c;
                int m = n - i - 1; // m表示后面的位数
                // 判断 rest 是否在合理范围内
                if (m <= rest && rest <= m * 26) {
                    ans += c + 'a' - 1; // 填成 c 对应的字符
                    sum += c;
                    break;
                }
            }
        }
        return ans;
    }
};