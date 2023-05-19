class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size(); //注意右端点的取值
        while (l < r) {
            int mid = l + r >> 1;
            if (arr[mid] - (mid + 1) >= k) r = mid;
            else l = mid + 1;
        }
        return r + k;
    }
};