#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set <int> record;
        for (int i = 0; i < nums1.size(); i++)
            record.insert(nums1[i]);

        set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++)
            if (record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);

        vector<int> resultVector;
        for (set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++)
            resultVector.push_back(*iter);

        return resultVector;
    }
};

// -----------------------2023年5月20日自己写的------------------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s1, s2;
        for (int& x : nums1) s1.insert(x);
        for (int& x : nums2) {
            if (s1.find(x) != s1.end())
                s2.insert(x);
        }
        for (auto it = s2.begin(); it != s2.end(); it++)
            res.push_back(*it);
        return res;
    }
};
//auto 为 set<int>::iterator