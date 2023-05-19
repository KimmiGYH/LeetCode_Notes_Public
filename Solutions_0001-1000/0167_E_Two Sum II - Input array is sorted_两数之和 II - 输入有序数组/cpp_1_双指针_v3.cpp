#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        assert(numbers.size() >= 2);
        int l = 0, r = numbers.size() - 1;

        while (l < r) {

            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            }
            else if (numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }

        throw invalid_argument("The input has no solution.");
    }
};