class Solution {
public:
    vector<string> res;
    string path;
    vector<string> letterMap = {
        "",     //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz"  //9
    };

    void backtracking(string& digits, int u) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        int idx = digits[u] - '0';
        for (auto c : letterMap[idx]) {
            path += c;
            backtracking(digits, u + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return res;
        backtracking(digits, 0);
        return res;
    }
};