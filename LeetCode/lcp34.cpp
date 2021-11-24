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
    unordered_map<TreeNode*, int> dp[11];
    int kk;
    int dfs(TreeNode* root, int usd) {
        if (!root)
            return 0;
        if (dp[usd].count(root))
            return dp[usd][root];
        int ret = 0;
        for (int i = 0; i <= kk - usd - 1; i++) {
            ret = max(ret, root->val + dfs(root->left, kk - i) +
                               dfs(root->right, usd + 1 + i));
        }
        ret = max(ret, dfs(root->left, 0) + dfs(root->right, 0));
        return dp[usd][root] = ret;
    }
    int maxValue(TreeNode* root, int k) {
        kk = k;
        return dfs(root, 0);
    }
};