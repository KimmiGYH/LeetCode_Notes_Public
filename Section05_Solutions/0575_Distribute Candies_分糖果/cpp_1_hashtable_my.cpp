#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int len = candyType.size();
        unordered_map<int, int> hash;
        int cnt;
        for (auto x : candyType) ++hash[x];
        if (hash.size() > len / 2) return len / 2;
        else return hash.size();
    }
};