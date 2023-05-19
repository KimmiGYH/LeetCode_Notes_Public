class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x || y) { //当 x 或 y 不为 0 时
            res += (x & 1) ^ (y & 1); //看下 x 和 y 的最后一位是否一样
            x >>= 1, y >>= 1; //将 x, y 的个位删掉
        }
        return res;
    }
};