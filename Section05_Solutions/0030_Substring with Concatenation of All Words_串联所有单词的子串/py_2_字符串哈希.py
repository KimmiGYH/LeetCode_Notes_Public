###思路2###
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words or not words[0]: return []
        n, m, w = len(s), len(words), len(words[0])
        res = list()
        # 字符串前缀hash
        seed = 131
        self.f, sh = [[0 for i in range(n)] for j in range(2)]
        self.f[0], sh[0] = 1, ord(s[0])
        for i in range(1, n): # 将s字符串hash化，这次hash时改变存储形态
            self.f[i] = (self.f[i - 1] * seed) % pow(2, 64)
            sh[i] = (sh[i - 1] * seed + ord(s[i])) % pow(2, 64)
        words2 = []
        for i in range(m): # 将words:List[str] -> words2:List[int]
            wh = [0 for _ in range(w)]
            wh[0] = ord(words[i][0])
            for j in range(1, w):
                wh[j] = (wh[j - 1] * seed + ord(words[i][j])) % pow(2, 64)
            words2.append(wh[-1])

        # 匹配
        total = dict() # 统计words中各单词数量
        for elem in words2: #统计words中字符出现次数
            total[elem] = total.get(elem, 0) + 1
        for i in range(w):
            window = dict()
            cnt = 0
            for j in range(i, n, w):
                if j >= (i + m * w): #滑动窗口尾部收缩
                    word = self.getHash(sh, j - m * w, j - (m - 1) * w)
                    window[word] -= 1
                    if window[word] < total.get(word, 0): cnt -= 1
                if j + w <= n: #滑动窗口头部前进
                    word = self.getHash(sh, j, j + w)
                    window[word] = window.get(word, 0) + 1
                    if window[word] <= total.get(word, 0): cnt += 1
                    if cnt == m:
                        res.append(j - (m - 1) * w)
        return res
    def getHash(self, s, i, j):
        if i == 0:
            return s[j - 1]
        else:
            return (s[j - 1] - s[i - 1] * self.f[j - i]) % pow(2, 64)

# https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/30-chuan-lian-suo-you-dan-ci-de-zi-chuan-c7xy/