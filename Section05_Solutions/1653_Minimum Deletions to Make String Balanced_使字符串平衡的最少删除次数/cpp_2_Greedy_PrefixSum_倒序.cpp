#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> leftB(n), rightA(n);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            leftB[i] = b;
            if (s[i] == 'b')  b++;
        }
        for (int i = n - 1; i >= 0; i--) {
            rightA[i] = a;
            if (s[i] == 'a')  a++;
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, leftB[i] + rightA[i]);
        return res;
    }
};