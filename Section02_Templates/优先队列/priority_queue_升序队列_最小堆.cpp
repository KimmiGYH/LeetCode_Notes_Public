#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

int main() {
    srand (time(NULL));

    // 用了greater，底层是最小堆
    priority_queue<int, vector<int>, greater<int>> pq2;

    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        pq2.push(num);
        cout << "Insert " << num << " in priority queue." << endl;
    }

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }

    return 0;
}

/* Output:
Insert 81 in priority queue.
Insert 72 in priority queue.
Insert 40 in priority queue.
Insert 49 in priority queue.
Insert 88 in priority queue.
Insert 60 in priority queue.
Insert 68 in priority queue.
Insert 19 in priority queue.
Insert 17 in priority queue.
Insert 95 in priority queue.
17 19 40 49 60 68 72 81 88 95 
*/