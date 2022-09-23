/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct pr {
    TreeNode *tp, *dn;
};
class Solution {
   public:
    pr dfs(TreeNode* root) {
        if (!root)
            return {0, 0};
        if (!root->left && !root->right) {
            return {root, root};
        }
        if (root->left && root->right) {
            pr ll = dfs(root->left);
            ll.dn->right = root;
            root->left = nullptr;
            pr rr = dfs(root->right);
            root->right = rr.tp;
            return {ll.tp, rr.dn};
        }
        if (!root->left && root->right) {
            pr rr = dfs(root->right);
            root->right = rr.tp;
            return {root, rr.dn};
        }
        pr ll = dfs(root->left);
        ll.dn->right = root;
        root->left = nullptr;
        return {ll.tp, root};
    }
    TreeNode* convertBiNode(TreeNode* root) { return dfs(root).tp; }
};