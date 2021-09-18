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
        vector<int> v1, v2;
        while (l1)
            v1.push_back(l1->val), l1 = l1->next;
        while (l2)
            v2.push_back(l2->val), l2 = l2->next;
        int c1 = v1.size(), c2 = v2.size();
        if (c1 < c2) {
            swap(c1, c2);
            v1.swap(v2);
        }
        int carry = 0;
        for (int i = c1 - 1, j = c2 - 1; i >= 0; i--, j--) {
            v1[i] += carry + (j < 0 ? 0 : v2[j]);
            carry = v1[i] / 10;
            v1[i] %= 10;
        }
        ListNode* fh = new ListNode();
        auto p = fh;
        if (carry)
            p->next = new ListNode(1), p = p->next;
        for (int i = 0; i < c1; i++) {
            p->next = new ListNode(v1[i]);
            p = p->next;
        }
        return fh->next;
    }
};