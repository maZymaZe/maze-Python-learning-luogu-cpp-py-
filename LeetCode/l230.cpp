/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int cnt,n,ans;
class Solution {
public:
    void dfs(TreeNode *root){
        if(root->left)dfs(root->left);
        cnt++;
        if(cnt==n)ans=root->val;
        if(root->right)dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        n=k;cnt=0;
        dfs(root);
        return ans;
    }
};