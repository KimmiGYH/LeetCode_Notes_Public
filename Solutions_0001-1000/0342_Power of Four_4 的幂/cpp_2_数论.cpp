class Solution {
public:
    bool isPowerOfFour(int n) {
        if (num <= 0) return false;
        int r = sqrt(num);
        if (r * r != num) return false;
        return (1 << 30) % num == 0;
    }
};