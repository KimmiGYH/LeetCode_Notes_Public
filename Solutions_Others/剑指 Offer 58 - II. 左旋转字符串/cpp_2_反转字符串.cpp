class Solution {
public:
    string reverseLeftWords(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
        //ba|gfedc
        reverse(s.begin(), s.end());
        return s;
    }
};