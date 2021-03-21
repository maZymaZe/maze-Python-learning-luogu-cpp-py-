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
    ListNode* deleteDuplicates(ListNode* head) {
        auto p1=head,p2=head;
        if(!p1)return p1;
        p2=p1->next;
        while(p2){
            if(p2->val!=p1->val){
                p1=p2;p2=p2->next;
            }else{
                p1->next=p2->next;
                p2=p2->next;
            }
        }
        return head;
    }
};