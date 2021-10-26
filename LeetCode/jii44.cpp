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
        if (ans.size() < x) {
            ans.push_back(root->val);
        } else {
            ans[x - 1] = max(ans[x - 1], root->val);
        }
        dfs(root->left, x + 1);
        dfs(root->right, x + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        ans.clear();
        dfs(root, 1);
        return ans;
    }
};