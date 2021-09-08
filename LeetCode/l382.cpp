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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */

    ListNode* h;
    Solution(ListNode* head) { h = head; }

    /** Returns a random node's value. */
    int getRandom() {
        auto p = h;
        int v = p->val;
        int c = 1;
        while (p) {
            if (rand() % c++ == 0)
                v = p->val;
            p = p->next;
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */