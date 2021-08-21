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
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int t = 1;
        if (root->left) {
            int r = dfs(root->left);
            if (r == 0 || root->val != root->left->val)
                t = 0;
        }
        if (root->right) {
            int r = dfs(root->right);
            if (r == 0 || root->val != root->right->val)
                t = 0;
        }
        ans += t;
        return t;
    }
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};