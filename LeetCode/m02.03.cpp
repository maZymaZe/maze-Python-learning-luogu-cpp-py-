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
    void deleteNode(ListNode* node) {
        ListNode* nx = node->next;
        node->next = nx->next;
        node->val = nx->val;
        delete nx;
    }
};