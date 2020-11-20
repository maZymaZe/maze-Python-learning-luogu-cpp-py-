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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        ListNode fh(0);
        fh->next = head;
        ListNode* lst=head,*cur=head->next;
        while(cur!=nullptr){
            if(lst->val<=cur->val)lst=lst->next;
            else {
                ListNode* prev=&fh;
                while(prev->next->val<=cur->val)prev=prev->next;
                lst->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur=lst->next;
        }
        return fh.next;
    }
};