/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* pre = new ListNode();
        ListNode* p = pre;
        while (l1 && l2) {
            int s = l1->val + l2->val + carry;
            carry = s / 10, s %= 10;
            ListNode* t = new ListNode(s);
            p->next = t; 
            p = p->next;
            l1=l1->next,l2=l2->next;
        }
        if (l1) {
            while (l1) {
                int s = l1->val + carry;
                carry = s / 10, s %= 10;
                ListNode* t = new ListNode(s);
                p->next = t;
                p = p->next;
                l1=l1->next;
            }
        }
        if (l2) {
            while (l2) {
                int s = l2->val + carry;
                carry = s / 10, s %= 10;
                ListNode* t = new ListNode(s);
                p->next = t;
                p = p->next;
                l2=l2->next;
            }
        }
        if(carry){
            ListNode* t = new ListNode(1);
            p->next = t;
        }
        return pre->next;
    }
};