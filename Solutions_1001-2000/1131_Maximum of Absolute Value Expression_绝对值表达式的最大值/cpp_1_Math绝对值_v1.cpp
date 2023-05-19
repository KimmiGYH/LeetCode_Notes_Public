#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int amin = INT_MAX, bmin = INT_MAX, cmin = INT_MAX, dmin = INT_MAX;
        int amax = INT_MIN, bmax = INT_MIN, cmax = INT_MIN, dmax = INT_MIN;
        
        for (int i = 0; i < arr1.size(); i++)
        {
            amin = min(amin, arr1[i] + arr2[i] + i);
            amax = max(amax, arr1[i] + arr2[i] + i);
            
            bmin = min(bmin, -arr1[i] + arr2[i] + i);
            bmax = max(bmax, -arr1[i] + arr2[i] + i);
            
            cmin = min(cmin, arr1[i] - arr2[i] + i);
            cmax = max(cmax, arr1[i] - arr2[i] + i);
            
            dmin = min(dmin, arr1[i] + arr2[i] - i);
            dmax = max(dmax, arr1[i] + arr2[i] - i);
        }
        
        return max(max(amax - amin, bmax - bmin), max(cmax - cmin, dmax - dmin));
    }
};