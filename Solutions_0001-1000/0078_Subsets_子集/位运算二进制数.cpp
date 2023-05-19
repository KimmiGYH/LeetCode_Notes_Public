//  求 `n` 的第 `k` 位数字是几？
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n = 10;
    for (int k = 3; k >= 0; k--)
        cout << (n >> k & 1);
    
    return 0;
}
// Output: 1010