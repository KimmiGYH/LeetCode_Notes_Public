class Solution {
public:
    int get(int n) {
        int tot = 0;
        while (n) {
            int d = n % 10;
            n /= 10;
            tot += d * d;
        }
        return tot;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = get(slow);
            fast = get(get(fast));
        } while (slow != fast);
        if (slow == 1) return true;
        else return false;
    }
};