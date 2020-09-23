#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int calc(int n, int m) {
        vector<int> result(n+1, 0);
        result[0] = 1;
        for (int i = 1; i <=n; ++i) {
            int current = 0;
            for (int j = 1; j <= m; ++j) {
                if (j > i) break;
                current += result[i-j];
            }
            result[i] = current;
        }
        return result[n];        
    }

public:
    int climbStairs(int n, int m) {

        return calc(n, m);
    }
};


int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(5, 3) << endl;
    return 0;
}
// Output: 433494437