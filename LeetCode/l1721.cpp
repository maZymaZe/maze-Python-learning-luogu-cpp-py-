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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        auto p = head;
        while (p)
            p = p->next, n++;
        p = head;
        auto q = head;
        for (int i = 0; i < k - 1; i++)
            p = p->next;
        for (int i = 0; i < (n - k); i++)
            q = q->next;
        swap(p->val, q->val);
        return head;
    }
};