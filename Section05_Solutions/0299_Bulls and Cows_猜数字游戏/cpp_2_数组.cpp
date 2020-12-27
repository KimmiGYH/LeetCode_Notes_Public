#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), bulls = 0, cows = 0, total = 0;
        vector<int> vec(10, 0);

        for (int i = 0; i < n; i++) {
            vec[secret[i] - '0']++;
            if (secret[i] == guess[i])
                bulls++;
        }

        for (int i = 0; i < n; i++) {
            if (vec[guess[i] - '0'] > 0) {
                total++;
                vec[guess[i] - '0']--;
            }
        }

        cows = total - bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";            
    }
};