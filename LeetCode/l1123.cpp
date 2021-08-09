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
    unordered_map<TreeNode*, int> mp;
    TreeNode* ans;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int d = 1;
        if (root->left)
            d = max(dfs(root->left) + 1, d);
        if (root->right)
            d = max(dfs(root->right) + 1, d);
        mp[root] = d;
        return d;
    }
    void fa(TreeNode* root) {
        if (!root->left && !root->right) {
            ans = root;
        } else if (!root->right) {
            fa(root->left);
        } else if (root->left) {
            fa(root->right);
        }
        if (mp[root->left] == mp[root->right])
            ans = root;
        else if (mp[root->left] > mp[root->right])
            fa(root->left);
        else
            fa(root->right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root);
        ans = root;
        fa(root);
        return ans;
    }
};