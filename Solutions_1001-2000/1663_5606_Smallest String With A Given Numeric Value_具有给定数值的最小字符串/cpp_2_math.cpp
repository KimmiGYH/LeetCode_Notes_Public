#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        int m = (k - n) / 25;
        string left (n - m - 1, 'a');
        string right (m, 'z');
        k -= left.size() + 26 * right.size();
        return left + (char)(k - 1 + 'a') + right;
    }
};
