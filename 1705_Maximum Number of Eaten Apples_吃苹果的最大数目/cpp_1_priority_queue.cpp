#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        typedef pair<int,int> PII; // {expireData, num}
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        int res = 0, i = 0, n = days.size();
        
        while (i < n || heap.size()) {            
            // 先查看优先队列中的苹果是否烂掉了，丢掉烂苹果
            while (heap.size() && heap.top().first <= i)  heap.pop();

            // 加进去新长出来的苹果，{过期日，苹果数}
            if (i < n && apples[i] > 0)
                heap.push({i + days[i], apples[i]});
            
            // 吃掉一个苹果，返还剩下的苹果
            if (heap.size()) {
                auto x = heap.top(); heap.pop();
                res++;
                if (--x.second)
                    heap.push(x);
            }
            i++;
        }
        return res;
    }
};