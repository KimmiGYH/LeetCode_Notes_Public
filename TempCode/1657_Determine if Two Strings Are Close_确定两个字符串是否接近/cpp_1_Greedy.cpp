#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        
        unordered_set<char>set1;
        unordered_set<char>set2;
        vector<int>count1(26);
        vector<int>count2(26);
        
        for (auto ch : word1) {
            set1.insert(ch);
            count1[ch - 'a'] ++;
        }
        
        for (auto ch : word2) {
            set2.insert(ch);
            count2[ch - 'a'] ++;
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return set1 == set2 && count1 == count2;
    }
};