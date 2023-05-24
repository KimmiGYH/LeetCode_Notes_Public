class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // nums1[i] + nums2[j] == -(nums3[k] + nums4[l])
        unordered_map<int, int> hash;
        int half1st = 0; // nums1[i] + nums2[j]
        int half2nd = 0; // nums3[k] + nums4[l]
        int res = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                half1st = nums1[i] + nums2[j];
                hash[half1st]++;
            }
        }
        for (int k = 0; k < nums3.size(); k++) {
            for (int l = 0; l < nums4.size(); l++) {
                half2nd = nums3[k] + nums4[l];
                res += hash[-half2nd];
            }
        }
        return res;
    }
};