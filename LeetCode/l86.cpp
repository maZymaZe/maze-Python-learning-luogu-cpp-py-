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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode fk(0),ff(0);
        ff.next=head;
        ListNode*p=head,*pp=&fk,*pre=&ff;
        while(p){
            if(p->val>=x){
                pp->next=p;
                pre->next=p->next;
                p->next=nullptr;
                p=pre->next;
                pp=pp->next;
            }else{
                pre=pre->next;
                p=p->next;
            }
        }
        pre->next=fk.next;
        return ff.next;
        
    }
};