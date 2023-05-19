class Solution {
public:
    int minInsertions(string s) {
        int insert = 0, need = 0; //insert插入数量，need右括号需求量
        for (char& c : s) {
            if (c == '(') {
                need += 2;
                if (need & 1) { //判断右括号的需求量是否为奇数
                    insert ++; //插入右括号
                    need --; //右括号需求减1
                }
            } else if (c == ')') {
                need --;
                if (need == -1) { //右括号数量较多时
                    insert ++; //插入左括号
                    need = 1; //右括号需求置为1
                }
            }
        }
        return insert + need;
    }
};