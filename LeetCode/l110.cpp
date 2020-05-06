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
    bool isBalanced(TreeNode* root) {
        return  dfs(root)>=0;
    }
    int dfs(TreeNode* root){
        if(root==NULL)return 0;
        int lh=dfs(root->left),rh=dfs(root->right);
        if(lh>=0&&rh>=0&&fabs(lh-rh)<=1)return max(lh,rh)+1;
        return -1;
    }
};