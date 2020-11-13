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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        auto r = new ListNode();
        auto w = head, p = r;

        while (w && w->next) {
            auto y = w->next;
            p->next = y;
            auto x = y->next;
            if (x == nullptr) {
                w->next = r->next;
                y->next = nullptr;
                return head;
            }
            w->next = x;
            w = x;
            y->next = nullptr;
            p=y;
        }
        w->next=r->next;
        return head;
    }
};