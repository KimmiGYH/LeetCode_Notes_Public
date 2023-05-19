#include <iostream>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i != j) {
            if (s[i] != s[j]) break;
            char c = s[i];
            while (s[i] == c) i++;
            while (s[j] == c) j--;
        }
        return j - i + 1;
    }
};