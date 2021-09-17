#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int t = target - numbers[i], left = i + 1, right = numbers.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t)  return {i + 1, mid + 1};
                else if (t > numbers[mid]) left = mid + 1;
                else right = mid;
            }
        }
        return {};
    }
};