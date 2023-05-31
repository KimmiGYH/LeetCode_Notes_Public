class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char& c : s) {
            if (res.empty() || res.back() != c)
                res.push_back(c);
            else res.pop_back();
        }
        return res;
    }
};

// --------------------------------------------

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char& c : s) {
            if (!res.empty() && res.back() == c)
                res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};

// -----------------2023年6月1日--------------------

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char& x : s) {
            if (res.size() && res.back() == x)
                res.pop_back();
            else
                res += x;
        }
        return res;
    }
};