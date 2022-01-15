class Solution {
public:
    const double eps = 1e-8; //精确度eps
    int a, b; //全局变量记录答案
    
    int get(vector<int>& arr, double x) {
        int cnt = 0; //cnt表示满足要求的数的个数
        for (int i = 0, j = 0; j < arr.size(); j++) {
            while ((double)arr[i + 1] / arr[j] <= x) i++;
            if ((double)arr[i] / arr[j] <= x)
                cnt += i + 1; //满足要求的是从0到i，一共 i+1 个数
            if (abs((double)arr[i] / arr[j] - x) < eps) {
                a = arr[i]; b = arr[j];
            }
        }
        return cnt;
    }
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        while (r - l >= eps) { //写成 r - l > eps 也可以
            double mid = (l + r) / 2;
            if (get(arr, mid) >= k) r = mid; //≤x 的个数如果 ≥k，x 猜太大了，要减少它的值，答案在左半边，r=mid
            else l = mid; //≤x 的个数如果＜k，x 猜太小了，要增加它的值，答案在右半边，l=mid
        }
        
        get(arr, r);
        return {a, b};
    }
};