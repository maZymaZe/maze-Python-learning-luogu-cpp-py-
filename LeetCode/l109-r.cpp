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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* work(ListNode* &head,int l,int r){
        if(l>r)return nullptr;
        int mid=(l+r+1)/2;
        TreeNode* ret=new TreeNode();
        ret->left=work(head,l,mid-1);
        ret->val=head->val;
        head=head->next;
        ret->right=work(head,mid+1,r);
        return ret;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        auto p=head;
        int cnt=0;
        while(p)p=p->next,cnt++;
        return work(head,0,cnt-1);    
    }
};