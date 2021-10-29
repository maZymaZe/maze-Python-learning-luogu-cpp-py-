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
    TreeNode *head=nullptr;
    void dfs(TreeNode * root,TreeNode *& t){
        if(!root) return;
        dfs(root->left,t);
        if(!t){
            t=new TreeNode(root->val);
            head=t;
        }else {
            t->right=new TreeNode(root->val);
            t=t->right;
        }
        dfs(root->right,t);

    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans=nullptr;
        dfs(root,ans);
        return head;
    }
};