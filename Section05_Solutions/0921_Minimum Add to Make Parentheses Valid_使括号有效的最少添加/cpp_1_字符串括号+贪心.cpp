class Solution {
public:
    int minAddToMakeValid(string s) {
        int insert = 0, right = 0;
        for (char& c : s) {
            if (c == '(') {
                right ++;
            } else if (c == ')') {
                right --;
                if (right == -1) {
                    right = 0;
                    insert ++;
                }
            }
        }
        if (right > 0) insert += right;
        return insert;
    }
};
// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/solution/shi-gua-hao-you-xiao-de-zui-xiao-tian-ji-18hh/