class Solution {
public:
    int get(int n) {
        int s = 0;
        while (n) {
            int a = n % 10;
            n -= a;
            n /= 10;
            s += a * a;
        }
        return s;
    }

    bool isHappy(int n) {
        unordered_map<int, int> hash;
        while (1) {
            hash[n]++;
            n = get(n);
            if (n == 1)
                return true;
            if (hash[n] > 1)
                return false;
        }
    }
};