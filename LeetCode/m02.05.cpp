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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* fh = new ListNode();
        auto p = fh;
        while (l1 || l2) {
            int nx = carry;
            if (l1)
                nx += l1->val, l1 = l1->next;
            if (l2)
                nx += l2->val, l2 = l2->next;
            carry = nx / 10;
            nx %= 10;
            p->next = new ListNode(nx);
            p = p->next;
            if (!l1 && !l2) {
                if (carry)
                    p->next = new ListNode(1), p = p->next;
                break;
            }
        }
        return fh->next;
    }
};