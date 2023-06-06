class Solution {
public:
    int get(int n) {
        int a = 0, sum = 0;
        while (n) {
            a = n % 10;
            n /= 10;
            sum += a * a;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = get(n);
        int fast = get(get(n));
        while (true) {
            if (fast == 1 || slow == 1)
                return true;
            else if (fast != slow) {
                fast = get(get(fast));
                slow = get(slow);
            } else     //else if (fast == slow)
                break;
        }
        return false;
    }
};