#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int k = 0;
        while (k < binary.size() && binary[k] == '1')  k++;
        if (k == binary.size())  return binary;
        int cnt = 0;
        for (int i = k + 1; i < binary.size(); i++)
            if (binary[i] == '0')  cnt++;
        string res(binary.size(), '1');
        res[k + cnt] = '0';
        return res;
    }
};