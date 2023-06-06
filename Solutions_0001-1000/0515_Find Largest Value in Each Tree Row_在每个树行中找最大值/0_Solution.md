# 515_Find Largest Value in Each Tree Row_在每个树行中找最大值



## 解法一：层序遍历 BFS



取最大值：

```cpp
auto mx = max_element(ans.begin(), ans.end());
res.push_back(*mx);
```

或者：

```cpp
int mx = INT_MIN; //(1)
vector<int> ans;
while (sz--) {
    auto t = q.front();
    q.pop();
    mx = max(mx, t->val); //(2)
    if (t->left) q.push(t->left);
    if (t->right) q.push(t->right);
}
res.push_back(mx); //(3)
```

