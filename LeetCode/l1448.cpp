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
    int ans=0;
    void dfs(TreeNode* n,int m){
        if(n->val>=m){
            ans++;
            m=n->val;
        }
        if(n->left)dfs(n->left,m);
        if(n->right)dfs(n->right,m);
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        dfs(root,root->val);
        return ans;
    }
};