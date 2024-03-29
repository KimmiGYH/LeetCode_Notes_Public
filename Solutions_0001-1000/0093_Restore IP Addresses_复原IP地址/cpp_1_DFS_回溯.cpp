class Solution {
public:
    vector<string> res;

    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进res中
            if (is_valid(s, startIndex, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (is_valid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
                pointNum ++;
                backtracking(s, i + 2, pointNum); // 插入逗点之后下一个子串的起始位置为i+2
                pointNum --;                      // 回溯恢复现场
                s.erase(s.begin() + i + 1);       // 回溯删掉逗点
            } else {
                break; // 不合法，直接结束本层循环
            }
        }
    }

    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool is_valid(string& s, int start, int end) {
        if (start > end)
            return false;
        if (s[start] == '0' && start != end)// 至少两位且有前导零
            return false;
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0')   // 遇到非数字字符不合法
                return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255)      // 如果大于255了不合法
                return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) //剪枝
            return res;
        backtracking(s, 0, 0);
        return res;
    }
};