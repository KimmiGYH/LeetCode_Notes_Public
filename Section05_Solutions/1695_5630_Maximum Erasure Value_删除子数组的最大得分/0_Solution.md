# 1695_5630_Maximum Erasure Value_删除子数组的最大得分 (Medium)

## 滑动窗口

**799. 最长连续不重复子序列**

```cpp

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 100010;

int nums[N];

int main() {
    unordered_map<int, int> hash;
    int n, res = 0;
    cin >> n;
    for (int i = 0, j = 0; i <= n; i++) {
        cin >> nums[i];
        hash[nums[i]]++;
        while (hash[nums[i]] > 1)
            hash[nums[j++]]--;
        res = max(res, i - j + 1);
    }
    cout << res;
    
    return 0;
}

```
