class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        auto cur = head;
        while (cur->next != head) {
            if ((cur->val <= insertVal) ^ (cur->next->val >= insertVal) ^
                (cur->next->val >= cur->val))
                break;
            cur = cur->next;
        }
        cur->next = new Node(insertVal, cur->next);
        return head;
    }
};
