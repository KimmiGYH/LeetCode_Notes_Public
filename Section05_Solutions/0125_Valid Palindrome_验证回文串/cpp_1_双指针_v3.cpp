#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (isalnum(s[i]) && isalnum(s[j]))
            {
                if (tolower(s[i]) != tolower(s[j])) return false;
                else i++; j--;
            }
            else
            {
                if (!isalnum(s[i])) i++;
                if (!isalnum(s[j])) j--;
            }
        }
        return true;
    }
};