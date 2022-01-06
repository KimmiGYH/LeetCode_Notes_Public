class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> window;
        int n = s.length(), res = 0;
        if (n < k) return n;
        for (int i = 0, j = 0; j < n; j++) {
            window[s[j]]++;
            while (window.size() > k) {
                window[s[i]]--;
                if (window[s[i]] == 0)
                    window.erase(s[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};