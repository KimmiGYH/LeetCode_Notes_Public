#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> hash;
        int bulls = 0, cows = 0, total = 0;
        for (auto s : secret)  hash[s]++;
        for (auto g : guess) {
            if (hash[g]) {
                total++;
                hash[g]--;
            }
        }
        for (int i = 0; i < secret.size(); i++)
            if (secret[i] == guess[i])
                bulls++;
        cows = total - bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};