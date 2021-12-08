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
    pair<int, double> dfs(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        return {
            l.first + r.first + root->val,
            root->val + max({l.second, r.second, (l.first + r.first) / 2.0})};
    }
    double minimalExecTime(TreeNode* root) {
        auto p = dfs(root);
        return p.second;
    }
};