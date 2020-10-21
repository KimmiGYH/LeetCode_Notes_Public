#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string vowels = "aeiou";

    bool check(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }

    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !check(s[i])) i++;
            while (i < j && !check(s[j])) j--;
            swap(s[i], s[j]);
        }
        return s;
    }
};