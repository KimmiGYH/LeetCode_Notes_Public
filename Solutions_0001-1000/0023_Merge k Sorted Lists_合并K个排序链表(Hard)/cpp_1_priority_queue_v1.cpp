#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    struct Cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val; // 翻转符号以得到较小值
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 元素类型为ListNode*，vector<ListNode*> 底层数据结构是个vector
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        ListNode* dummy = new ListNode(-1), *tail = dummy;
        // 将k个链表的头结点插到堆中
        for (auto node : lists)
            if (node)  heap.push(node);
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            tail = tail->next = t;
            //看k条链表中值最小的头节点是否有后驱节点，有点话把后驱节点插到堆里
            if (t->next)  heap.push(t->next);
        }
        return dummy->next;
    }
};