# 208. Implement Trie (Prefix Tree)_实现 Trie (前缀树) (Medium)



参考资料：[什么是 Trie 树？](https://mp.weixin.qq.com/s/vSF4k6-h5FUUUeDuF4L6wQ)

```c++
class Trie {
public:
    //实现 Trie 树节点结构
    struct  TrieNode {
        bool is_end = false; //标志，false：不是字符串结尾，true：是字符串结尾
        TrieNode* child[26] = {nullptr}; //指向子节点指针
    }*root; // 初始时定义根节点
    
    
    /** 初始化创建：Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** 插入字符串：Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->child[u]) p->child[u] = new TrieNode();
            p = p->child[u];
        }
        p->is_end = true;
    }
    
    /** 检索字符串：Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->child[u]) return false; // 不存在单词也不存在路径
            p = p->child[u];
        }
        return p->is_end; // 有可能路径存在但单词不存在
    }
    
    /** 检查前缀：Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix) {
            int u = c - 'a';
            if (!p->child[u]) return false;
            p = p->child[u];
        }
        return true; // 只要能搜到路径，就说明一定是前缀
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

