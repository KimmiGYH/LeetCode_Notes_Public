class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; (long long)a * a <= c; a++) {
            int t = c - a * a;
            int b = sqrt(t);
            if (b * b == t) return true;
        }
        return false;
    }
};