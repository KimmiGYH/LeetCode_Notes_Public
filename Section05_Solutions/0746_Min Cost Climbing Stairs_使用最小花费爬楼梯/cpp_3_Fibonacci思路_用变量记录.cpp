#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0;
        for (int num : cost) {
            int c = min(a, b) + num;
            a = b;
            b = c;
        }
        return min(a, b);
    }
};