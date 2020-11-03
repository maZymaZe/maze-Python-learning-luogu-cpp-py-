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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int c1 = 0, c2 = 0;
        auto pa = headA, pb = headB;
        while (pa && pa->next)
            pa = pa->next, c1++;
        while (pb && pb->next)
            pb = pb->next, c2++;
        if (pa != pb)
            return nullptr;
        pa = headA, pb = headB;
        if (c1 > c2) {
            int d = c1 - c2;
            for (int i = 0; i < d; i++)
                headA = headA->next;
        }
        if (c2 > c1) {
            int d = c2 - c1;
            for (int i = 0; i < d; i++)
                headB = headB->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};