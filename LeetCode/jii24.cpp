/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* p = head;
        while (p) {
            auto np = p->next;
            p->next = pre;
            pre = p;
            p = np;
        }
        return pre;
    }
};