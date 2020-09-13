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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto fakehead=ListNode();
        auto p=&fakehead;
        while (l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
                p->next->next=nullptr;
                p=p->next;
            }
            else{
                p->next=l2;
                l2=l2->next;
                p->next->next=nullptr;
                p=p->next;
            }
        }
        if(l1)p->next=l1;
        if(l2)p->next=l2;
        return fakehead.next;
    }
};