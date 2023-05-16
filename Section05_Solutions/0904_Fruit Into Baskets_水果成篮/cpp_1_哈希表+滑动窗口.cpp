class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        unordered_map<int, int> hash;
        for (int i = 0, j = 0, s = 0; i < fruits.size(); i++) {
            hash[fruits[i]] ++;
            if (hash[fruits[i]] == 1) s++;
            while (s > 2) {
                if (-- hash[fruits[j]] == 0)
                    s --;
                j ++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

// --------更简略的代码----------

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        unordered_map<int, int> hash;
        for (int i = 0, j = 0, s = 0; i < fruits.size(); i++) {
            if (++ hash[fruits[i]] == 1) //注意1
                s++;
            while (s > 2) {
                if (-- hash[fruits[j ++]] == 0) //注意2
                    s --;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
