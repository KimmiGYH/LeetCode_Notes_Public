class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        stack<int> stk;
        sort(properties.begin(), properties.end(), cmp);
        for (int i = 0; i < properties.size(); i++) {
            while (!stk.empty() && stk.top() < properties[i][1]) {
                stk.pop();
                res++;
            }
            stk.push(properties[i][1]);
        }
        return res;
    }
};