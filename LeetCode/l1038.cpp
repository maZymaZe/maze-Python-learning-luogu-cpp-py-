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
    int tot = 0;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->right);
        tot += root->val;
        root->val = tot;
        dfs(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};