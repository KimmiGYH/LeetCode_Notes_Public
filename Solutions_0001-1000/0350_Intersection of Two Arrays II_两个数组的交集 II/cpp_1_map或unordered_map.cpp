#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int, int> record;
        for (int i = 0; i < nums1.size(); i++)
            record[nums1[i]]++;
        
        vector<int> resultVector;
        for (int i = 0; i < nums2.size(); i++)
            if (record[nums2[i]] > 0) {
                resultVector.push_back(nums2[i]);
                record[nums2[i]]--;
            }
        return resultVector;
    }
};

// -----------用 unordered_map，思路一样，自己写的-------------

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> s1;
        for (int& x : nums1)
            s1[x] ++;
        for (int& x : nums2) {
            if (s1[x] > 0) {
                s1[x]--;
                res.push_back(x);
            }
        }
        return res;
    }
};