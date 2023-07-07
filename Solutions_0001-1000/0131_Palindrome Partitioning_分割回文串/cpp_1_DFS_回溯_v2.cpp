class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    void backtracking(string& s, int startIndex) {
        if (startIndex == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (is_palindrome(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool is_palindrome(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};