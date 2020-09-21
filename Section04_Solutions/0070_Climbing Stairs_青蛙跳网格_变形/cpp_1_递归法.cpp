#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int calc(int n, int maxJump) {
        int jumpCount = 0;
        if (n == 0)
            return 1;
        
        if (n >= maxJump) {
            for (int i = 1; i < maxJump; ++i) {
                jumpCount += calc(n-i, maxJump);
            }
        } else {
            jumpCount = calc(n, n);
        }
        return jumpCount;
    }

public:
    int climbStairs(int n, int m) {
        return calc(n, m);
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(3, 5) << endl;
    return 0;
}
// Output: 433494437