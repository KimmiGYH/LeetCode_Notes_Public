class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 0; i <= n; i ++)
            bits[i] = countOnes(i);
        return bits;
    }
    
    int countOnes(int x) {
        int cnt = 0;
        while (x) {
            x &= x - 1; //或者 x -= x & -x
            cnt++;
        }
        return cnt;
    }
};