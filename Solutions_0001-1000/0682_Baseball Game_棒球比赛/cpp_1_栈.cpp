class Solution {
public:
    int calPoints(vector<string>& ops) {
        //数组模拟栈
        vector<int> stk;
        for (string& s : ops) {
            int p = stk.size() - 1;
            if (s == "+") stk.push_back(stk[p-1] + stk[p]);
            else if (s == "D") stk.push_back(stk[p] * 2);
            else if (s == "C") stk.pop_back();
            else stk.push_back(stoi(s));
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};