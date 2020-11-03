# 102. Binary Tree Level Order Traversal_二叉树的层序遍历 (Medium)

```cpp
// 简单的层序遍历框架
void levelOrder() {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->key << endl;

        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0102_Binary%20Tree%20Level%20Order%20Traversal_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/solve.png)