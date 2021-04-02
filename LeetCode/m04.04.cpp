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
    int dfs(TreeNode * root){
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        int l=dfs(root->left),r=dfs(root->right);
        if(l==-1||r==-1)return -1;
        if(abs(r-l)>1)return -1;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
};