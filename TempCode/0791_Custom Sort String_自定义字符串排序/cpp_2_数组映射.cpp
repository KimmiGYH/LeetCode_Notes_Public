class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> arr(26, 0);
        string res = "";
        for (char& c : s) ++arr[c - 'a'];
        for (char& c : order) {
            while (arr[c - 'a']--)
                res.push_back(c);
        }
        for (char& c : s) {
            //注意这里会从0递减为负数，所以要写上条件 > 0
            while (arr[c - 'a']-- > 0)
                res.push_back(c);
        }
        return res;
    }
};