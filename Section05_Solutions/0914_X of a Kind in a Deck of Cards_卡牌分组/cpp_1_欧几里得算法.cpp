#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> hash;
        for (int card : deck)
            ++hash[card];
        int X = 0;
        for (auto& cnt : hash)
            X = gcd(cnt.second, X);
        return X >= 2;
    }
    
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }        
};