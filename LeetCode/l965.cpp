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
    int t=0;
    bool flag=true;
    void dfs(TreeNode* root){
        if(root&&root->val!=t){
            flag=false;
        }
        if(root){
            dfs(root->left),dfs(root->right);
        }
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        t=root->val;
        dfs(root);
        return flag;
    }
};