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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)return NULL;
        ListNode *pA=headA,*pB=headB;
        while(pA!=pB){
            pA=pA?pA->next:headB;
            pB=pB?pB->next:headA;
        }
        return pA;
    }
};