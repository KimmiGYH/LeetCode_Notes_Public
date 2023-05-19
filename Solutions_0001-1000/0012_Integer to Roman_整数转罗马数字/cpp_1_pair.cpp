class Solution {
public:
    vector<pair<int, string>> table = {
        {   1 , "I"}, {  4 , "IV"}, {  5 , "V"}, {  9, "IX"},
        {  10 , "X"}, { 40 , "XL"}, { 50 , "L"}, { 90, "XC"},
        { 100 , "C"}, {400 , "CD"}, {500 , "D"}, {900, "CM"},
        {1000 , "M"}
    };
    string intToRoman(int num) {
        int len = table.size();
        string res;
        for (int i = len - 1; i >= 0; i--) {
            int value = table[i].first;
            string str = table[i].second;
            while (num >= value) {
                num -= value;
                res += str;
            }
        }
        return res;
    }
};