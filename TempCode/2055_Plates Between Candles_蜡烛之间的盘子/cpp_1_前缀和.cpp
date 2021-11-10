class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        // l 表示每个位置的左边第一根蜡烛，r 表示每个位置右边的第一根蜡烛
        // 之所以 r 数组长度开到 n+2 是因为如果第 n 个位置没有蜡烛，那默认右边第一根蜡烛在 n+1 的位置上，所以总共 n+2 个位置
        vector<int> prefix(n + 1), l(n + 1), r(n + 2, n + 1);
        for (int i = 1; i <= n; i ++) {
            prefix[i] = prefix[i - 1]; //预处理前缀和数组
            // 如果当前位置是盘子，prefix加1；当前不是蜡烛，所以蜡烛在左边位置
            if (s[i - 1] == '*') prefix[i] ++, l[i] = l[i - 1];
            else l[i] = i; //否则就是蜡烛，是当前位置自己
        }
        // 同理预处理每个右边位置右边第一根蜡烛的位置
        for (int i = n; i; i --) {
            if (s[i - 1] == '*') r[i] = r[i + 1];
            else r[i] = i;
        }

        vector<int> res;
        for (auto& q : queries) {
            // 找到左端点右边第一根蜡烛，以及右端点左边第一根蜡烛
            int a = r[q[0] + 1], b = l[q[1] + 1];
            if (a > b) res.push_back(0);
            else res.push_back(prefix[b] - prefix[a - 1]);
        }
        return res;
    }
};