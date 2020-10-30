/*

思路：将原链表的所有节点遍历一次，将每一个节点插入到新的链表的对应位置中。

新链表的头结点为dummy

*/
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
    ListNode* insertionSortList(ListNode* head) {

        ListNode *dummy = new ListNode(0); 
        ListNode *cur=  head; //当前遍历的点从head开始
        ListNode *pre = dummy;//pre指的是已经遍历过的部分，也就是已经从原链表截取下来拼接到新的虚拟头结点的部分。大概是这个意思，继续往下看。
        ListNode *next = nullptr; //预存cur的next指针,防止被覆盖了以后找不到了。

        while(cur != nullptr)
        {
            while(pre->next && pre->next->val <= cur->val) pre = pre->next;
            //因为用了虚拟头结点，第一个节点的值不能用，所以要从pre->next开始检查。
            //新的链表依次遍历已经存在的节点，如果该节点的值小于等于cur->val,就继续向后遍历,直到找到能插入的位置停下来

            next = cur->next; //预存一下cur的next指针

            cur->next = pre->next; //以下两行将cur节点插到pre和pre->next之间
            pre->next = cur;

            cur = next; // cur向后遍历一个，取原先保留的cur->next指针的值

            pre = dummy; // 将pre回退到dummy的位置,便于下一次遍历和比较，然后再插入，如此反复。
        }
        return dummy->next;
    }
};