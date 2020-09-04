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
    ListNode* removeElements(ListNode* head, int val) {
        while(head&&head->val==val)head=head->next;
        if(!head)return head;
        auto pre=head;auto p=pre->next;
        while(p){
            if(p->val==val)p=p->next,pre->next=p;
            else pre=pre->next,p=p->next;
        }
        return head;
    }
};