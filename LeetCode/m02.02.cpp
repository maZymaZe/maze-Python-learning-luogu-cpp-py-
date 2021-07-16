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
    int kthToLast(ListNode* head, int k) {
        int c=0;
        auto pp=head;
        while(pp){
            c++,pp=pp->next;
        }
        pp=head;
        for(int i=1;i<=c-k;i++){
            pp=pp->next;
        }
        return pp->val;
    }
};