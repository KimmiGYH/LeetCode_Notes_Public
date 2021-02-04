#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0, mxCnt = 0;
        vector<int> cnt(26);
        for (char& task : tasks) {
            ++cnt[task - 'A'];
            if (mx == cnt[task - 'A'])
                ++ mxCnt;
            else if (mx < cnt[task - 'A']) {
                mx = cnt[task - 'A'];
                mxCnt = 1;
            }
        }
        int partCnt = mx - 1;
        int partLen = n + 1 - mxCnt;
        int emptySlots = partCnt * partLen;
        int tasksLeft = tasks.size() - mx * mxCnt;
        // if (emptySlots < tasksLeft)
        //     return tasks.size();
        // return tasks.size() + (emptySlots - tasksLeft);
        int idles = max(0, emptySlots - tasksLeft);
        return tasks.size() + idles;
    }
};