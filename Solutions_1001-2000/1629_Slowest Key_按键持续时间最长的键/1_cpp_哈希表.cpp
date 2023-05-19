#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        // char res = 'a';
        // int prevT = releaseTimes[0], duration = releaseTimes[0], maxDuration = releaseTimes[0];
        int prevT = 0, duration = 0, maxDuration = 0;
        for (int i = 0; i < releaseTimes.size(); i++) {
            duration = releaseTimes[i] - prevT;
            prevT = releaseTimes[i];
            if (duration > maxDuration) {
                maxDuration = duration;
                res = keysPressed[i];
            }
            else if (duration == maxDuration && keysPressed[i] > res)
                res = keysPressed[i];
        }
        return res;
    }
};