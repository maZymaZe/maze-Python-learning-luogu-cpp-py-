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
    ListNode* detectCycle(ListNode* head) {
        auto f = head;
        auto s = head;
        while (1) {
            if (!f)
                return nullptr;
            f = f->next;
            s = s->next;
            if (!f)
                return nullptr;
            f = f->next;
            if (f && f == s)
                break;
        }
        f = head;
        while (1) {
            if (f == s)
                return f;
            f = f->next;
            s = s->next;
            
        }
        return nullptr;
    }
};