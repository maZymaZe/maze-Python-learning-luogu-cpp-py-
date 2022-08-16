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
    vector<int> ans;
    void dfs(TreeNode* root, int x) {
        if (!root)
            return;
        if (x == ans.size()) {
            ans.push_back(root->val);
        } else {
            ans[x] += root->val;
        }
        dfs(root->left, x + 1);
        dfs(root->right, x + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans.back();
    }
};