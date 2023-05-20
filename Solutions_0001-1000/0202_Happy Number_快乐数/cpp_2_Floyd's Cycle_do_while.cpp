class Solution {
public:
    bool isHappy(int n) {
        auto next = [](int v) {
            int ret = 0;
            while (v > 0) {
                ret += (v % 10) * (v % 10);
                v /= 10;
            }
            return ret;
        };
        
        int slow = n, fast = n;
        
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast);
        return slow == 1;
    }
};

//-----------------------------------------

class Solution {
public:
    bool isHappy(int n) {
        auto next = [](int v) {
            int ret = 0;
            while (v > 0) {
                ret += (v % 10) * (v % 10);
                v /= 10;
            }
            return ret;
        };
        
        int slow = n, fast = n;
        slow = next(slow), fast = next(slow);
        
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        } 
        return slow == 1;
    }
};