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
    ListNode* mergeNodes(ListNode* head) {
        ListNode th;
        auto p = &th;
        auto q = head;
        q = q->next;
        int tot = 0;
        while (q) {
            if (q->val)
                tot += q->val;
            else
                p->next = new ListNode(tot), tot = 0, p = p->next;
            q = q->next;
        }
        return th.next;
    }
};