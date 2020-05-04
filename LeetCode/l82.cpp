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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode bh(-98983232);
        bh.next=head;
        int f=0;
        ListNode* fast=head->next;
        ListNode* pfast=head;
        ListNode* slow=head;
        ListNode* pre=(&bh);
        while(fast!=NULL){
            f=0;
            while(fast!=NULL&&fast->val==slow->val){
                fast=fast->next;
                pfast=pfast->next;
                f=1;
            }
            if(f==0){
                pre=slow;
                slow=fast;
                pfast=fast;
                if(fast!=NULL)fast=fast->next;
            }
            else{
            pre->next=fast;
            pfast=fast;
            slow=pfast;
            if(fast!=NULL)fast=fast->next;
            }
        }
        return bh.next;
    }
};