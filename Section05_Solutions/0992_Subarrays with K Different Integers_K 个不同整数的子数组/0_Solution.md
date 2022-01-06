# 992_Subarrays with K Different Integers_K 个不同整数的子数组

## 解法一：滑动窗口

要解出这道题，需要具体两个知识点
1. **至多包含 K 个不同字符的最长子串** 的模板题

- 如第150题，第340题
[340. 至多包含 K 个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/) 中等

    ```cpp
    //模板：340题
    class Solution {
    public:
        int lengthOfLongestSubstringKDistinct(string s, int k) {
            unordered_map<char, int> hash;
            int n = s.length(), res = 0;
            if (n < k) return n;
            for (int i = 0, j = 0; j < n; j++) {
                hash[s[j]]++;
                while (hash.size() > k) {
                    hash[s[i]]--;
                    if (hash[s[i]] == 0)
                        hash.erase(s[i]);
                    i++;
                }
                res = max(res, j - i + 1);
            }
            return res;
        }
    };
    ```
2. 类似第 930 题的思维，$atMost(k) - atMost(k-1)$
    ```
    输入：A = [1,2,1,2,3], K = 2
    输出：7
    解释：恰好由 2 个不同整数组成的子数组：
    [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
    ```
- 先求出至多包含 $k$ 个不同字符的所有子数组
- 再求至多包含 $k-1$ 个不同字符的所有子数组
- 两个相减，就是恰好由 $k$ 个不同整数组成的子数组

**复杂度分析**：
- 时间复杂度：$O(n)$
  - 其中 $n$ 是数组长度。我们至多只需要遍历该数组三次（右指针和两个左指针各一次）。
- 空间复杂度：$O(n)$
  - 其中 $n$ 是数组长度。我们需要记录每一个数的出现次数，本题中数的大小不超过数组长度。
