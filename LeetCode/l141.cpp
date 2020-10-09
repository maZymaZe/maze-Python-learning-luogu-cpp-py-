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
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        if(!head)return false;
        while(1){
            if(!fast)return false;
            fast=fast->next;
            slow=slow->next;
            if(!fast)return false;
            fast=fast->next;
            if(fast==slow&&fast)return true;
        }
        return false;
    }
};