class Solution {
    using LL = long long;
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        if (nums1.size() > nums2.size())
            return kthSmallestProduct(nums2, nums1, k);
        
        LL l = -1e10, r = 1e10;
        while (l < r) {
            LL mid = l + r >> 1;
            LL cnt = count(mid, nums1, nums2);
            if (cnt >= k) r = mid;
            else l = mid + 1;
        }
        return r;
    }
    
    LL count(LL mid, vector<int>& nums1, vector<int>& nums2) {
        LL cnt = 0;
        for (int& x : nums1) {
            if (x > 0) {
                LL y = floor(mid * 1.0 / x);
                auto iter = upper_bound(nums2.begin(), nums2.end(), y);
                cnt += iter - nums2.begin();
            } else if (x < 0){
                LL y = ceil(mid * 1.0 / x);
                auto iter = lower_bound(nums2.begin(), nums2.end(), y);
                cnt += nums2.size() - (iter - nums2.begin()); // cnt += n-1-j+1
            } else {
                if (mid < 0) cnt += 0;
                else cnt += nums2.size();
            } 
        }
        return cnt;                                               
    }
};