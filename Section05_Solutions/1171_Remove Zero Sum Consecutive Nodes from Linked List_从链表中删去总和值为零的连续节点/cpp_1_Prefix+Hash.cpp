#include <unordered_map>
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;        
        unordered_map<int, ListNode*> hash;
        int prefix = 0;
        
        for (auto cur = dummy; cur; cur = cur->next) {
            prefix += cur->val;
            if (hash.count(prefix)) {
                auto start = hash[prefix]->next;
                int tmp = prefix + start->val;
                while (tmp != prefix) {
                    hash.erase(tmp);
                    start = start->next;
                    tmp += start->val;
                }
                hash[prefix]->next = cur->next;
            } else {
                hash[prefix] = cur;
            }
        }
        return dummy->next;
    }
};