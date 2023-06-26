# 617_Merge Two Binary Trees_合并二叉树

## 解法一：递归

1. 递归出口为：
    ```cpp
    if(!t1) return t2;
    if(!t2) return t1; 
    ```
2. 可以将值加到 `tree1` 上，也可以新建节点 `root` 将 `t1->val + t2->val` 

## 解法二：迭代

- 求二叉树对称的时候就是把两个树的节点同时加入队列进行比较。
- 本题我们也使用队列，模拟的层序遍历
