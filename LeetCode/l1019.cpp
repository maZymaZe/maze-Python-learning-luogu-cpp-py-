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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        int l=ans.size();
        stack<int> s;
        for(int i=l-1;i>=0;--i){
            int cur=ans[i];
            while(!s.empty()&&s.top()<=cur){
                s.pop();
            }
            ans[i]=(s.empty())?0:s.top();
            s.push(cur);
        }
        return ans;
    }
};