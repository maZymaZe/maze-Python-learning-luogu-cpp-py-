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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fakehead= new ListNode();
        fakehead->next= head;
        ListNode *f=fakehead,*s=fakehead;
        n+=1;
        while(n--)s=s->next;
        while (s)s=s->next,f=f->next;
        f->next=f->next->next;
        return fakehead->next;
    }
};