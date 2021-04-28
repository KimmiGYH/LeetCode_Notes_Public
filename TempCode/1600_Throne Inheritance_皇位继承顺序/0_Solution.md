# 1600_Throne Inheritance_皇位继承顺序

## 解法一：DFS + Hash + Design

1. 阅读理解
   1. 捋清之后，发现题目描述的递归只是继承逻辑的描述
   2. 题目并不要求死人之后，马上动态算出下一个人
   3. 而是根据继承逻辑，将所有人列个排名出来
2. 父子关系，可以使用 `unordered_map<string, vector<string>>` 来记录 `parent -> list[children]`
   1. `key` 为父亲名字
   2. `value` 为按顺序的孩子名字
3. 根据父子关系，可以进行深度优先遍历
   1. 因为第一继承权是长子，长子完了是长孙
   2. 所以是深度优先遍历，前序 preorder
   3. 因为一开始只有国王，从国王开始建图，所以国王就是根节点
4. 使用 `unordered_set<string>` 来标记死亡情况
   1. 这样在 `dfs` 时，根据死亡情况来输出即可

作者：ikaruga
链接：https://leetcode-cn.com/problems/throne-inheritance/solution/throne-inheritance-by-ikaruga/

### 解法二：在一的基础上用树结点的数据结构存储

