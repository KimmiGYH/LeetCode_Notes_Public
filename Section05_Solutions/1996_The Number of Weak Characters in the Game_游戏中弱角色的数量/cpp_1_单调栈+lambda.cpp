class Solution {
public:
    // static bool cmp(vector<int>&a, vector<int>& b) {
    //     if (a[0] != b[0]) return a[0] < b[0];
    //     else return a[1] > b[1];
    // }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        stack<int> stk;
        // sort(properties.begin(), properties.end(), cmp);
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]);
            });
        for (auto& p : properties) {
            while (!stk.empty() && stk.top() < p[1]) {
                stk.pop();
                res++;
            }
            stk.push(p[1]);
        }
        return res;
    }
};