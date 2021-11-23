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
        // 要求 nums1[i]*nums2[j] ≤ mid
        if (mid >= 0) {
            int k = nums2.size() - 1, t = nums2.size() - 1;
            for (int i = 0; i < nums1.size(); i++) {
                if (nums1[i] > 0) {
                    while (k >= 0 && (LL)nums1[i] * nums2[k] > mid) --k;
                    cnt += k + 1; //上界
                }
                else if (nums1[i] == 0)
                    cnt += nums2.size();
                else {
                    while (t >= 0 && (LL)nums1[i] * nums2[t] <= mid) --t;
                    cnt += nums2.size() - 1 - t;
                }
            }
        } else {
            int k = 0, t = 0;
            for (int i = 0; i < nums1.size(); i++) {
                if (nums1[i] > 0) {
                    while (k < nums2.size() && (LL)nums1[i] * nums2[k] <= mid) ++k;
                    cnt += k;
                }
                else if (nums1[i] == 0)
                    cnt += 0;
                else {
                    while (t < nums2.size() && (LL)nums1[i] * nums2[t] > mid) ++t;
                    cnt += nums2.size() - 1 - (t - 1); //下界
                }
            }
        }
        return cnt;                                               
    }
};