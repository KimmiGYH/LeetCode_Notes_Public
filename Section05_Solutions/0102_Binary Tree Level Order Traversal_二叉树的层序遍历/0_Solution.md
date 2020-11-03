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