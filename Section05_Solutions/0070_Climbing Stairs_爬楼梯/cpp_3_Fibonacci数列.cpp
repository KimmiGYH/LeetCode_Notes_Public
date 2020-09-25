// 70. Climbing Stairs / Solution 3
// Fibonacci 数列 / C++
// Time Complexity: O(n)
// Space Complexity: O(1)


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 2;
        for (int i = 3; i <= n; ++i) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(7) << endl;
    return 0;
}
// Output: 433494437
