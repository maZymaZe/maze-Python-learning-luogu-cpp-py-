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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c = 0;
        auto p = head, nh = head, pre = head;
        while (p) {
            p = p->next;
            c++;

            if (c == k) {
                nh = p;
            }
        }
        if (c < k)
            return head;

        p = head;
        pre = reverseKGroup(nh, k);
        for (int i = 1; i <= k; i++) {
            auto nn = p->next;
            p->next = pre;
            pre = p;
            p = nn;
        }
        return pre;
    }
};