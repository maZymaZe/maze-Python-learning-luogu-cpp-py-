/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = -99999999;
class Solution {
   public:
    int maxPathSum(TreeNode* root) {
        ans = -99999999;
        mx(root);
        return ans;
    }
    int mx(TreeNode* root) {
        if (!root)
            return 0;
        int l = max(0, mx(root->left)), r = max(0, mx(root->right));
        int t = root->val + l + r;
        ans = max(ans, t);
        return root->val + max(l, r);
    }
};