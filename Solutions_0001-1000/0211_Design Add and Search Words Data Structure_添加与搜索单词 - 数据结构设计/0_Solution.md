# 211_Design Add and Search Words Data Structure_添加与搜索单词 - 数据结构设计

### 解法一：字典树 + DFS

字典树（前缀树）是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。前缀树可以用 $O(|S|)$ 的时间复杂度完成如下操作，其中 $|S|$ 是插入字符串或查询前缀的长度：
- 向字典树中插入字符串 $word$；
- 查询字符串 $word$ 是否已经插入到字典树中。

字典树的实现可以参考「208. 实现 Trie (前缀树) 」。

**思路和算法**
根据题意，$WordDictionary$ 类需要支持添加单词和搜索单词的操作，可以使用字典树实现。
- 对于添加单词，将单词添加到字典树中即可。
- 对于搜索单词，从字典树的根结点开始搜索。由于待搜索的单词可能包含点号 `.`，因此在搜索过程中需要考虑点号的处理。对于当前字符是字母和点号的情况，分别按照如下方式处理：

1. 如果当前字符是字母，则判断当前字符对应的子结点是否存在，如果子结点存在则移动到子结点，继续搜索下一个字符，如果子结点不存在则说明单词不存在，返回 $false$；
2. 如果当前字符是点号，由于点号可以表示任何字母，因此需要对当前结点的所有非空子结点继续搜索下一个字符。如果当前这个分支存在，且搜得到，返回 $true$。

重复上述步骤，直到返回 $false$ 或搜索完给定单词的最后一个字符。

**复杂度分析**

- 时间复杂度：初始化为 $O(1)$，添加单词为 $O(|S|)$，搜索单词为 $O(|\Sigma|^{|S|})$，其中 $|S|$ 是每次添加或搜索的单词的长度，$\Sigma$ 是字符集，这道题中的字符集为全部小写英语字母，$|\Sigma| = 26$。

空间复杂度：$O(|T|\cdot|\Sigma|)$，其中 $|T|$ 是所有添加的单词的长度之和，$\Sigma$ 是字符集，这道题中的字符集为全部小写英语字母，$|\Sigma| = 26$。

