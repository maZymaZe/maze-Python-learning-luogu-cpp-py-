/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ls;
        ListNode *p=head;
        while(p){
            ls.push_back(p->val);
            p=p->next;
        }
        return pre(0,ls.size()-1,ls);
    }
    TreeNode* pre(int l,int r,vector<int> &ls){
        if(l>r)return NULL;
        int mid=(l+r)/2;
        TreeNode *root=new TreeNode(ls[mid]);
        root->left=pre(l,mid-1,ls);
        root->right=pre(mid+1,r,ls);
        return root;
    } 
};