#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // O(nlogn) 
        set <int> record(nums1.begin(), nums1.end());

        // O(nlogn)
        set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++)
            if (record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);

        // O(n)
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};