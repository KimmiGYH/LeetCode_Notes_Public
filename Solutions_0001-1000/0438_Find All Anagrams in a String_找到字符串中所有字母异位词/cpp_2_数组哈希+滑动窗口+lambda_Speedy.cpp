class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto ret = std::vector<int>{};
        if (p.size() > s.size()) return ret;

        auto hf = [](string const& s, int l, int r) {
            auto ret = std::vector<int>(26, 0);
            for (int i = l; i < r; ++i) {
                ++ret[s.at(i) - 'a'];
            }
            return ret;
        };
        auto const target = hf(p, 0, p.size());
        auto cur = hf(s, 0, p.size());
        if (cur == target) ret.push_back(0);

        for (int i = 0; i + p.size() < s.size(); ++i) {
            --cur[s.at(i) - 'a'];
            ++cur[s.at(i + p.size()) - 'a'];
            if (cur == target) ret.push_back(i + 1);
        }
        return ret;
        
    }
};
