#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n = people.size(), left = 0, right = n - 1;
        sort(people.begin(), people.end()); //left 瘦子, right 胖子
        while (left <= right) {
            if (people[left] + people[right] <= limit) left++;
            right--;
            res++;
        }
        return res;        
    }
};