#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        for (char task : tasks)
            ++cnt[task - 'A'];
        sort(cnt.begin(), cnt.end(), greater<int>());
        /* 
        ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
        任务最大次数，A出现6次：mx = 6
        完整模块个数，mx - 1 = 5个
        模块的长度，A--，为 n + 1 = 3
        最后补上的是最大次数的任务出现的个数
        */
        int i = 0, mx = cnt[0], len = tasks.size();
        while (i <= 25 && cnt[i] == mx) ++i;
        return max(len, (mx - 1) * (n + 1) + i);
    }
};

/*
eg: AAAABBBEEFFGG 3
任务最大次数，A出现4次：mx = 4
完整模块个数，mx - 1 = 3个
模块的长度，A---，为 n + 1 = 4
最后补上的是最大次数的任务出现的个数
*/