/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans=0;
int dfs(TreeNode* root){
    if(!root)return 0;
    int delta=0,t;
    
    t=dfs(root->left);
    root->val-=t;
    ans+=abs(t);
    t=dfs(root->right);
    root->val-=t;
    ans+=abs(t);
    delta=1-root->val;
    return delta;
}
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};