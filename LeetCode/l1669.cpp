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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto p1 = list1;
        for (int i = 1; i < a; i++)
            p1 = p1->next;
        auto p2 = list2;
        while (p2->next)
            p2 = p2->next;
        auto p3 = list1;
        for (int i = 0; i <= b; i++)
            p3 = p3->next;
        p1->next = list2;
        p2->next = p3;
        return list1;
    }
};