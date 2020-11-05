#include <iostream>
#include <queue>
#include <functional>
#include <ctime>

using namespace std;

// 比较 a 和 b 的个位数
bool myCmp(int a, int b) {
    return a%10 < b%10; // 个位数更大的排前面
}

int main() {
    srand (time(NULL));

    // 使用自定义 Comparator 的 priority queue
    priority_queue<int, vector<int>, function<bool(int,int)>> pq3(myCmp);

    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        pq3.push(num);
        cout << "Insert " << num << " in priority queue." << endl;
    }

    while (!pq3.empty()) {
        cout << pq3.top() << " ";
        pq3.pop();
    }

    return 0;
}

/* Output:
Insert 4 in priority queue.
Insert 93 in priority queue.
Insert 57 in priority queue.
Insert 84 in priority queue.
Insert 75 in priority queue.
Insert 71 in priority queue.
Insert 81 in priority queue.
Insert 66 in priority queue.
Insert 87 in priority queue.
Insert 44 in priority queue.
57 87 66 75 4 84 44 93 81 71 
*/
