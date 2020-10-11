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
    int pre=-1,ans=0x7FFFFFFF;
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        if(pre>=0&&root->val-pre<ans)ans=root->val-pre;
        pre=root->val;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};