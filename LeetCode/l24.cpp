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
    ListNode* swapPairs(ListNode* head) {
        ListNode* fakehead=new ListNode();
        fakehead->next=head;
        ListNode *p1=fakehead,*p2=head,*p3;
        if(head)p3=head->next;
        if(!p3)return head;
        while(p3&&p2){
            ListNode *t=p3->next;
            p1->next=p3;
            p3->next=p2;
            p2->next=t;
            p1=p2;
            p2=t;
            if(t)p3=t->next;
            else p3=nullptr;
        }
        return fakehead->next;
    }
};