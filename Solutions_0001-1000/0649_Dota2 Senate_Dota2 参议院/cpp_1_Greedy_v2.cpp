#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;

        for (int i = 0; i < senate.size(); i++)
            (senate[i] == 'R') ? r.push(i) : d.push(i);
        
        while (!r.empty() && !d.empty()) {
            int x = r.front(); r.pop();
            int y = d.front(); d.pop();
            (x < y) ? r.push(x + n) : d.push(y + n);
        }

        return r.size() > d.size() ? "Radiant" : "Dire";
    }
};