#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        struct {
            bool operator()(vector<int>& a, vector<int>& b) {
                return a[1] <= b[1];
            }
        } sortTrips;

        struct CompareTrip {
            bool operator()(vector<int>& a, vector<int>& b) {
                return a[2] > b[2]; // minHeap
            }
        };
        // sort trips by start_location
        sort(trips.begin(), trips.end(), sortTrips);
        priority_queue<vector<int>, vector<vector<int>>, CompareTrip> heap;
        int passengers = 0;
        for (auto trip : trips) {
            // remove dead trips
            while (heap.size() && heap.top()[2] <= trip[1]) {
                passengers -= heap.top()[0];
                heap.pop();
            }
            passengers += trip[0];
            if (passengers > capacity)  return false;
            heap.push(trip);
        }
        return true;
    }
};