/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    void dfs(TreeNode* lf, TreeNode* rt, bool f) {
        if (!lf)
            return;
        if (f)
            swap(lf->val, rt->val);
        dfs(lf->left, rt->right, !f);
        dfs(lf->right, rt->left, !f);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return root;
        dfs(root->left, root->right, 1);
        return root;
    }
};