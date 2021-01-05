#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        int res = 0;
        unordered_map<int, int> hash;
        for (auto x : deliciousness) {
            for (int i = 0; i <= 21; i++) {
                int y = (1 << i) - x;
                if (hash.count(y))
                    res = (res + hash[y]) % MOD;
            }
            hash[x]++;
        }
        return res;        
    }
};