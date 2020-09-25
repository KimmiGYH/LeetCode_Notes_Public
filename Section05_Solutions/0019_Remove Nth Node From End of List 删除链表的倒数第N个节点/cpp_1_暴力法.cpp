#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *workNode = head;
        int size = 0;
        while (workNode != nullptr)
        {
            workNode = workNode->next;
            size++;
        }
        int target = size + 1 - n;

        workNode = dummyNode;
        for (int times = 1; times < target; ++times)
        {
            workNode = workNode->next;
        }
        // 跳过被删除的元素
        workNode->next = workNode->next->next;
        return dummyNode->next;
    }
};