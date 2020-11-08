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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1), *tail = dummy;

        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> heap(comp);

        for (ListNode* list : lists)
            if (list)  heap.push(list);

        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            tail = tail->next = t;
            if (t->next)  heap.push(t->next);
        }
        return dummy->next;
    }
};