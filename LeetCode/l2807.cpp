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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p1 = head, *p2;
        if (!p1)
            return nullptr;
        p2 = p1->next;
        while (p2) {
            ListNode* p3 = new ListNode(__gcd(p1->val, p2->val), p2);
            p1->next = p3;
            p1 = p2;
            p2 = p2->next;
        }
        return head;
    }
};