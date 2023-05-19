class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int t = 1;
        for (int& x : digits) {
            int sum = 0;
            sum = t + x;
            x = sum % 10;
            t = sum / 10;
        }
        if (t) digits.push_back(t);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

//------------------------------------------------

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int t = 1;
        for (int& x : digits) {
            t += x;
            x = t % 10;
            t /= 10;
        }
        if (t) digits.push_back(t);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};