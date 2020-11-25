#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return ans; // 记得要判空
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& digits, int u, string path) {
        // cout << u << " : " << path << endl;
        if (u == digits.size())  ans.push_back(path);
        else {
            for (auto c : strs[digits[u] - '0'])
                dfs(digits, u + 1, path + c);
        }
    }
};

int main() {
    vector<string> res = Solution().letterCombinations("234");
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}

/*
0 : 
1 : a
2 : ad
3 : adg
3 : adh
3 : adi
2 : ae
3 : aeg
3 : aeh
3 : aei
2 : af
3 : afg
3 : afh
3 : afi
1 : b
2 : bd
3 : bdg
3 : bdh
3 : bdi
2 : be
3 : beg
3 : beh
3 : bei
2 : bf
3 : bfg
3 : bfh
3 : bfi
1 : c
2 : cd
3 : cdg
3 : cdh
3 : cdi
2 : ce
3 : ceg
3 : ceh
3 : cei
2 : cf
3 : cfg
3 : cfh
3 : cfi
adg
adh
adi
aeg
aeh
aei
afg
afh
afi
bdg
bdh
bdi
beg
beh
bei
bfg
bfh
bfi
cdg
cdh
cdi
ceg
ceh
cei
cfg
cfh
cfi
*/