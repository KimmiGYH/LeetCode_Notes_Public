#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;
        for (auto x : candyType) types.insert(x);        
        return min(candyType.size() / 2, types.size());
    }
};