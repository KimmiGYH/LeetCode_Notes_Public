//正确代码
class Solution {
public:
    unordered_map<char, int> hs, hp;
    bool check(unordered_map<char, int>& hs, unordered_map<char, int>& hp) {
        for (auto x : hp) {
            char c = x.first;
            if (hs.count(c) == 0 || hs[c] != hp[c])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        for (char& c : p) hp[c]++;
        for (int i = 0, j = 0; i < s.length(); i++) {
            hs[s[i]]++;
            while (i - j + 1 > p.length()) {
                hs[s[j]]--;
                j++;
            }
            if (check(hs, hp)) res.push_back(j);
        }
        return res;
    }
};

// -----------------------------------------
// 错误代码
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hs, hp;
        for (char c : p) hp[c]++;
        
        vector<int> res;
        for (int i = 0, j = 0; i < s.length(); i++) {
            hs[s[i]]++;
            while (i - j + 1 > p.length()) {
                hs[s[j]]--;
                j++;
            }
            if (hs == hp) res.push_back(j);//这里hs和hp应该不同
        }
        return res;
    }
};

/*我猜估计是因为两个哈希表不完全一样：
unordered_map<char, int> hs = {'e':0, 'a':1, 'b':1, 'c':1};
unordered_map<char, int> hp = {'a':1, 'b':1, 'c':1};
hs == hp吗？
这里hs多了个key
*/