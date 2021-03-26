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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        auto p=head,q=head,st=head;
        int cnt=0;
        while(q){
            st=q;
            q=q->next;
            cnt++;
        }
        k%=cnt;
        if(!k)return head;
        q=head;
        k=cnt-k;
        auto t=head;
        for(int i=1;i<k;i++){
            q=q->next;
        }
        t=q->next;
        st->next=head;
        q->next=nullptr;
        return t;
    }
};