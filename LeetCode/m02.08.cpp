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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,*slow=head;
        if(fast)fast = fast->next;
        if(fast)fast=fast->next;
        if(slow)slow=slow->next;
        if(!fast)return nullptr;
        while(fast!=slow){
            if(fast)fast = fast->next;
            if(fast)fast=fast->next;
            if(slow)slow=slow->next;
            if(!fast)return nullptr;
        }
        fast=head;
        while(fast!=slow){
            if(fast)fast = fast->next;
            if(slow)slow=slow->next;
        }
        return fast;
    }
};