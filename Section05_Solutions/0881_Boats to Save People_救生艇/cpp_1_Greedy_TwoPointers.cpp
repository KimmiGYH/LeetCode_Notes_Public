#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n = people.size(), l = 0, r = n - 1;
        sort(people.begin(), people.end()); //l 瘦子, r 胖子
        while (l <= r) {
            if (people[l] + people[r] <= limit) l++;
            r--;
            res++;
        }
        return res;        
    }
};