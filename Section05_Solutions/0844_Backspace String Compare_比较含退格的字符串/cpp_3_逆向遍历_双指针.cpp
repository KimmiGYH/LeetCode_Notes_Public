class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() -1, j = t.length() - 1;
        int x = 0, y = 0; //退格符数量
        while (i >= 0 || j >= 0)
        {
            while (i >= 0) {
                if (s[i] == '#') x++;
                else {
                    if (x) x--;
                    else   break;
                }
                i--;
            }
            
            while (j >= 0) {
                if (t[j] == '#') y++;
                else {
                    if (y) y--;
                    else   break;
                }
                j--;
            }
            
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j] )
                    return false;
            } else {
                if (i >= 0 || j >= 0)
                    return false;
            }
            
            i--, j--;
        }
        return true;
    }
};
// https://leetcode-cn.com/problems/backspace-string-compare/solution/844-bi-jiao-han-tui-ge-de-zi-fu-chuan-by-8lom/