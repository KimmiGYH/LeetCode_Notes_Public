class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int i = 0, j = 0;
        for (char& c : s) {
            i += c == 'L';
            j += c == 'R';
            if (i == j) {
                res++;
                i = j = 0;
            }
        }
        return res;
    }
};