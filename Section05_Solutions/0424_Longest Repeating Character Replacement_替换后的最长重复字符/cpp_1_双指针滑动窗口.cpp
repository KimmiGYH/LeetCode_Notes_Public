class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            for (int i = 0, j = 0, cnt = 0; j < s.size(); j++) {//cnt当前窗口里c出现的字符次数
                if (s[j] == c) cnt++; //判断新加字符==c的话，cnt++
                while (j - i + 1 - cnt > k) { //总长度-cnt>k，就要删掉窗口开头的字符
                    if (s[i] == c) cnt --; //如果窗口开头的字符==c，cnt--
                    i++; //窗口左边指针右移
                }
                res = max(res, j - i + 1); //更新答案
            }
        }
        return res;
    }
};