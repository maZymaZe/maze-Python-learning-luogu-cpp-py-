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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* fh = new ListNode();
        fh->next = head;
        auto p = fh, q = head;
        while (q) {
            if (q->val == val) {
                q = q->next;
                p->next = q;
            } else {
                q = q->next;
                p = p->next;
            }
        }
        return fh->next;
    }
};