# 572_Subtree of Another Tree_另一棵树的子树

## 解法一：递归 DFS

- 判断 $root$ 是否含有子树 $subRoot$，先考虑 $root$ 是否本身就是 $subRoot$：如果是的话，直接返回 $true$；如果不是的话，就需要考察：
    ```cpp
    isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    ```
    注意相应的前提是左右子树非 `NULL`。

- 对于判断两个数是否相等的函数 `isSameTree(root, subRoot)`，就很好写了。

[【每日一题】572. Subtree of Another Tree, 2/6/2021](https://www.youtube.com/live/BHzTSN6gAaM?feature=share)

## 解法二：树哈希

- 考虑把每个子树都映射成一个唯一的数，如果 $subRoot$ 对应的数字和 $root$ 中任意一个子树映射的数字相等，则 $subRoot$ 是 $root$ 的某一棵子树。如何映射呢？我们可以定义这样的哈希函数：

    ```cpp
    哈希值 f = root + left * P + right * Q
    P、Q 都是质数，比如取 P = 131, Q = 31
    ```

- 冲突的可能性比较小。可是如果还是出现了冲突怎么办呢？ 我们可以设计两个哈希函数 $f_1$ 和 $f_2$，用这两个哈希函数生成第三个哈希函数，比如 $f = f_1 + f_2$、$f = f_1 \times f_2$ 等等，这样可以进一步缩小冲突。

## 解法三：KMP

- 我们将每棵树按照先序遍历转化为数组 $S$ 和 $T$，就可以映射为一个unique的序列。注意，对于任何的叶子节点，序列里也要包含它的两个空叶子（可以设计为 `INT_MAX`）.

- 于是这道题就变成了在序列 $S$ 里找一段和T一样的 $window$。这就可以用到 $KMP$ 算法。尽管这里的“目标串”和“模式串”都是数组而不是字符串，但并不妨碍 $KMP$ 算法的实现：依旧是先计算模式串的自相关后缀数组，再计算 $S$ 和 $T$ 之间的互相关后缀数组。

参考：https://github.com/wisdompeak/LeetCode/tree/master/Tree/572.Subtree-of-Another-Tree