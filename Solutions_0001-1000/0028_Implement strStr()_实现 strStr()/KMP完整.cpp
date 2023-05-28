#include <iostream>
#include <vector>

using namespace std;

int strStr(string s, string p) {
    int n = s.length(), m = p.length();
    s = ' ' + s, p = ' ' + p;

    vector<int> nxt(m + 1);
    for (int i = 1, j = 0; i <= m; i++) {//i从2开始，因为nxt[1]=0
        while (j && p[i] != p[j + 1])
            j = nxt[j];
        if (p[i] == p[j + 1])
            j++;
        nxt[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1])
            j = nxt[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m)
            return i - m;
    }
    return -1;
}

int main()
{
    string s = "aabaabaaf";
    string p = "aabaaf";
    int res = strStr(s, p);
    cout << res << endl;
}