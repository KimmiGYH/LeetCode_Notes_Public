class Solution {
public:
    string reverse_str(string& s, int start, int end) {
        for (int i = start, j = end - 1; i < j; i++, j--)
            swap(s[i], s[j]);
        return s;
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2*k) {
            int l = i, r = i + k;
            if (r > s.length())
                reverse_str(s, l, s.length());
            else
                reverse_str(s, l, i + k);
        }
        return s;
    }
};