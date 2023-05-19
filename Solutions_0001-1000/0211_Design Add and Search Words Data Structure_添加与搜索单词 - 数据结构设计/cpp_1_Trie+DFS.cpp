class WordDictionary {
public:
    struct Node {
        bool is_end;
        Node *son[26];
        Node() {
            is_end = false;
            for (int i = 0; i < 26; ++i)
                son[i] = NULL;
        }
    }*root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        auto p = root;
        for (auto c : word) {
            int u = c - 'a';
            if (!p->son[u])  p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_end = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);//从第0个字母开始搜
    }
    
    bool dfs(Node* p, string& word, int i) {
        //如果当前遍历到最后一个字母，说明已经遍历完整个单词，看下当前节点是否有单词结尾
        if (i == word.size()) return p->is_end;
        
        if (word[i] != '.') {
            int u = word[i] - 'a';
            if (!p->son[u]) return false; //分支不存在
            return dfs(p->son[u], word, i + 1);
        } else {//否则当前位置是'.'
            for (int j = 0; j < 26; j++)
                if (p->son[j] && dfs(p->son[j], word, i + 1))//如果当前有这个分支且能搜到的话
                    return true;
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
