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
    int t1,t2,ans=0;
    void dfs(TreeNode* t){
        if(t){
            dfs(t->left);
            if(t->val>=t1&&t->val<=t2)ans+=t->val;
            dfs(t->right);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        t1=low,t2=high;
        dfs(root);
        return ans;
    }
};