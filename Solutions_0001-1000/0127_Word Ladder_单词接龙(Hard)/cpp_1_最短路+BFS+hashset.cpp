class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for (string& word : wordList) st.insert(word);
        unordered_map<string, int> dist;
        dist[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            string rec = word; //备份以便重置
            for (int i = 0; i < word.length(); i++) {
                word = rec;
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word) && !dist.count(word)) {
                        dist[word] = dist[rec] + 1;
                        if (word == endWord) return dist[word] + 1;
                        q.push(word);
                    }
                }
            }
        }
        return 0;
    }
};
// 边权为1的最短路用 BFS 做
// 其中由于可能会出现单词搜到自己本身，所以应用 hashset 来存以便去重。