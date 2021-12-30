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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        auto oed = head;
        while (oed->next)
            oed = oed->next;
        auto ned = oed;
        ListNode fh, fh2;
        fh.next = head;
        auto p = &fh;
        auto q = head;
        auto s = &fh2;
        while (q && p) {
            if (q->val >= x) {
                p->next = q->next;
                s->next = q;
                q->next = nullptr;
                s = s->next;
                q = p->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        p->next = fh2.next;
        return fh.next;
    }
};