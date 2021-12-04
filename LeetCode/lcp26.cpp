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
    int res = 0, s = 1;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if (root->right && root->left) {
            res += !l && !r;
            s = !(l && r);
            return 1;
        }
        return l || r;
    }
    int navigation(TreeNode* root) {
        int l = dfs(root->left), r = dfs(root->right);
        return res + ((l && r) ? 0 : s);
    }
};