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
    void dfs(TreeNode* root, int f, vector<vector<int>>& ans) {
        if (root) {
            if (ans.size() <= f) {
                ans.push_back(vector<int>());
            }
            ans[f].push_back(root->val);
            dfs(root->left, f + 1, ans);
            dfs(root->right, f + 1, ans);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        int f = 0;
        for (auto& x : ans) {
            if (f)
                reverse(x.begin(), x.end());
            f ^= 1;
        }
        return ans;
    }
};