class Solution {
   public:
    ListNode* reverse(ListNode* head) {
        ListNode dummy;
        while (head != nullptr) {
            ListNode* p = head;
            head = head->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        for (ListNode* p = head; p->next != nullptr;) {
            if (p->val > p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return reverse(head);
    }
};
