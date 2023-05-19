#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto x : nums)  freq[x]++;
    
        // 用来记录出现每种次数的对应元素个数
        int n = nums.size();
        vector<int> s(n + 1);
        for (auto [x, f] : freq)  s[f]++;
        // 找分界点，按次数从大到小即从右往左，t 要累加直到 t ≥ k
        int i = n, t = 0;
        while (t < k)  t += s[i--];
        
        vector<int> res;
        for (auto [x, f] : freq)
            if (f > i)  res.push_back(x);
        return res;
    }
};