class Solution {
public:
    string getString(string &str) {
        int slow = 0;
        for (int fast = 0; fast < str.length(); fast++) {
            if (str[fast] != '#') {
                str[slow++] = str[fast];
            } else {
                if (slow != 0)
                    slow--;
            }
        }
        str.resize(slow);
        return str;
    }

    bool backspaceCompare(string s, string t) {
        return getString(s) == getString(t);
    }
};