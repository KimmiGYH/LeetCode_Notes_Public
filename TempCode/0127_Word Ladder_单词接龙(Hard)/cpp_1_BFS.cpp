#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> S;
        for (auto& word : wordList) S.insert(word);
        unordered_map<string, int> dist;
        dist[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            auto t = q.front(); // t 队头元素
            q.pop();
            string tmp = t; //先存一下单词
            for (int i = 0; i < t.size(); i++) { // 枚举当前单词的每一位
                t = tmp; // 每次先把单词拿过来 防止前面的位在修改时对单词造成影响
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (S.count(t) && !dist.count(t)) // 如果新的字符串t在S里有但在dist里没有
                    {
                        dist[t] = dist[tmp] + 1;
                        if (t == endWord)
                            return dist[t] + 1; //记得加1 因为把起点也算上了
                        q.push(t); // 否则将t插到队列
                    }
                }
            }
        }
        return 0;
    }
};