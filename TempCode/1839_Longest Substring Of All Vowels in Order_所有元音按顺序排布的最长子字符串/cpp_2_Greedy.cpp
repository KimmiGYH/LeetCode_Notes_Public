#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int len = 1, cnt = 1, res = 0;
        for (int i = 1; i < word.size(); i ++)
        {
            if (word[i - 1] < word[i]) len ++, cnt ++;
            else if (word[i - 1] == word[i])  len ++;
            else len = 1, cnt = 1;
            
            if (cnt == 5) res = max(res, len);
        }
        return res;        
    }    
};