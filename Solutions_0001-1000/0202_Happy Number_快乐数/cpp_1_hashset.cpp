class Solution {
public:
    int get_next(int& n) {
        int tot = 0;
        while (n) {
            int d = n % 10;
            n /= 10;
            tot += d * d;
        }
        return tot;
    }
    
    bool isHappy(int n) {
        unordered_set<int> hash;
        while (n != 1 && !hash.count(n)) {
            hash.insert(n);
            n = get_next(n);
        }
        return n == 1;
    }
};