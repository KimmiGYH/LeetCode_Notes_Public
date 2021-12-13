class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };
        int res = 0, len = s.length();
        for (int i = 0; i < len; ++i) {
            if (i < len - 1 && hash[s[i]] < hash[s[i+1]])
                res -= hash[s[i]];
            else
                res += hash[s[i]];
        }
        return res;
    }
};

            // "IV" : 4;
            // "IX" : 9;
            // "XL" : 40;
            // "XC" : 90;
            // "CD" : 400;
            // "CM" : 900;
