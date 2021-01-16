#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> stk;

        for (int i = 0; i < T.size(); ++i) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                auto k = stk.top(); stk.pop();
                res[k] = i - k;
            }
            stk.push(i);
        }
        return res;
    }
};