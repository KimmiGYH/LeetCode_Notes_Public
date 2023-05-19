class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n - 1)) && (n & 1431655765);
        //lowbit
        return n > 0 && (n & -n) == n && (n & 1431655765);
        //取模性质，不能用 n%4==0，因为当n=8时会出问题
        return n > 0 && !(n & (n - 1)) && n % 3 == 1;
    }
};