# 17. Letter Combinations of a Phone Number_电话号码的字母组合 (Medium)

## 解法一：递归回溯 $O(4^n)$

1. 数字和字母如何映射

```cpp
//v1
    string letterMap[10] = {
        // ...
    };
//v2
    const string letterMap[10] = {
        // ...
    };

//v3: 我自己选的vector
    vector<string> letterMap = {
        "",     //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz"  //9
    };
```

2. 回溯法来解决n个for循环的问题

![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20201123200304469.png)

图中可以看出遍历的深度，就是输入"23"的长度，而叶子节点就是我们要收集的结果，输出["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]。

3. 确定终止条件

例如输入用例"23"，两个数字，那么根节点往下递归两层就可以了，叶子节点就是要收集的结果集。

那么终止条件就是如果 `u` 等于 输入的数字个数（digits.size）了（本来 `u` 就是用来遍历digits的）。

```cpp
if (u == digits.size()) { // u 从0开始，但 u==digits.size()时终止递归
    res.push_back(path);
    return;
}
// 也可以写成
if (path.size() == digits.size()) {
    res.push_back(path);
    return;
}
```

4. 一些写法，是把回溯的过程放在递归函数里了

5. 注意，有可能数字串是空串，需要特判。

##### 时间复杂度

由于使用了递归的方式，时间复杂度与答案个数相同。

设数字串长度为 `n`，则最坏时间复杂度为 $O(4^n)$。

外加 `push_back` 答案 需要 `O(n)`的时间复杂度，所以总的时间复杂度为  $O(4^n * n)$
