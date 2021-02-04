#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        sort(tasks.begin(), tasks.end());
        vector<char> copy(tasks.begin(), tasks.end());
        auto last = unique(copy.begin(), copy.end());
        copy.erase(last, copy.end());
        vector<int> cnt;
        for (auto& c : copy)
            cnt.push_back(count(tasks.begin(), tasks.end(), c));
        sort(cnt.begin(), cnt.end());
        
        int mx = cnt.back(); // 任务最大次数
        int k = count(cnt.begin(), cnt.end(), mx); // 最大次数的任务出现的个数
        int ret = (mx - 1) * (n + 1) + k;
        if (ret < tasks.size())
            return tasks.size();
        return ret;        
    }
};