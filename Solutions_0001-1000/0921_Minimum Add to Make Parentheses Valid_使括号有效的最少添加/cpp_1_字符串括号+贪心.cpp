class Solution {
public:
    int minAddToMakeValid(string s) {
        int insert = 0, need = 0;
        for (char& c : s) {
            if (c == '(') {
                need ++;
            } else if (c == ')') {
                need --;
                if (need == -1) {
                    insert ++;
                    need = 0;
                }
            }
        }
        return insert + need;
    }
};
// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/solution/shi-gua-hao-you-xiao-de-zui-xiao-tian-ji-18hh/