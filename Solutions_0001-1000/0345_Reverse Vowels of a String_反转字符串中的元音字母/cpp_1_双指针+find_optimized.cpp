#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string vowels = "aeiou";

    bool check(char c) {
        // find() 看 c 是不是在 vowels 里
        // find() 函数找得到就返回下标，找不到就返回 -1
        return vowels.find(tolower(c)) != -1;
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