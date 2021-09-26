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
    int p, q, ans;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->right);
        q++;
        if (q == p)
            ans = root->val;
        dfs(root->left);
    }
    int kthLargest(TreeNode* root, int k) {
        p = k, q = 0;
        dfs(root);
        return ans;
    }
};