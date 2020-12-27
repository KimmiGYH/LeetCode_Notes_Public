#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> people(students.begin(), students.end()),  // people: {1, 1, 0, 0}
                   food(sandwiches.begin(), sandwiches.end());  // food: {0, 1, 0, 1}
        unordered_map<int, int> hash;
        for (auto c : people)  hash[c]++;
        while (food.size() && hash[food[0]] > 0) {
            if (people[0] != food[0]) {
                people.push_back(people.front());
                people.pop_front();
            } else {
                hash[food[0]]--;
                people.pop_front();
                food.pop_front();
            }
        }
        return people.size();
    }
};