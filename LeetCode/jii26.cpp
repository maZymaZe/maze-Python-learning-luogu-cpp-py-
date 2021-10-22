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
    ListNode* middleNode(ListNode* head) {
        auto p1=head,p2=head;
        while(p2&&p2->next)p2=p2->next->next,p1=p1->next;
        return p1;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* p = head;
        while (p) {
            auto np = p->next;
            p->next = pre;
            pre = p;
            p = np;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(!head)return;
        ListNode*mid=middleNode(head);
        ListNode* l1=head,*l2=mid->next;
        mid->next=nullptr;
        l2=reverseList(l2);
        merge(l1,l2);
    }
    void merge(ListNode* l1,ListNode* l2) {
        ListNode *l1t,*l2t;
        while(l1&&l2){
            l1t=l1->next,l2t=l2->next;
            l1->next=l2,l1=l1t,l2->next=l1,l2=l2t;
        }
    }
};