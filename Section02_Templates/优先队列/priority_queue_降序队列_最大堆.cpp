#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

int main() {
    srand (time(NULL));

    // 默认情况下，底层是最大堆
    priority_queue<int> pq;
    for (int i = 0; i < 10; i++) {
        int num = rand() % 100; // 生成从 0 到 99 生成一个数
        pq.push(num);
        cout << "Insert " << num << " in priority queue." << endl;
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl << endl;

    return 0;
}

/* Output:
Insert 37 in priority queue.
Insert 59 in priority queue.
Insert 2 in priority queue.
Insert 49 in priority queue.
Insert 30 in priority queue.
Insert 98 in priority queue.
Insert 62 in priority queue.
Insert 16 in priority queue.
Insert 37 in priority queue.
Insert 45 in priority queue.
98 62 59 49 45 37 37 30 16 2
*/