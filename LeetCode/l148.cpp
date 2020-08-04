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
    ListNode* sortList(ListNode* head) {
        ListNode dummyhead(0);
        dummyhead.next=head;
        auto p=head;
        int l=0;
        while(p)l++,p=p->next;
        for(int sz=1;sz<l;sz<<=1){
            auto cur=dummyhead.next;
            auto tail=&dummyhead;
            while(cur){
                auto left=cur;
                auto right=cut(left,sz);
                cur=cut(right,sz);

                tail->next=merge(left,right);
                while(tail->next)tail=tail->next;
            }
        }
        return dummyhead.next;
    }
    ListNode* cut(ListNode*head,int n){
        auto p=head;
        while(--n&&p)p=p->next;
        if(!p)return p;
        auto nx=p->next;
        p->next=NULL;
        return nx;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummyhead(0);
        auto p=&dummyhead;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                p=p->next;
                l1=l1->next;
            }
            else{
                p->next=l2;
                p=p->next;
                l2=l2->next;
            }
        }
        p->next=l1?l1:l2;
        return dummyhead.next;
    }
};
