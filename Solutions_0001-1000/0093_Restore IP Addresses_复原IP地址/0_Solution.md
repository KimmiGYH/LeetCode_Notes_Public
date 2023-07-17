# 93. Restore IP Addresses_复原IP地址

## 解法一：DFS＋回溯

切割问题可以抽象为树型结构，如图：
![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20201123203735933.png)

### 回溯三部曲

- 递归参数
1. `startIndex`一定是需要的，因为不能重复分割，记录下一层递归分割的起始位置。
2. 本题我们还需要一个变量`pointNum`，记录添加逗点的数量。
```cpp
vector<string> result;// 记录结果
// startIndex: 搜索的起始位置，pointNum:添加逗点的数量
void backtracking(string& s, int startIndex, int pointNum) {}
```

- 递归终止条件
1. 终止条件和`131.分割回文串`情况就不同了，本题明确要求只会分成 $4$ 段，所以不能用切割线切到最后作为终止条件，而是分割的段数作为终止条件。
2. `pointNum`表示逗点数量，`pointNum`为 $3$ 说明字符串分成了 $4$ 段了。
3. 然后验证一下第四段是否合法，如果合法就加入到结果集里
```cpp
if (pointNum == 3) { // 逗点数量为3时，分隔结束
    // 判断第四段子字符串是否合法，如果合法就放进result中
    if (isValid(s, startIndex, s.size() - 1)) {
        result.push_back(s);
    }
    return;
}
```

- 单层搜索的逻辑
1. 在 `for (int i = startIndex; i < s.size(); i++)` 循环中 `[startIndex, i]` 这个区间就是截取的子串，需要判断这个子串是否合法。
2. 如果合法就在字符串后面加上符号 `.` 表示已经分割。
3. 如果不合法就结束本层循环


然后就是递归和回溯的过程：

1. 递归调用时，下一层递归的 `startIndex` 要从 `i+2` 开始（因为需要在字符串中加入了分隔符 `.`），同时记录分割符的数量 `pointNum` 要 `+1`。
2. 回溯的时候，就将刚刚加入的分隔符 `.` 删掉就可以了，`pointNum` 也要 `-1`。

```cpp
for (int i = startIndex; i < s.size(); i++) {
    if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
        s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
        pointNum++;
        backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
        pointNum--;                         // 回溯
        s.erase(s.begin() + i + 1);         // 回溯删掉逗点
    } else break; // 不合法，直接结束本层循环
}
```

### 判断子串是否合法

最后就是在写一个判断段位是否是有效段位了。
主要考虑到如下三点：

- 段位以`0`为开头的数字不合法
- 段位里有非正整数字符不合法
- 段位如果大于`255`了不合法

```cpp
// 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
bool isValid(const string& s, int start, int end) {
    if (start > end) {
        return false;
    }
    if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
    }
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
            return false;
        }
        num = num * 10 + (s[i] - '0');
        if (num > 255) { // 如果大于255了不合法
            return false;
        }
    }
    return true;
}
```

## 解法二： 暴搜 $C_{n-1}^{3} * 3$

搜四组数：

1. 确保每一个数是在 `0 ~ 255` 之间（用 `num` 来表示当前这个数的值是多少）
2. 同时当有两个数时不能有前导 `0`，比如 `11001`，不能划分成 `11` 和 `001`
3. 最多只有 `12` 位，当 `n` 长度大于 `12` 的时候，即当 `k` 大于 `4` 时，一定无解。
4. 当 `n ` 长度等于 `12` 的时候（即当 `k` 等于 `4`时），相当于给了 `11` 个可以放 `.` 的位置，然后从 `n-1` 个位置里挑 `3` 个 `.`

**时间复杂度分析：**
一共 `n` 个数字，`n−1` 个数字间隔，相当于从 `n−1` 个数字间隔中挑 `3` 个断点，所以计算量是 $C_{n-1}^{3}$

