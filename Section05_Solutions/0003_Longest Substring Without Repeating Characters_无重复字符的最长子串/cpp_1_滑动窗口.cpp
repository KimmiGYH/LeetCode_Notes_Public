#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> heap; // 创建哈希表
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            heap[s[i]]++; // 加了元素，数量增1
            // s[i]重复时，j 往后移动一位，并把 s[j] 移除掉
            while (heap[s[i]] > 1)  heap[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }
};