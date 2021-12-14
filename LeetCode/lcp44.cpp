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
    set<int> s;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        s.insert(root->val);
        dfs(root->left), dfs(root->right);
    }
    int numColor(TreeNode* root) {
        dfs(root);
        return s.size();
    }
};