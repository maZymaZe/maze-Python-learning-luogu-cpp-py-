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
    int c[10] = {0}, cood = 0, ans = 0;
    void add(int x) {
        if (c[x] & 1)
            cood--;
        else
            cood++;
        c[x]++;
    }
    void dfs(TreeNode* rt) {
        if (!rt)
            return;
        add(rt->val);
        if (!rt->left && !rt->right) {
            if (cood < 2)
                ans++;
        }
        dfs(rt->left);
        dfs(rt->right);
        add(rt->val);
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};