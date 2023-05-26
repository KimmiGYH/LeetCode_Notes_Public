#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

string reverseWords(string s) {
    int n = s.length();
    int k = 0; // effective strings
    for (int i = 0; i < n; i++) {
        // s = "  hello world  "
        // s = "olleh o world "
        // s = "olleh dlrow d "
        // Output: "world hello"
        if (s[i] == ' ') continue;
        int j = i, t = k;
        while (j < n && s[j] != ' ')
            s[t++] = s[j++];
        reverse(s.begin() + k, s.begin() + t);
        s[t++] = ' ';
        k = t, i = j;
    }
    if (k > 0) k--;
    s.erase(s.begin() + k, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s = "  hello world  ";
    string str = reverseWords(s);
    cout << str << endl;
    return 0;
};