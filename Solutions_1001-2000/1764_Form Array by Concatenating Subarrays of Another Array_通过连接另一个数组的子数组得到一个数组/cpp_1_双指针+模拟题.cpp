// 这个写法更清楚一些
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), m = groups.size();
        int cnt = 0;
        for (int i = 0, j = 0; i < n && j < m; ) {
            if (check(groups[j], nums, i)) {
                i += groups[j++].size();
                cnt++;
            } else
                i++;
        }
        return cnt == m;
    }
    
    bool check(vector<int> group, vector<int>& nums, int i) {
        int n = nums.size(), t = group.size();
        int j = 0;
        for ( ; i < n && j < t; i++, j++) {
            if (group[j] != nums[i]) return false;
        }
        return j == t;
    }
};

// ------------------------------------------------
// 没太大变化的另种写法
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), m = groups.size();
        int cnt = 0;
        for (int i = 0, j = 0; i < n && j < m; i++) {
            if (check(groups[j], nums, i)) {
                i += groups[j++].size() - 1; //这里写法有所不同
                cnt++;
            }
            if (cnt == m) return true;//这里写法
        }
        return false;
    }
    
    bool check(vector<int> group, vector<int>& nums, int i) {
        int n = nums.size(), t = group.size();
        int j = 0;
        for ( ; i < n && j < t; i++, j++) {
            if (group[j] != nums[i]) return false;
        }
        if (j != t) return false; //这里写法
        return true;
    }
};