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
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> m;
        if(!head)return NULL;
        auto p1=head,p2=head->next;
        m.insert(head->val);
        while(p2){
            if(m.count(p2->val))p2=p2->next,p1->next=p2;
            else p1=p2,m.insert(p2->val),p2=p2->next;
        }
        return head;
    }
};