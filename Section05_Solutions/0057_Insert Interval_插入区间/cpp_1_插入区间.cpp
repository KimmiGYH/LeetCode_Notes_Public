#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& B) {
        vector<vector<int>> res;
        int k = 0;
        while (k < A.size() && A[k][1] < B[0])
            res.push_back(A[k++]); // 左边完全没交集的部分
        
        if (k < A.size()) {
            B[0] = min(B[0], A[k][0]);
            while (k < A.size() && A[k][0] <= B[1])
                B[1] = max(B[1], A[k++][1]); // 中间有交集的部分
        }
        res.push_back(B);
        
        while (k < A.size())  res.push_back(A[k++]);
        
        return res;        
    }
};