#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v; 
        for (int i = 0; i < trips.size(); i++) {
            v.push_back({trips[i][1], trips[i][0]});  // {start, passengers}
            v.push_back({trips[i][2], -trips[i][0]}); // {end, -passengers}
        }
        sort(v.begin(), v.end());
        int passengers = 0;
        for (int i = 0; i < v.size(); i++) {
            passengers += v[i].second;
            if (passengers > capacity)  return false;
        }
        return true;
    }
};