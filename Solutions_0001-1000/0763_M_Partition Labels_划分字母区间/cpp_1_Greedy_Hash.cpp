#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> last_index;
        for (int i = 0; i < s.size(); i++)
            last_index[s[i]] = i;
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_index[s[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end = i + 1;
            }
        }
        return res;
    }
};