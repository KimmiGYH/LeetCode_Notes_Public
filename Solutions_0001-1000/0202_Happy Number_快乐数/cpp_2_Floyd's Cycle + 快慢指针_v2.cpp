class Solution {
public:
    int get(int n) {
        int tot = 0;
        while (n) {
            tot += (n % 10) * (n % 10);
            n /= 10;
        }
        return tot;
    }
    
    bool isHappy(int n) {
        int fast = get(n), slow = n;
        while (fast != slow) {
            fast = get(get(fast));
            slow = get(slow);
        }
        return slow == 1;
    }
};