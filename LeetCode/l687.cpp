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
    int dfsa(TreeNode* root) {
        if (!root)
            return 0;
        int ret = 1;
        int tl = 0, tr = 0;
        if (root->left) {
            if (root->left->val == root->val) {
                tl = dfsa(root->left);
            } else
                dfsa(root->left);
        }
        if (root->right) {
            if (root->right->val == root->val) {
                tr = dfsa(root->right);
            } else
                dfsa(root->right);
        }
        ans = max(ans, ret + tl + tr);
        return ret + max(tl, tr);
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root)
            return 0;
        dfsa(root);
        return ans - 1;
    }
};