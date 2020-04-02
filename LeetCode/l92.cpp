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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head->next)return head;
        int w=1; 
        ListNode *b;
        ListNode *now=head,*t=head,*tt,*ttt,*tttt;
        for(int i=1;i<m-1;i++)now=now->next;
        if(m==1){
           
            b= new ListNode(5);
            b->next=head;
            now=b;
        }
        ttt=now;
        now=now->next;
        for(int i=m;i<=n;i++){
            if(i==n)tttt=now;
            tt=now->next;
            now->next=t;
            t=now;
            now=tt;
            
        }
        ttt->next->next=now;
        ttt->next=tttt;
        if(m==1)return b->next;
        return head;
    }
   
};