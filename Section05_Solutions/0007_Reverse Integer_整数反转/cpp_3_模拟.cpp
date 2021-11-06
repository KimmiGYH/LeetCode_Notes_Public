#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    reverse(str.begin(), str.end());
    if (str.back() == '-')
    {
        cout << '-';
        str.pop_back();
    }
    int k = 0; // 坐标
    // 如果下一位没有越界，为什么是 k + 1 < str.size()，是因为如果只有一位是 0，那么也得输出 0
    while (k + 1 < str.size() && str[k] == '0') k ++;
    // 把剩余的字符输出
    while (k < str.size()) cout << str[k ++];
    
    return 0;
}