class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& loc) {
        int origin = 0, cnt = 0;
        vector<double> list;//夹角弧度数组
        
        for (vector<int>& p : points) {
            if (p[0] == loc[0] && p[1] == loc[1]) origin++;
            else list.push_back(atan2(p[1] - loc[1], p[0] - loc[0]));
        }
        
        sort(list.begin(), list.end());
        int m = list.size();
        for (int i = 0; i < m; i++)
            list.push_back(list[i] + 2 * M_PI);
        
        double degree = angle * M_PI / 180;
        for (int l = 0, r = 0; r < list.size(); r++) {
            while (list[r] - list[l] > degree) l++;
            cnt = max(cnt, r - l + 1);
        }
            
        return origin + cnt;
    }
};