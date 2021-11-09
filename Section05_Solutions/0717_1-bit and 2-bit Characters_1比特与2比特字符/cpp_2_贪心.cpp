class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ones = 0;
        //因为最后一位规定是0，从倒数第二位往前看连续的 1 的个数是奇还是偶
        for (int i = bits.size() - 2; i >= 0 && bits[i]; i--)
            ones ++;
        if (ones % 2) return false;
        return true;
    }
};