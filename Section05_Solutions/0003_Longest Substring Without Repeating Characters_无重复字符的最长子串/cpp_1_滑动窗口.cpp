class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            hash[s[i]] ++;
            while (hash[s[i]] > 1)
                hash[s[j ++]] --;//元素重复时，将最左边的元素移出滑窗
            res = max(res, i - j + 1);
        }
        return res;
    }
};