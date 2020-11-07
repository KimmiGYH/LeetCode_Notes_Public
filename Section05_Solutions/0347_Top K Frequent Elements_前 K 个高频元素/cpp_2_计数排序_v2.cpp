#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for (int x : nums) hash[x] ++;
    
        // 用来记录出现每种次数的对应元素个数
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (auto &p : hash) s[p.second] ++ ;
        // 找分界点，按次数从大到小即从右往左，t 要累加直到 t ≥ k
        int i = n, t = 0;
        while (t < k)  t += s[i--];
        
        vector<int> res;
        for (auto &p : hash)
            if (p.second > i)
                res.push_back(p.first);
        return res;
    }
};