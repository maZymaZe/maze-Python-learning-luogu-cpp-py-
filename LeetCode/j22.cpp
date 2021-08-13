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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto p = head;
        int c = 0;
        while (p)
            p = p->next, c++;
        c = c - k + 1;
        p = head;
        for (int i = 1; i < c; i++)
            p = p->next;
        return p;
    }
};